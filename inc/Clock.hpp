#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <string>
#include "raylib.h"
#include "Time.hpp"

class Clock {
public:
    Clock(const char* _Time);
    void Draw();
    void Update();

private:
    std::string TIME;
    bool IsStart;
    time_t StartTime;
};

#endif // CLOCK_HPP