# My Basic Kernel

This is a basic kernel created to understand OS implementation details, starting from the boot sector, real mode, protected mode, GDT, IDT, etc.

## Boot Process

The boot process begins when the computer is powered on. The BIOS (Basic Input/Output System) performs a Power-On Self Test (POST) and then searches for a bootable device. Once a bootable device is found, the BIOS loads the first 512 bytes (the Master Boot Record or MBR) into memory at address `0x7c00`.

Our bootloader, `loader.s`, resides in the MBR. Its primary responsibilities are:
1.  **Initialize the system:** This includes setting up the stack and preparing the system for the transition to protected mode.
2.  **Transition to Protected Mode:** Real mode has limitations (e.g., 1MB addressable memory). Protected mode allows access to more memory and offers features like memory protection. `loader.s` handles this transition by:
    *   Enabling the A20 line.
    *   Loading the Global Descriptor Table (GDT) using the `lgdt` instruction. The GDT defines memory segments and their access privileges.
    *   Setting the PE (Protection Enable) bit in the CR0 control register.
3.  **Call `kernelMain`:** After successfully transitioning to protected mode, the bootloader jumps to the `kernelMain` function, which is the entry point of our C kernel.

## Kernel Components and Functionalities

Once `kernelMain` is called, the kernel takes control and starts setting up its core components and functionalities.

### Global Descriptor Table (GDT)
The GDT is already loaded by the bootloader (`loader.s`) before jumping to `kernelMain`. It defines the segments of memory the CPU can access. Our GDT defines segments for kernel code and data.

### Interrupt Descriptor Table (IDT)
The IDT is a data structure used by the processor to determine the correct response to interrupts and exceptions. The kernel sets up the IDT to handle hardware interrupts (like keyboard, mouse, timer) and software exceptions. Each entry in the IDT (called a gate) points to an Interrupt Service Routine (ISR) or an exception handler.

Key steps in IDT setup:
1.  **Define ISRs/Exception Handlers:** These are functions that will be executed when a specific interrupt or exception occurs.
2.  **Populate IDT Entries:** Each interrupt/exception is assigned a vector number (0-255). The kernel creates IDT entries (gates) for each relevant vector, pointing to the corresponding ISR or handler.
3.  **Load IDT Register (IDTR):** The `lidt` instruction is used to load the base address and limit of the IDT into the IDTR.

### Interrupt Handling
When an interrupt occurs:
1.  The CPU saves the current execution context (registers, instruction pointer).
2.  It uses the interrupt vector number to look up the corresponding gate in the IDT.
3.  It jumps to the ISR specified in the IDT gate.
4.  The ISR handles the interrupt (e.g., reads data from the keyboard controller).
5.  The ISR sends an End of Interrupt (EOI) signal to the Programmable Interrupt Controller (PIC) to acknowledge the interrupt.
6.  The ISR executes an `iret` (interrupt return) instruction to restore the saved context and resume the interrupted task.

### Keyboard and Mouse Drivers
Basic drivers are implemented to handle input from the PS/2 keyboard and mouse.
*   **Keyboard Driver:** Initializes the keyboard controller and handles scan codes received from the keyboard. It translates these scan codes into ASCII characters.
*   **Mouse Driver:** Initializes the PS/2 mouse and handles data packets received from it, allowing for tracking mouse movement and button presses.

### Memory Management (Basic)
Currently, memory management is very basic. The kernel operates with the memory layout established by the bootloader. Future plans include implementing paging and a more sophisticated memory allocator.

### Process Scheduling (Placeholder)
Process scheduling is not yet implemented. The kernel currently runs in a single thread of execution. Future plans include implementing a preemptive multitasking scheduler.

## Project Structure

The project is organized as follows:

```
.
├── include/        # Header files
│   ├── keyboard.h
│   └── mouse.h
├── src/            # Source files
│   ├── kernel/       # Kernel C code
│   │   ├── kernel.c
│   │   ├── keyboard.c
│   │   └── mouse.c
│   └── boot/         # Bootloader assembly code
│       └── loader.s
├── obj/            # Object files (created during build)
├── Makefile        # Build script for automating compilation and linking
├── README.md       # This file
└── os.img          # Final bootable disk image (created after build)
```

*   **`include/`**: Contains header files (`.h`) for the C kernel code. These files define function prototypes, data structures, and macros used across different parts of the kernel.
    *   `keyboard.h`: Declarations for keyboard driver functions and definitions.
    *   `mouse.h`: Declarations for mouse driver functions and definitions.
