#ifndef __CPU_H
#define __CPU_H

#include "ProcesScheduling/Process.h"

class CPU {
private:
    Process* currentProcess;
    uint32_t idleTime;

public:
    CPU();
    ~CPU();

    void execute(Process* process, uint32_t timeSlice);
    void updateIdleTime();
    bool isIdle();
};

#endif
