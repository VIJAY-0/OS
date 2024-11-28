#ifndef __VIRTUALMEMORY_H
#define __VIRTUALMEMORY_H

#include "MemoryManagement/PageTable.h"
#include <vector>
#include<memory>

class VirtualMemory {
private:
    std::vector<PageTable*> pageTables;
    uint32_t pageSize;
    uint32_t totalPages;

public:
    VirtualMemory(uint32_t numPages, uint32_t pageSize) 
        : pageSize(pageSize), totalPages(numPages) {
        pageTables.push_back(new PageTable(numPages));
    }

    void* allocatePage() {
        // Simple allocation of a virtual page, could use page table for mapping
        return malloc(pageSize);
    }

    void freePage(void* ptr) {
        free(ptr);
    }

    PageTable* getPageTable(uint32_t tableIndex) {
        return pageTables[tableIndex];
    }
};

#endif
