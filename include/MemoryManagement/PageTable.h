#ifndef __PAGETABLE_H
#define __PAGETABLE_H

#include "MemoryManagement/PageTableEntry.h" // Definition of PageTableEntry is required
#include <vector>   // For std::vector
#include <cstdint>  // For uint32_t

// PageTable class: Represents a table of page entries used in virtual memory systems
// to map virtual pages to physical frames.
class PageTable {
private:
    std::vector<PageTableEntry> entries; // The collection of page table entries

public:
    // Constructor: Initializes the page table with a specific number of entries.
    // Each entry is default-constructed.
    explicit PageTable(uint32_t numEntries); // Mark single-argument constructors explicit

    // Retrieves a copy of the page table entry at the given index.
    // Throws std::out_of_range if the index is invalid.
    PageTableEntry getEntry(uint32_t index) const;

    // Sets the page table entry at the given index with a copy of the provided entry.
    // Throws std::out_of_range if the index is invalid.
    void setEntry(uint32_t index, const PageTableEntry& entry);

    // Returns the size of an individual PageTableEntry structure.
    // Note: This is not the memory page size (e.g., 4KB) but the size of the entry itself.
    uint32_t getPageSize() const;

    // It might be useful to have a method to get the number of entries:
    // uint32_t getNumEntries() const { return entries.size(); }
    // This was not in the original header, so it's commented out.

    // Destructor: Default destructor is sufficient as std::vector manages its own memory.
    // ~PageTable();
};

#endif // __PAGETABLE_H
