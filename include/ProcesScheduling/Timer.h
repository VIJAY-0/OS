#ifndef __TIMER_H
#define __TIMER_H

#include <stdint.h>

class Timer {
private:
    uint32_t timeQuantum;
    uint32_t elapsedTime;

public:
    Timer(uint32_t timeQuantum);
    ~Timer();

    void startTimer();
    void stopTimer();
    bool isTimeUp();
    uint32_t getElapsedTime();
};

#endif
