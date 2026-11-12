#include <raylib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include "class.hpp"
#include "func.hpp"
using namespace std;



int main () {
    SetTargetFPS(60);
    InitWindow(1600, 800, "Shuraim Homeless");
    InitAudioDevice();
    SetExitKey(KEY_NULL);
    //default coords
    int shuraimxcoord = 800;
    int shuraimycoord = 400;
    int speed = 5;

    interactable obj1;
    obj1.id = 1;
    obj1.xcoord = 800;
    obj1.ycoord = 400;
    obj1.path = "sprites/paperonfloor.png";
    obj1.clue = "The servants have been acting quite suspiciously.";

    interactable door;
    door.id = 3;
    door.xcoord = 0;
    door.ycoord = 320;
    door.path = "sprites/door.png";

    //asset list
    //visual
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D controls;
    Texture2D wasd;
    Texture2D border;
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    bool playMusic = 1;
    //audio/music
    // Music menumusic = LoadMusicStream("music/foxsparrow.mp3");
    Music gamemusic = LoadMusicStream("music/buckshotroulleteost.mp3");
    // Music interrogationmusic = LoadMusicStream("music/UndertaleFinale.mp3");

 
    menu(playMusic);
    //game loop
    if (playMusic) {
        PlayMusicStream(gamemusic);
    }
    
    while (!WindowShouldClose()) {
        if (playMusic) {
            UpdateMusicStream(gamemusic);
        }
        //according to tutorial event handling goes first
        //movement
        if (IsKeyDown(KEY_D)) {
            shuraimxcoord = shuraimxcoord + speed;
        }
        if (IsKeyDown(KEY_A)) {
            shuraimxcoord = shuraimxcoord - speed;
        }
        if (IsKeyDown(KEY_W)) {
            shuraimycoord = shuraimycoord - speed;
        }
        if (IsKeyDown(KEY_S)) {
            shuraimycoord = shuraimycoord + speed;
        }
        // then update of positions
        // DRAWING?!?!?!?!
        BeginDrawing();
        // ClearBackground(WHITE);
        DrawTexture(backdrop, 0, 0, WHITE);
        if (IsKeyDown(KEY_E)) {
            if ((obj1.inRange(shuraimxcoord, shuraimycoord, 100))) {
                obj1.giveClue();
            }
            if (door.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                room2(playMusic);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
        }
        if (obj1.inRange(shuraimxcoord, shuraimycoord, 100)) {
            obj1.displayInter();
        }
        obj1.draw();
        door.draw();
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            //Note: Its better if the main game file handles all game music rather than passing it onto the function which causes audio glitches.
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            menu(playMusic);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            }
        }
    }


    CloseWindow();
    return 0;
}