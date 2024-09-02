
#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <common/types.h>
#include <hardware communication/interrupts.h>
#include <hardware communication/port.h>
#include <Drivers/Driver.h>

    class KeyboardDriver : public InterruptHandler , public Driver
    {
        Port8Bit dataport;
        Port8Bit commandport;
    public:
        KeyboardDriver(InterruptManager* manager);
        ~KeyboardDriver();
        virtual uint32_t HandleInterrupt(uint32_t esp);
        virtual void Activate();
    };

#endif