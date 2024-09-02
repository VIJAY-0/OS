
#ifndef __INTERRUPTMANAGER_H
#define __INTERRUPTMANAGER_H

#include <common/types.h>
#include <hardware communication/gdt.h>
#include <hardware communication/port.h>


    class InterruptManager;

    class InterruptHandler
    {
    protected:
        uint8_t InterruptNumber;
        InterruptManager* interruptManager;
        InterruptHandler(InterruptManager* interruptManager, uint8_t InterruptNumber);
        ~InterruptHandler();
    public:
        virtual uint32_t HandleInterrupt(uint32_t esp);
    };


    class InterruptManager
    {
        friend class InterruptHandler;
        protected:

            static InterruptManager* ActiveInterruptManager;
            InterruptHandler* handlers[256];

            struct GateDescriptor
            {
                uint16_t handlerAddressLowBits;
                uint16_t gdt_codeSegmentSelector;
                uint8_t reserved;
                uint8_t access;
                uint16_t handlerAddressHighBits;
            } __attribute__((packed));

            static GateDescriptor interruptDescriptorTable[256];

            struct InterruptDescriptorTablePointer
            {
                uint16_t size;
                uint32_t base;
            } __attribute__((packed));

            uint16_t hardwareInterruptOffset;
            static void SetInterruptDescriptorTableEntry(uint8_t interrupt,
                uint16_t codeSegmentSelectorOffset, void (*handler)(),
                uint8_t DescriptorPrivilegeLevel, uint8_t DescriptorType);


            static void InterruptIgnore();

            static void HandleInterruptRequest0x00();
            static void HandleInterruptRequest0x01();
            static void HandleInterruptRequest0x0C();

            static uint32_t HandleInterrupt(uint8_t interrupt, uint32_t esp);
            uint32_t DoHandleInterrupt(uint8_t interrupt, uint32_t esp);

            Port8BitSlow programmableInterruptControllerMasterCommandPort;
            Port8BitSlow programmableInterruptControllerMasterDataPort;
            Port8BitSlow programmableInterruptControllerSlaveCommandPort;
            Port8BitSlow programmableInterruptControllerSlaveDataPort;

        public:
            InterruptManager(uint16_t hardwareInterruptOffset, GlobalDescriptorTable* globalDescriptorTable);
            ~InterruptManager();
            uint16_t HardwareInterruptOffset();
            void Activate();
            void Deactivate();
    };
#endif