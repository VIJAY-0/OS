#ifndef __MEMORYBLOCK_H
#define __MEMORYBLOCK_H

#include <cstdint> // For uint32_t
#include <cstddef> // For void* (though not strictly required for void*)

class MemoryBlock {
private:
    uint32_t size;
    void* startAddress; // Represents the starting memory address of the block
    bool isAllocate;    // Status flag: true if allocated, false if free

public:
    // Constructor: Initializes a memory block with a given size and start address.
    // Initially, the block is marked as not allocated.
    MemoryBlock(uint32_t size, void* startAddress);

    // Returns the size of the memory block in bytes.
    uint32_t getSize() const;

    // Returns the starting memory address of the block.
    void* getStartAddress() const;

    // Returns true if the block is currently allocated, false otherwise.
    bool isAllocated() const;

    // Marks the block as allocated.
    void allocate();

    // Marks the block as free.
    void free();

    // Optional: Add a destructor if MemoryBlock were to manage resources
    // that need explicit cleanup (e.g., if startAddress was owned and allocated by this class).
    // ~MemoryBlock();
};

#endif // __MEMORYBLOCK_H
