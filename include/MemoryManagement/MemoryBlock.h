#ifndef __MEMORYBLOCK_H
#define __MEMORYBLOCK_H

#include <cstdint>

class MemoryBlock {
private:
    uint32_t size;
    void* startAddress;
    bool isAllocate;

public:
    MemoryBlock(uint32_t size, void* startAddress)
        : size(size), startAddress(startAddress), isAllocate(false) {}

    uint32_t getSize() const {
        return size;
    }

    void* getStartAddress() const {
        return startAddress;
    }

    bool isAllocated() const {
        return isAllocate;
    }

    void allocate() {
        isAllocate = true;
    }

    void free() {
        isAllocate = false;
    }
};

#endif
