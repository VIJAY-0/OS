#ifndef __PAGETABLE_H
#define __PAGETABLE_H

#include "MemoryManagement/PageTableEntry.h"
#include <vector>

class PageTable {
private:
    std::vector<PageTableEntry> entries;

public:
    PageTable(uint32_t numEntries) : entries(numEntries) {}

    PageTableEntry getEntry(uint32_t index) const {
        return entries[index];
    }

    void setEntry(uint32_t index, const PageTableEntry& entry) {
        entries[index] = entry;
    }

    uint32_t getPageSize() const {
        return sizeof(PageTableEntry);
    }
};

#endif
