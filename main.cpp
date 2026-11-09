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

    //asset list
    //visual
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D controls;
    Texture2D wasd;
    Texture2D border;
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    bool playMusic = 1;
    //audio/music
    Music menumusic = LoadMusicStream("music/foxsparrow.mp3");
    Music gamemusic = LoadMusicStream("music/buckshotroulleteost.mp3");
    // Music interrogationmusic = LoadMusicStream("music/UndertaleFinale.mp3");
    PlayMusicStream(menumusic);


    //DO NOT TOUCH THIS LOOP ITS BACKUP CODE IN CASE THE FUNCTION FOR MENU EVER FAILS PLEASE DO NOT TOUCH THIS
    
    
    //GUI loop
    // while (!WindowShouldClose()) {
    //     UpdateMusicStream(menumusic);
    //     BeginDrawing();
    //     ClearBackground(RED);
    //     if (IsKeyPressed(KEY_ENTER)) {
    //         StopMusicStream(menumusic);
    //         EndDrawing();
    //         break;
    //     }
    //     EndDrawing();
    //     if (IsKeyPressed(KEY_ONE)) {
    //         //Controls
    //     }
    //     if (IsKeyPressed(KEY_M)) {
    //         if (IsMusicStreamPlaying(menumusic)) {
    //             PauseMusicStream(menumusic);
    //             playMusic = 0;
    //         }
    //         else {
    //             ResumeMusicStream(menumusic);
    //             playMusic = 1;
    //         }
    //     }
    //     if (WindowShouldClose() || (IsKeyPressed(KEY_ESCAPE))) {
    //         CloseWindow();
    //     }
        
    // }

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
        if (IsKeyDown(KEY_E) && (obj1.inRange(shuraimxcoord, shuraimycoord, 100))) {
            obj1.giveClue();
        }
        if (obj1.inRange(shuraimxcoord, shuraimycoord, 100)) {
            obj1.displayInter();
        }
        obj1.draw();
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            //Note: Its better if the main game file handles all game music rather than passing it onto the function which causes audio glitches.
            if (IsMusicStreamPlaying) {
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