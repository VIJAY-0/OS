// VirtualMemory.cpp
// Implementations for VirtualMemory class

#include "MemoryManagement/VirtualMemory.h"
#include "MemoryManagement/PageTable.h" // Included by VirtualMemory.h, but good for clarity
#include <cstdlib> // For malloc, free
#include <stdexcept> // For std::out_of_range

// Constructor
VirtualMemory::VirtualMemory(uint32_t numPages, uint32_t pageSize)
    : pageSize(pageSize), totalPages(numPages) {
    // Initialize the pageTables vector with one PageTable.
    // The PageTable is created with 'numPages' entries.
    if (numPages > 0) { // Avoid creating a PageTable if numPages is 0, though PageTable itself might handle that.
        pageTables.push_back(new PageTable(numPages));
    }
    // If there's a scenario for multiple page tables (e.g., per process),
    // this constructor might need to be different, or methods to add/manage them.
    // For now, it creates one based on totalPages.
}

// Destructor
VirtualMemory::~VirtualMemory() {
    // Clean up the PageTable objects allocated in the constructor.
    for (PageTable* pt : pageTables) {
        delete pt;
    }
    pageTables.clear(); // Clear the vector of pointers.
}

// Allocate a "virtual page"
// In the current header implementation, this is a simplified allocation
// that doesn't deeply involve page table mapping for actual virtual memory simulation.
// It just returns a block of memory of 'pageSize'.
void* VirtualMemory::allocatePage() {
    // This simplistic version directly allocates memory.
    // A more realistic virtual memory system would find a virtual page,
    // then later map it to a physical frame (perhaps on page fault).
    void* newPage = malloc(pageSize);
    if (!newPage) {
        // Handle allocation failure, e.g., throw std::bad_alloc
        throw std::bad_alloc();
    }
    // Further logic could involve marking a virtual page as allocated in some structure,
    // but the current header doesn't specify such a structure beyond the PageTable.
    return newPage;
}

// Free a "virtual page"
void VirtualMemory::freePage(void* ptr) {
    if (ptr) {
        free(ptr);
    }
    // Similar to allocatePage, a more realistic system would update virtual address space metadata.
}

// Get a specific page table
PageTable* VirtualMemory::getPageTable(uint32_t tableIndex) {
    if (tableIndex >= pageTables.size()) {
        // Handle error: index out of bounds
        throw std::out_of_range("VirtualMemory::getPageTable: tableIndex out of bounds");
    }
    return pageTables[tableIndex];
}

// It might be useful to have access to pageSize and totalPages,
// so getters for those could be added if needed, though not in original header.
// uint32_t VirtualMemory::getPageSize() const { return pageSize; }
// uint32_t VirtualMemory::getTotalPages() const { return totalPages; }

// The include path for VirtualMemory.h assumes the build system is configured
// to find headers in the 'include' directory.
