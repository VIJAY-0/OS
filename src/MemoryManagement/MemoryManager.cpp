// MemoryManager.cpp
// Implementations for MemoryManager class

#include "MemoryManagement/MemoryManager.h"
// Other necessary includes might be MemoryAllocator.h, PageTable.h, VirtualMemory.h,
// but they are already included by MemoryManager.h.

// Constructor
MemoryManager::MemoryManager(MemoryAllocator* allocator, PageTable* pageTable, VirtualMemory* virtualMemory)
    : allocator(allocator), pageTable(pageTable), virtualMemory(virtualMemory) {
    // The constructor body is empty in the header, so it remains empty here.
    // It correctly initializes the members with the provided pointers.
}

// Destructor
// No explicit destructor was defined in the header.
// This implies MemoryManager does not own the objects pointed to by allocator, pageTable, and virtualMemory.
// If it did own them, a destructor would be needed:
// MemoryManager::~MemoryManager() {
//     delete allocator;
//     delete pageTable;
//     delete virtualMemory;
// }
// For now, assuming non-owning pointers as per the header's structure.
MemoryManager::~MemoryManager() {
    // If the manager is responsible for cleaning up these components,
    // delete them here. However, the header doesn't suggest ownership.
    // If they are managed externally, this destructor can be empty or omitted
    // (the compiler will generate a default one).
}

void MemoryManager::initializeAllocator() {
    // Initialize memory allocator with specific total memory size
    // The header provides an empty implementation.
    // This method's purpose is a bit unclear without further context.
    // It might be intended to call a method on the allocator, e.g.:
    // if (allocator) {
    //     allocator->initialize(); // Assuming MemoryAllocator has such a method
    // }
    // Or it might have been a placeholder for future logic.
    // For now, keeping it empty as per the header.
}

void* MemoryManager::allocateMemory(uint32_t size) {
    if (!allocator) {
        // Handle error: allocator not set
        // This could throw an exception or return nullptr
        // For example: throw std::runtime_error("MemoryAllocator not initialized");
        return nullptr;
    }
    return allocator->allocate(size);
}

void MemoryManager::freeMemory(void* ptr) {
    if (!allocator) {
        // Handle error: allocator not set
        // For example: throw std::runtime_error("MemoryAllocator not initialized");
        return;
    }
    allocator->free(ptr);
}

uint32_t MemoryManager::getTotalMemory() const {
    if (!allocator) {
        // Handle error or return a sensible default
        return 0;
    }
    return allocator->getTotalMemory();
}

uint32_t MemoryManager::getFreeMemory() const {
    if (!allocator) {
        // Handle error or return a sensible default
        return 0;
    }
    return allocator->getFreeMemory();
}

PageTable* MemoryManager::getPageTable() const {
    return pageTable;
}

VirtualMemory* MemoryManager::getVirtualMemory() const {
    return virtualMemory;
}

// Note on include paths:
// As with other .cpp files in this directory, the include statement
// #include "MemoryManagement/MemoryManager.h"
// assumes that the build system is configured to find headers
// in the `include` directory (e.g., via -I ../../include if compiling from src/MemoryManagement,
// or -I include if compiling from the project root).
