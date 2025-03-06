#include "../inc/Clock.hpp"
#include "../inc/Button.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

Clock::Clock(const char* _Time) {
    TIME = (_Time != nullptr) ? _Time : "00:00:00";
    IsStart = false;
    StartTime = 0;
}

void Clock::Draw() {
    DrawText(TIME.c_str(), 80, GetScreenHeight() / 2 - 100, 60, BLACK);


    static Button btn("assets/back.png", {100, 100}, 0.1);

    btn.Draw();

    const char* text_for_break_continue;

    if (IsUpdate) {
        text_for_break_continue = "BREAK";
    } else {
        text_for_break_continue = "CONT";
    }

    if (!IsStart) {
        DrawRectangle(80, 370, 200, 50, GREEN);
        DrawText("START", 140, 385, 30, WHITE);
    } else {
        DrawRectangle(80, 470, 100, 50, RED);
        DrawRectangle(190, 470, 100, 50, BLUE);
        DrawText(text_for_break_continue, 100, 485, 20, WHITE);
        DrawText("FINISH", 210, 485, 20, WHITE);
    }
}

void Clock::Update() {
    Vector2 pos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && pos.x >= 80 && pos.x <= 280 && pos.y >= 370 && pos.y <= 420) {
        if (!IsStart) {
            IsStart = true;
            time(&StartTime); 
        } 
    }

    if (IsStart) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && pos.x >= 190 && pos.x <= 290 && pos.y >= 470 && pos.y <= 520) {
            IsStart = false;
        }
    }

    if (IsStart) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && pos.x >= 80 && pos.x <= 180 && pos.y >= 470 && pos.y <= 520) {
            if (IsUpdate) {
                IsUpdate = false;
            } else {
                IsUpdate = true;
            }
        }
    }

    if (IsUpdate == false && IsStart) {
    }

    if (IsStart && IsUpdate) {
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
    } else if (IsStart == false) {
        TIME = "00:00:00"; 
    }
}
