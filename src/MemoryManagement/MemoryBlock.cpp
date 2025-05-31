// MemoryBlock.cpp
// Implementations for MemoryBlock class

#include "MemoryManagement/MemoryBlock.h" // Assuming this path will be resolved by the build system
                                        // Or #include "../../include/MemoryManagement/MemoryBlock.h"
                                        // Or similar, depending on actual structure and include paths.
                                        // For now, keeping it generic.

// Constructor
MemoryBlock::MemoryBlock(uint32_t size, void* startAddress)
    : size(size), startAddress(startAddress), isAllocate(false) {
    // Constructor body was empty in the header, so it remains empty here.
}

// Getters
uint32_t MemoryBlock::getSize() const {
    return size;
}

void* MemoryBlock::getStartAddress() const {
    return startAddress;
}

bool MemoryBlock::isAllocated() const {
    return isAllocate;
}

// Setters / Modifiers
void MemoryBlock::allocate() {
    isAllocate = true;
}

void MemoryBlock::free() {
    isAllocate = false;
}

// Note: The include path for MemoryBlock.h in this .cpp file might need adjustment
// depending on the project structure and include paths configuration.
// If MemoryBlock.h is in `include/MemoryManagement/MemoryBlock.h`
// and this .cpp is in `src/MemoryManagement/MemoryBlock.cpp`,
// then the include path should be `#include "MemoryManagement/MemoryBlock.h"`
// and the compiler needs to be told where to find headers (e.g. -I ../../include if compiling from src/MemoryManagement, or -I include if from project root).
// The placeholder for MemoryAllocator.cpp noted this, and it applies here too.
// I will assume the build system handles this via include path settings.
