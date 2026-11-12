#include "func.hpp"
#include "class.hpp"
#include <raylib.h>

void menu (bool &playMusic) {
    Music menumusic = LoadMusicStream("music/foxsparrow.mp3");
    PlayMusicStream(menumusic);
    if (!playMusic) {
        PauseMusicStream(menumusic);
    }
    while (!IsKeyPressed(KEY_ENTER)) {
        if (playMusic) {
            UpdateMusicStream(menumusic);
        }
        BeginDrawing();
        ClearBackground(RED);
        DrawText("Main Menu", 0, 0, 40, WHITE);
        DrawText("Press 1 to view controls", 0, 60, 25, WHITE);
        DrawText("Press M to mute/unmute music", 0, 90, 25, WHITE);
        DrawText("Press Enter to return to game", 0, 120, 25, WHITE);
        DrawText("Press Esc to quit game", 0, 150, 25, WHITE);


        if (IsKeyPressed(KEY_ENTER)) {
            StopMusicStream(menumusic);
            EndDrawing();
            break;
        }
        if (IsKeyPressed(KEY_ONE)) {
            EndDrawing();
            while (!IsKeyPressed(KEY_H)) {
                if (playMusic) {
                    UpdateMusicStream(menumusic);
                }
                BeginDrawing();
                ClearBackground(RED);
                DrawText("Controls", 0, 0, 40, WHITE);
                DrawText("WASD for movement", 0, 60, 25, WHITE);
                DrawText("E for interaction", 0, 90, 25, WHITE);
                DrawText("Esc for menu", 0, 120, 25, WHITE);
                DrawText("H to go back", 0, 150, 25, WHITE);
                EndDrawing();
            }
            BeginDrawing();
        }
        if (IsKeyPressed(KEY_M)) {
            if (IsMusicStreamPlaying(menumusic)) {
                PauseMusicStream(menumusic);
                playMusic = 0;
            }
            else {
                ResumeMusicStream(menumusic);
                playMusic = 1;
            }
        }
        EndDrawing();
        if (WindowShouldClose() || (IsKeyPressed(KEY_ESCAPE))) {
            CloseWindow();
        }
    }
    StopMusicStream(menumusic);
}

void mainroom () {
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D controls;
    Texture2D wasd;
    Texture2D border;
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    bool playMusic = 1;

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

    Music gamemusic = LoadMusicStream("music/buckshotroulleteost.mp3");

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
}