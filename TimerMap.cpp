#include "TimerMap.h"

TimerMap::TimerMap() : timerMap(std::map<std::string, std::chrono::system_clock::time_point>()) {
    
}

void TimerMap::addTimerToMap(std::string name) {
    timerMap.insert(std::make_pair(name, std::chrono::system_clock::now()));
}

std::chrono::system_clock::duration TimerMap::getTimerDuration(std::string name) {
    if(timerMap.find(name) == timerMap.end()) {
        return std::chrono::system_clock::duration(0);
    }
    std::chrono::system_clock::time_point pTime = timerMap[name];
    std::chrono::system_clock::duration milliseconds = (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - pTime));
    return milliseconds;
}

bool TimerMap::resetTimer(std::string name) {
    if(timerMap.find(name) == timerMap.end()) {
        return false;
    }
    timerMap[name] = std::chrono::system_clock::now();
    return true;
}

void TimerMap::resetAllTimers() {
    for(auto &iterator : timerMap) {
        iterator.second = std::chrono::system_clock::now();
    }
}

std::chrono::system_clock::duration TimerMap::getTimerDurationAndReset(std::string name) {
    if(timerMap.find(name) == timerMap.end()) {
        return std::chrono::system_clock::duration(0);
    }
    std::chrono::system_clock::time_point pTime = timerMap[name];
    std::chrono::system_clock::duration milliseconds = (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - pTime));
    timerMap[name] = std::chrono::system_clock::now();
    return milliseconds;
}

bool TimerMap::removeTimerFromMap(std::string name) {
    if(timerMap.find(name) == timerMap.end()) {
        return false;
    }
    timerMap.erase(name);
    return true;
}

void TimerMap::removeAllTimersFromMap() {
    timerMap.clear();
}