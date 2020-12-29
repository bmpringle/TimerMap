#include "TimerMap.h"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    TimerMap m = TimerMap();
    m.addTimerToMap("ex");

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << m.getTimerDurationAndReset("ext") << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << m.getTimerDurationAndReset("ex") << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    m.resetAllTimers();

    std::cout << m.getTimerDurationAndReset("ex") << std::endl;
}