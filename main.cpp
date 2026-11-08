#include <raylib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>
using namespace std;

int main () {
    SetTargetFPS(60);
    InitWindow(1600, 800, "Shuraim Homeless");
    //default coords
    int xcoord = 800;
    int ycoord = 400;
    int speed = 5;

    //game loop
    while (WindowShouldClose() == false) {
        //according to tutorial event handling goes first
        //movement
        if (IsKeyDown(KEY_D)) {
            xcoord = xcoord + speed;
        }
        if (IsKeyDown(KEY_A)) {
            xcoord = xcoord - speed;
        }
        if (IsKeyDown(KEY_W)) {
            ycoord = ycoord - speed;
        }
        if (IsKeyDown(KEY_S)) {
            ycoord = ycoord + speed;
        }
        // then update of positions
        // DRAWING?!?!?!?!
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(xcoord, ycoord, 25, WHITE);
        EndDrawing();
    }


    CloseWindow();
    return 0;
}