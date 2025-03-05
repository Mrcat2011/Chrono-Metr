#include "../inc/Time.hpp"

void Time::Update() {
    time(&now);
}

std::string Time::getTime() {
    std::string currTime = ctime(&now);
    return currTime;
}