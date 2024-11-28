#ifndef __MEMORYMANAGER_H
#define __MEMORYMANAGER_H

#include "MemoryManagement/MemoryAllocator.h"
#include "MemoryManagement/PageTable.h"
#include "MemoryManagement/VirtualMemory.h"

class MemoryManager {
private:
    MemoryAllocator* allocator;
    PageTable* pageTable;
    VirtualMemory* virtualMemory;

public:
    MemoryManager(MemoryAllocator* allocator, PageTable* pageTable, VirtualMemory* virtualMemory) 
        : allocator(allocator), pageTable(pageTable), virtualMemory(virtualMemory) {}

    void initializeAllocator() {
        // Initialize memory allocator with specific total memory size
    }

    void* allocateMemory(uint32_t size) {
        return allocator->allocate(size);
    }

    void freeMemory(void* ptr) {
        allocator->free(ptr);
    }

    uint32_t getTotalMemory() const {
        return allocator->getTotalMemory();
    }

    uint32_t getFreeMemory() const {
        return allocator->getFreeMemory();
    }

    PageTable* getPageTable() const {
        return pageTable;
    }

    VirtualMemory* getVirtualMemory() const {
        return virtualMemory;
    }
};

#endif
