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
                DrawText("I to leave a room", 0, 120, 25, WHITE);
                DrawText("Esc for menu", 0, 150, 25, WHITE);
                DrawText("H to go back", 0, 180, 25, WHITE);
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

void room2 (bool playMusic) {
    //Object Testing
    interactable obj2;
    obj2.id = 2;
    obj2.xcoord = 800;
    obj2.ycoord = 400;
    obj2.path = "sprites/paperonfloor.png";
    obj2.clue = "Clue 2";

    interactable door;
    door.id = 4;
    door.xcoord = 1560;
    door.ycoord = 320;
    door.path = "sprites/door.png";

    //Initialising and importing music and textures n stuff idk
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    Music gamemusic = LoadMusicStream("music/buckshotroulleteost.mp3");
    PlayMusicStream(gamemusic);
    int shuraimxcoord = 1500;
    int shuraimycoord = 350;
    int speed = 5;
    bool exitroom = 0;
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    if (playMusic) {
        PlayMusicStream(gamemusic);
    }
    while (!exitroom) {
        if ((door.inRange(shuraimxcoord, shuraimycoord, 100)) && IsKeyDown(KEY_I)) {
            exitroom = 1;
        }
        if (playMusic) {
            UpdateMusicStream(gamemusic);
        }
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
        BeginDrawing();
        DrawTexture(backdrop, 0, 0, WHITE);
        obj2.draw();
        DrawText("Room 2", 0, 1560, 40, YELLOW);
        door.draw();
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        if (IsKeyDown(KEY_E)) {
            if ((obj2.inRange(shuraimxcoord, shuraimycoord, 100))) {
                obj2.giveClue();
            }
        }
        if (obj2.inRange(shuraimxcoord, shuraimycoord, 100)) {
            obj2.displayInter();
        }
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
    StopMusicStream(gamemusic);
}