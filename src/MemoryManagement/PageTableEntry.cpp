// PageTableEntry.cpp
// Implementations for PageTableEntry class

#include "MemoryManagement/PageTableEntry.h"

// Default constructor
PageTableEntry::PageTableEntry() : frameNumber(0), valid(false), accessPermission(0) {
    // Initialization is done in the member initializer list as per the header.
    // No further implementation needed in the body.
}

// --- Getters ---
uint32_t PageTableEntry::getFrameNumber() const {
    return frameNumber;
}

bool PageTableEntry::isValid() const {
    return valid;
}

uint8_t PageTableEntry::getAccessPermission() const {
    return accessPermission;
}

// --- Setters ---
void PageTableEntry::setFrameNumber(uint32_t frame) {
    frameNumber = frame;
}

void PageTableEntry::setValid(bool validFlag) {
    valid = validFlag;
}

void PageTableEntry::setAccessPermission(uint8_t permission) {
    accessPermission = permission;
}

// Note on include paths:
// As with other .cpp files in this directory, the include statement
// #include "MemoryManagement/PageTableEntry.h"
// assumes that the build system is configured to find headers
// in the 'include' directory (e.g., via -I ../../include or -I include).
