// PageTable.cpp
// Implementations for PageTable class

#include "MemoryManagement/PageTable.h"
#include <stdexcept> // For std::out_of_range if bounds checking is desired

// Constructor
PageTable::PageTable(uint32_t numEntries) : entries(numEntries) {
    // The vector 'entries' is initialized with 'numEntries' default-constructed PageTableEntry objects.
    // If PageTableEntry needs specific initialization beyond its default constructor,
    // that would be done here in a loop, or PageTableEntry itself should handle it.
}

// Get page table entry by index
PageTableEntry PageTable::getEntry(uint32_t index) const {
    if (index >= entries.size()) {
        // Handle error: index out of bounds.
        // Throwing an exception is a common way to handle this.
        throw std::out_of_range("PageTable::getEntry: index out of bounds");
    }
    return entries[index];
}

// Set page table entry by index
void PageTable::setEntry(uint32_t index, const PageTableEntry& entry) {
    if (index >= entries.size()) {
        // Handle error: index out of bounds.
        throw std::out_of_range("PageTable::setEntry: index out of bounds");
    }
    entries[index] = entry;
}

// Get the "page size" - in this context, it's the size of a PageTableEntry struct.
// This is an unusual interpretation of "page size".
// Typically, page size refers to the memory page size (e.g., 4KB).
uint32_t PageTable::getPageSize() const {
    // This implementation matches the header.
    // If the intent was the number of entries, it would be entries.size().
    // If the intent was memory page size (e.g., 4096 bytes), this class would need that info.
    return sizeof(PageTableEntry);
}

// To implement functionality similar to the placeholder's mapPage,
// one would typically do something like this outside or as a helper method within PageTable:
// void PageTable::mapPage_conceptual(uint32_t pageNumber, uint32_t frameNumber, bool present, bool readWrite) {
//     if (pageNumber >= entries.size()) {
//         throw std::out_of_range("mapPage_conceptual: pageNumber out of bounds");
//     }
//     PageTableEntry newEntry; // Assuming PageTableEntry has a default constructor
//     newEntry.setFrameNumber(frameNumber); // Assuming PageTableEntry has these methods
//     newEntry.setPresent(present);
//     newEntry.setReadWrite(readWrite);
//     // ... set other flags ...
//     entries[pageNumber] = newEntry;
// }
// This depends heavily on the definition of PageTableEntry.

// The include path for PageTable.h assumes the build system is configured
// to find headers in the 'include' directory (e.g., -I ../../include or -I include).
