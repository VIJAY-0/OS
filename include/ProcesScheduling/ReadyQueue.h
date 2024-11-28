#ifndef __READYQUEUE_H
#define __READYQUEUE_H

#include <vector>
#include "ProcesScheduling/Process.h"

class ReadyQueue {
private:
    std::vector<Process*> queue;

public:
    ReadyQueue();
    ~ReadyQueue();

    void enqueue(Process* process);
    Process* dequeue();
    bool isEmpty();
    Process* peek();
};

#endif
