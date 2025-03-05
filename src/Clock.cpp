#include "../inc/Clock.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

Clock::Clock(const char* _Time) {
    TIME = (_Time != nullptr) ? _Time : "00:00:00";
    IsStart = false;
    StartTime = 0;
}

void Clock::Draw() {
    DrawText(TIME.c_str(), 80, GetScreenHeight() / 2, 60, BLACK);

    DrawRectangle(80, 470, 200, 50, BLACK);
    if (!IsStart) {
        DrawRectangle(80, 470, 200, 50, GREEN);
        DrawText("START", 140, 485, 30, WHITE);
    } else {
        DrawRectangle(80, 470, 200, 50, RED);
        DrawText("BREAK", 140, 485, 30, WHITE);
    }
}

void Clock::Update() {
    Vector2 pos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && pos.x >= 80 && pos.x <= 280 && pos.y >= 470 && pos.y <= 520) {
        if (!IsStart) {
            IsStart = true;
            time(&StartTime); 
        } else {
            IsStart = false;
        }
    }

    if (IsStart) {
        time_t currentTime;
        time(&currentTime);
        int elapsed = static_cast<int>(difftime(currentTime, StartTime));

        int hours = elapsed / 3600;
        int minutes = (elapsed % 3600) / 60;
        int seconds = elapsed % 60;

        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;
        TIME = oss.str();
    } else {
        TIME = "00:00:00"; 
    }
}