*   **`src/`**: Contains the source code.
    *   **`src/kernel/`**: Houses the C source files for the kernel itself.
        *   `kernel.c`: The main kernel entry point (`kernelMain`) and core kernel logic.
        *   `keyboard.c`: Implementation of the keyboard driver.
        *   `mouse.c`: Implementation of the mouse driver.
    *   **`src/boot/`**: Contains the assembly code for the bootloader.
        *   `loader.s`: The bootloader responsible for initializing the system, transitioning to protected mode, and loading the kernel.
*   **`obj/`**: This directory stores intermediate object files (`.o`) generated by the assembler and compiler during the build process. It is typically created by the `Makefile`.
*   **`Makefile`**: The `Makefile` contains instructions for building the entire project. It defines rules for compiling source files, linking them, and creating the final bootable disk image (`os.img`).
*   **`README.md`**: This file, providing information about the project.
*   **`os.img`**: The final bootable disk image generated by the build process. This is the file you run with an emulator like QEMU.

## Future Improvements

This basic kernel is a starting point for learning and experimentation. There are many potential areas for future development and improvement, including:

*   **Advanced Memory Management:**
    *   Implement paging to enable virtual memory.
    *   Develop a more sophisticated dynamic memory allocator (e.g., `kmalloc`, `kfree`).
*   **Process Scheduling:**
    *   Implement a preemptive multitasking scheduler.
    *   Introduce concepts of processes and threads.
*   **File System:**
    *   Design and implement a simple file system (e.g., a basic FAT-like system or a custom one).
    *   Add support for reading from and writing to storage devices.
*   **More Drivers:**
    *   **Timer Driver:** A more precise timer interrupt for scheduling and other time-sensitive operations.
    *   **Serial Port Driver:** For communication with the host or other devices.
    *   **Basic Graphics Driver:** To enable simple graphics modes (e.g., VGA text mode extensions or basic pixel plotting).
*   **System Calls:**
    *   Develop a system call interface to allow user-mode programs (once supported) to request services from the kernel.
*   **User Mode:**
    *   Implement mechanisms to switch to user mode and run user-level applications.
*   **Shell/Command Line Interface:**
    *   Create a simple shell to interact with the kernel.
*   **Networking Stack (Ambitious):**
    *   Implement a basic networking stack (e.g., IP, TCP/UDP).

These are just some ideas, and the direction of future development can be adapted based on learning goals.

## Build and Run Instructions

### Prerequisites
Before you can build and run the kernel, you'll need the following dependencies:
*   **NASM Assembler:** Used for assembling the bootloader (`loader.s`).
*   **GCC Cross-Compiler:** A GCC toolchain that can compile C code for the target architecture (e.g., `i686-elf-gcc`).
*   **QEMU Emulator:** For running the kernel.
*   **Make:** To automate the build process using the provided `makefile`.

You can typically install these using your system's package manager. For example, on a Debian-based Linux distribution:
```bash
sudo apt-get update
sudo apt-get install nasm build-essential qemu-system-x86
# For the cross-compiler, you might need to build it from source or find a pre-built one.
# Search for 'i686-elf-gcc' or similar for your system.
```

### Building the Kernel
The provided `makefile` automates the build process.
1.  **Navigate to the project root directory.**
2.  **Run Make:**
    ```bash
    make
    ```
    This command will:
    *   Assemble the bootloader (`loader.s`) into a binary object file.
    *   Compile the C kernel code (e.g., `kernel.c`, `keyboard.c`) into object files using the cross-compiler.
    *   Link the bootloader object file and kernel object files together to create the final linked kernel image (often named `kernel.bin`).
    *   Concatenate the bootloader (typically the first 512 bytes) and the linked kernel image to create the final bootable disk image (`os.img`).

### Running the Kernel
Once the kernel is successfully built (producing `os.img`), you can run it using QEMU:
```bash
qemu-system-i386 -fda os.img
```
This command tells QEMU to use `os.img` as the floppy disk image (drive A) and boot from it.

## Usage

Currently, the kernel boots, initializes basic hardware (keyboard, mouse if enabled and compiled), and may display output to the screen (e.g., characters typed on the keyboard). Direct user interaction is limited until a shell or command-line interface is implemented (see Future Improvements).

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these general steps:

1.  **Fork the repository.**
2.  **Create a new branch** for your feature, bug fix, or improvement (e.g., `git checkout -b feature/my-new-feature` or `git checkout -b fix/issue-tracker-bug`).
3.  **Make your changes.** Ensure your code adheres to the existing style if one is apparent.
4.  **Test your changes thoroughly.**
5.  **Commit your changes** with a clear and descriptive commit message.
6.  **Push your branch** to your forked repository.
7.  **Submit a pull request** to the main repository, detailing the changes you've made.

Please ensure that your contributions are your own original work or that you have the necessary rights to contribute them.
