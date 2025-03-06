#include "raylib.h"
#include "../inc/Clock.hpp"
#include "../inc/Time.hpp"
#include "../inc/GlobalVariable.hpp"

const int screenHeight = 600;
const int screenWidth = 400;

int main(int argc, char const *argv[])
{
    /* code */
    InitWindow(screenWidth, screenHeight, "Clock");

    State state = MENU;
    
    time_t k;
    time(&k);
    Clock clock(ctime(&k));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state == MENU) {
            //MENU CODE
            DrawRectangle(0, 0, 400, 100, WHITE);
            DrawRectangleLines(0, 0, 400, 100, BLACK);

            DrawText("Counter", 50, 50, 50, BLACK);

            Vector2 pos = GetMousePosition();
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (pos.x >= 0 && pos.x <= 400 && pos.y >= 0 && pos.y <= 100) {
                    state = Counter;
                }
            }


        } else if (state == Counter) {
            time(&k);
            clock.Update();
            clock.Draw();
        } else {
            //code2
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
