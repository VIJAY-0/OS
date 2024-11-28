#ifndef __PROCESS_H
#define __PROCESS_H

#include <common/types.h>

enum class ProcessState {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {
private:
    uint32_t pid;
    uint32_t priority;
    uint32_t arrivalTime;
    uint32_t burstTime;
    uint32_t remainingTime;
    ProcessState state;

public:
    Process(uint32_t pid, uint32_t priority, uint32_t arrivalTime, uint32_t burstTime);
    ~Process();

    uint32_t getPID();
    void updateState(ProcessState newState);
    uint32_t getRemainingTime();
    void execute(uint32_t timeSlice);
    ProcessState getState();
};

#endif
