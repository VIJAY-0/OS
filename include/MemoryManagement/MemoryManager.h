#ifndef __MEMORYMANAGER_H
#define __MEMORYMANAGER_H

#include <cstdint> // For uint32_t

// Forward declarations to avoid circular dependencies if these headers also include MemoryManager.h
// However, given these are components OF MemoryManager, it's more likely MemoryManager.h includes them directly.
// If PageTable or VirtualMemory were to use MemoryManager, then forward declaration would be key.
class MemoryAllocator;
class PageTable;
class VirtualMemory;

// MemoryManager class: Orchestrates memory operations using an allocator,
// page table, and virtual memory system.
class MemoryManager {
private:
    MemoryAllocator* allocator;     // Pointer to a MemoryAllocator object
    PageTable* pageTable;           // Pointer to a PageTable object
    VirtualMemory* virtualMemory;   // Pointer to a VirtualMemory object

public:
    // Constructor: Initializes the MemoryManager with existing allocator, page table, and virtual memory components.
    // Note: This constructor implies that the MemoryManager does not own these components,
    // and their lifecycle is managed externally.
    MemoryManager(MemoryAllocator* allocator, PageTable* pageTable, VirtualMemory* virtualMemory);

    // Destructor: Cleans up resources if necessary.
    // Given the constructor, this would typically be empty unless the MemoryManager
    // acquires other resources during its lifetime.
    ~MemoryManager();

    // Initializes the memory allocator. The specific logic for initialization
    // (e.g., setting total memory size) would be in the implementation or
    // within the MemoryAllocator itself. The current implementation is empty.
    void initializeAllocator();

    // Allocates a block of memory of the specified size using the associated MemoryAllocator.
    // Returns a pointer to the allocated memory, or nullptr if allocation fails.
    void* allocateMemory(uint32_t size);

    // Frees a previously allocated block of memory using the associated MemoryAllocator.
    void freeMemory(void* ptr);

    // Returns the total memory managed by the allocator.
    uint32_t getTotalMemory() const;

    // Returns the total free memory currently available in the allocator.
    uint32_t getFreeMemory() const;

    // Returns a pointer to the PageTable object.
    PageTable* getPageTable() const;

    // Returns a pointer to the VirtualMemory object.
    VirtualMemory* getVirtualMemory() const;

    // Note: If MemoryManager were to be responsible for creating/destroying its components,
    // the constructor would likely take configuration parameters (e.g., total memory size)
    // and instantiate MemoryAllocator, PageTable, VirtualMemory internally.
    // The destructor would then be responsible for deleting these owned objects.
};

#endif // __MEMORYMANAGER_H
