#ifndef __MEMORYALLOCATOR_H
#define __MEMORYALLOCATOR_H

#include "MemoryManagement/MemoryBlock.h"
#include <list>

class MemoryAllocator {
private:
    uint32_t totalMemory;
    std::list<MemoryBlock*> freeList;

public:
    MemoryAllocator(uint32_t totalMemory) : totalMemory(totalMemory) {}

    void* allocate(uint32_t size) {
        for (auto it = freeList.begin(); it != freeList.end(); ++it) {
            if ((*it)->getSize() >= size && !(*it)->isAllocated()) {
                (*it)->allocate();
                return (*it)->getStartAddress();
            }
        }
        return nullptr;
    }

    void free(void* ptr) {
        for (auto it = freeList.begin(); it != freeList.end(); ++it) {
            if ((*it)->getStartAddress() == ptr) {
                (*it)->free();
                return;
            }
        }
    }

    uint32_t getFreeMemory() const {
        uint32_t freeMem = 0;
        for (auto block : freeList) {
            if (!(block->isAllocated())) {
                freeMem += block->getSize();
            }
        }
        return freeMem;
    }

    uint32_t getTotalMemory() const {
        return totalMemory;
    }

    void addMemoryBlock(MemoryBlock* block) {
        freeList.push_back(block);
    }
};

#endif
