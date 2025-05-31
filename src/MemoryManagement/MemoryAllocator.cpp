// MemoryAllocator.cpp
#include "MemoryManagement/MemoryAllocator.h" // Should be "MemoryAllocator.h" if it's in the same directory or configured in include paths
#include <cstdlib> // For malloc, free (though not directly used in the provided header)
#include <stdexcept> // For std::bad_alloc (not used in the provided header, but good for memory allocation)

// Constructor
MemoryAllocator::MemoryAllocator(uint32_t totalMemory) : totalMemory(totalMemory) {
    // The constructor body is empty in the header, so it remains empty here.
    // If there was logic, it would be moved here.
}

// Destructor
MemoryAllocator::~MemoryAllocator() {
    // The provided header does not have an explicit destructor.
    // If MemoryBlocks are dynamically allocated by MemoryAllocator itself (not just pointers added),
    // they should be deleted here.
    // For now, assuming MemoryBlocks are managed externally or are stack-allocated/global.
    // Example:
    // for (MemoryBlock* block : freeList) {
    //     delete block; // If MemoryAllocator owns these blocks
    // }
    // freeList.clear();
}

// Allocate memory
void* MemoryAllocator::allocate(uint32_t size) {
    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
        if ((*it)->getSize() >= size && !(*it)->isAllocated()) {
            (*it)->allocate();
            return (*it)->getStartAddress();
        }
    }
    return nullptr; // Indicates allocation failure
}

// Deallocate memory
void MemoryAllocator::free(void* ptr) {
    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
        if ((*it)->getStartAddress() == ptr) {
            (*it)->free();
            // Consider merging free blocks here if applicable
            return;
        }
    }
    // Optionally, handle cases where ptr is not found or already free,
    // though the original header doesn't specify this.
}

// Get total free memory
uint32_t MemoryAllocator::getFreeMemory() const {
    uint32_t freeMem = 0;
    for (const MemoryBlock* block : freeList) { // Added const for const correctness
        if (!(block->isAllocated())) {
            freeMem += block->getSize();
        }
    }
    return freeMem;
}

// Get total memory
uint32_t MemoryAllocator::getTotalMemory() const {
    return totalMemory;
}

// Add a memory block to the allocator
void MemoryAllocator::addMemoryBlock(MemoryBlock* block) {
    // It's generally a good idea to check if the block is valid
    if (block) {
        freeList.push_back(block);
        // Potentially sort or merge blocks here depending on allocation strategy
    }
}

// Note: The original header used std::list<MemoryBlock*>.
// If MemoryAllocator is responsible for creating and destroying these MemoryBlock objects,
// then the destructor ~MemoryAllocator() should iterate through freeList and delete each MemoryBlock.
// If MemoryBlock objects are managed externally (e.g., passed in and guaranteed to exist for the
// lifetime of MemoryAllocator), then the current destructor (or lack thereof an explicit one in .h) is fine.
// The include path for MemoryAllocator.h in this .cpp file might need adjustment
// depending on the project structure and include paths configuration.
// If MemoryAllocator.h is in `include/MemoryManagement/MemoryAllocator.h`
// and this .cpp is in `src/MemoryManagement/MemoryAllocator.cpp`,
// then the include path should be `#include "MemoryManagement/MemoryAllocator.h"`
// or the compiler needs to be told where to find headers (e.g. -I ../include)
// For now, I'll assume the include path will be resolved by the build system.
// Corrected include statement:
// #include "MemoryManagement/MemoryAllocator.h"
// This was already present, but if MemoryAllocator.h is in `include/` and this file is in `src/`,
// the build system needs to be configured with an include path like `-I../include`.
// For now, I'll use the relative path from `src` to `include`.
// This should be: #include "../../include/MemoryManagement/MemoryAllocator.h" if we are in src/MemoryManagement
// Or more commonly: #include "MemoryManagement/MemoryAllocator.h" and the compiler is given -I ../../include (from src/MemoryManagement) or -I include (if CWD is project root)

// Let's assume the common practice where include paths are set up by the build system.
// So, `#include "MemoryManagement/MemoryAllocator.h"` is standard.
// The initial placeholder included this already.

// No changes needed to the #include line from the placeholder if the build system is set up correctly.
// The primary task is to move the implementation logic.
// The placeholder already had function signatures. I'm filling them in.
