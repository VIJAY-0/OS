#ifndef __PAGETABLEENTRY_H
#define __PAGETABLEENTRY_H

#include <cstdint>

class PageTableEntry {
private:
    uint32_t frameNumber;
    bool valid;
    uint8_t accessPermission;

public:
    PageTableEntry() : frameNumber(0), valid(false), accessPermission(0) {}

    uint32_t getFrameNumber() const {
        return frameNumber;
    }

    void setFrameNumber(uint32_t frame) {
        frameNumber = frame;
    }

    bool isValid() const {
        return valid;
    }

    void setValid(bool validFlag) {
        valid = validFlag;
    }

    uint8_t getAccessPermission() const {
        return accessPermission;
    }

    void setAccessPermission(uint8_t permission) {
        accessPermission = permission;
    }
};

#endif
