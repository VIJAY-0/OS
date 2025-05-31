#ifndef __VIRTUALMEMORY_H
#define __VIRTUALMEMORY_H

#include <vector>
#include <cstdint> // For uint32_t

// Forward declaration
class PageTable;

// VirtualMemory class: Manages a virtual address space.
// This version is simplified: it creates and owns a PageTable,
// and provides high-level page allocation/deallocation (currently via malloc/free).
class VirtualMemory {
private:
    std::vector<PageTable*> pageTables; // A list of page tables managed by this VM system.
                                        // The current constructor creates one.
    uint32_t pageSize;                  // Size of a single page in bytes.
    uint32_t totalPages;                // Total number of pages in the virtual address space
                                        // (used to size the initial PageTable).

public:
    // Constructor: Initializes the virtual memory system.
    // Creates a PageTable with 'numPages' entries.
    // 'numPages' refers to the total number of virtual pages.
    // 'pageSize' is the size of each page.
    VirtualMemory(uint32_t numPages, uint32_t pageSize);

    // Destructor: Cleans up resources, particularly the PageTable objects
    // allocated by this VirtualMemory instance.
    ~VirtualMemory();

    // Allocates a block of memory of 'pageSize'.
    // In this simplified version, it uses `malloc`. A more complex system would
    // manage virtual page descriptors and coordinate with the PageTable for mapping.
    void* allocatePage();

    // Frees a block of memory previously allocated by `allocatePage`.
    // Uses `free` in this simplified version.
    void freePage(void* ptr);

    // Retrieves a pointer to a PageTable managed by this VirtualMemory system.
    // 'tableIndex' specifies which PageTable to retrieve if multiple are managed.
    // Throws std::out_of_range if tableIndex is invalid.
    PageTable* getPageTable(uint32_t tableIndex);

    // Consider adding getters for pageSize and totalPages if external query is needed.
    // uint32_t getPageSize() const;
    // uint32_t getTotalPages() const;
};

#endif // __VIRTUALMEMORY_H
