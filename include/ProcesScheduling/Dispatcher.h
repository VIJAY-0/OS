#ifndef __DISPATCHER_H
#define __DISPATCHER_H

#include "ProcesScheduling/Process.h"
#include "ProcesScheduling/CPU.h"

class Dispatcher {
private:
    uint32_t contextSwitchOverhead;

public:
    Dispatcher(uint32_t contextSwitchOverhead);
    ~Dispatcher();

    void dispatch(Process* process, CPU* cpu);
    void terminate(Process* process, CPU* cpu);
};

#endif
