#ifndef __MEMORYALLOCATOR_H
#define __MEMORYALLOCATOR_H

#include "MemoryManagement/MemoryBlock.h" // Assuming MemoryBlock.h is correctly located
#include <list>
#include <cstdint> // For uint32_t
#include <cstddef> // For size_t (though uint32_t is used in current functions)

class MemoryAllocator {
private:
    uint32_t totalMemory;
    std::list<MemoryBlock*> freeList;
    // It's good practice to make private helper functions if any complex logic is needed internally
    // e.g., for merging blocks, finding best fit, etc.

public:
    // Constructor
    MemoryAllocator(uint32_t totalMemory);

    // Destructor
    // If the MemoryAllocator manages the lifecycle of MemoryBlock objects (i.e., creates them),
    // it needs a destructor to clean them up to prevent memory leaks.
    ~MemoryAllocator();

    // Allocate a block of memory of the given size
    void* allocate(uint32_t size);

    // Free a previously allocated block of memory
    void free(void* ptr);

    // Get the total amount of free memory currently available
    uint32_t getFreeMemory() const;

    // Get the total memory managed by this allocator
    uint32_t getTotalMemory() const;

    // Add an externally created memory block to the allocator's list of free blocks
    // This implies that the MemoryAllocator does not own the MemoryBlock objects themselves,
    // but rather manages them.
    void addMemoryBlock(MemoryBlock* block);

    // It might be useful to have other functions, such as:
    // - Clearing all memory / resetting state
    // - Getting the number of free blocks
    // - Getting the largest available free block
    // - etc.
    // These are not in the original, so I will not add them.
};

#endif // __MEMORYALLOCATOR_H
