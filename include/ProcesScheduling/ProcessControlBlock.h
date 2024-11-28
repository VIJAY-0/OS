#ifndef __PROCESSCONTROLBLOCK_H
#define __PROCESSCONTROLBLOCK_H

#include "ProcesScheduling/Process.h"

class ProcessControlBlock {
private:
    Process* process;
    uint32_t programCounter;
    uint32_t* registers;
    uint32_t priority;
    ProcessState state;

public:
    ProcessControlBlock(Process* process);
    ~ProcessControlBlock();

    void saveState();
    void restoreState();
    Process* getProcess();
};

#endif
