#include <raylib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <random>
using namespace std;

int main () {
    SetTargetFPS(60);
    InitWindow(1600, 800, "Shuraim Homeless");
    InitAudioDevice();
    //default coords
    int xcoord = 800;
    int ycoord = 400;
    int speed = 5;
    
    //asset list
    //visual
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D controls;
    Texture2D wasd;
    Texture2D border;
    //audio/music
    Music menumusic = LoadMusicStream("music/buckshotroulleteost.mp3");
    PlayMusicStream(menumusic);

    //GUI loop
    while (!WindowShouldClose()) {
        UpdateMusicStream(menumusic);
        BeginDrawing();
        ClearBackground(RED);
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
        EndDrawing();
        if (IsKeyPressed(KEY_ONE)) {
            //Controls
        }
        if (IsKeyPressed(KEY_M)) {
            if (IsMusicStreamPlaying(menumusic)) {
                PauseMusicStream(menumusic);
            }
            else {
                ResumeMusicStream(menumusic);
            }
        }
        
    }

    //game loop
    while (!WindowShouldClose()) {
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
        ClearBackground(GRAY);
        DrawTexture(shuraim, xcoord, ycoord, WHITE);
        // DrawCircle(xcoord, ycoord, 25, WHITE);
        EndDrawing();
    }


    CloseWindow();
    return 0;
}