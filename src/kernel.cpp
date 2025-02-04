#include <common/types.h>
#include <hardware communication/gdt.h>
#include <hardware communication/interrupts.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <drivers/driver.h>


// kermel main


void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}



extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("hello .....\n");
    GlobalDescriptorTable gdt;
    printf("GDT Loaded...\n");

    InterruptManager interrupts(0x20, &gdt);
    printf("IDTM instanstiated...\n");


    DriverManager drvManager;
    
        KeyboardDriver keyboard(&interrupts);
        printf("KeyBoard Driver instanstiated\n");
        drvManager.AddDriver(&keyboard);
        
        MouseDriver mouse(&interrupts);
        drvManager.AddDriver(&mouse);
        printf("Mouse Driver instanstiated\n");

        drvManager.ActivateAll();


    interrupts.Activate();
    
    printf("Interrupts Started\n");
    while(1);
}
