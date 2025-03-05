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

    State state = Counter;
    
    time_t k;
    time(&k);
    Clock clock(ctime(&k));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state == Counter) {
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
