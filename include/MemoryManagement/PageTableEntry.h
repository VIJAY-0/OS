#ifndef __PAGETABLEENTRY_H
#define __PAGETABLEENTRY_H

#include <cstdint> // For uint32_t and uint8_t

// PageTableEntry class: Represents a single entry in a Page Table.
// It holds information about a virtual page, such as its corresponding
// physical frame number and access permissions.
class PageTableEntry {
private:
    uint32_t frameNumber;       // The physical frame number where the page is located.
    bool valid;                 // Valid bit: true if the page is in physical memory, false otherwise.
    uint8_t accessPermission;   // Access permissions for the page (e.g., read, write, execute bits).

public:
    // Default Constructor: Initializes a page table entry.
    // By default, sets frameNumber to 0, valid to false (not present),
    // and accessPermission to 0 (no permissions).
    PageTableEntry();

    // --- Getters ---

    // Returns the physical frame number associated with this page entry.
    uint32_t getFrameNumber() const;

    // Returns true if the page is marked as valid (present in physical memory), false otherwise.
    bool isValid() const;

    // Returns the access permission flags for this page.
    // The interpretation of these flags (e.g., bit positions for read/write/execute)
    // depends on the system's memory management unit (MMU) design.
    uint8_t getAccessPermission() const;

    // --- Setters ---

    // Sets the physical frame number for this page entry.
    void setFrameNumber(uint32_t frame);

    // Sets the valid bit for this page entry.
    void setValid(bool validFlag);

    // Sets the access permission flags for this page entry.
    void setAccessPermission(uint8_t permission);
};

#endif // __PAGETABLEENTRY_H
