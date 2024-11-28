#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <string>
#include "ProcesScheduling/Process.h"
#include "ProcesScheduling/ReadyQueue.h"

class Scheduler {
private:
    ReadyQueue* readyQueue;
    Process* runningProcess;
    std::vector<Process*> completedProcesses;
    std::string schedulingAlgorithm; // FCFS, SJF, Priority, Round Robin

public:
    Scheduler(std::string algorithm);
    ~Scheduler();

    void addProcess(Process* process);
    void schedule();
    void run(uint32_t timeSlice);
    void switchContext();
    Process* getNextProcess();
};

#endif
