#include "class.hpp"
#include "func.hpp"
#include <raylib.h>
#include <string>

bool interactable::inRange(int shuraimx, int shuraimy, int range) {
    if ((shuraimx >= (xcoord - range)) && (shuraimx <= (xcoord + range)) && (shuraimy >= (ycoord - range)) && (shuraimy <= (ycoord + range))) {
        return true;
    }
    else {
        return false;
    }
}

void interactable::draw() {
    DrawTexture(LoadTexture(path), xcoord, ycoord, WHITE);
}

void interactable::giveClue() {
    DrawText(clue, 0, 0, 20, RED);
}

void interactable::displayInter() {
    DrawText("Hold E to Interact", xcoord, ycoord - 30, 25, RED);
}

void interactable::interrogation (bool &playMusic) {
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music intemusic = LoadMusicStream("music/interrogationmusic.mp3");
    PlayMusicStream(intemusic);
    if (playMusic) {
        PlayMusicStream(intemusic);
    }
    while (!(IsKeyPressed(KEY_M))) {
        if (playMusic) {
            UpdateMusicStream(intemusic);
        }
        BeginDrawing();
        ClearBackground(GRAY);
        DrawText("Q1. How are you?", 0, 0, 25, RED);
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            //Note: Its better if the main game file handles all game music rather than passing it onto the function which causes audio glitches.
            if (IsMusicStreamPlaying(intemusic)) {
                StopMusicStream(intemusic);
            }
            menu(playMusic);
            if (playMusic) {
                PlayMusicStream(intemusic);
            }
        }
    }
}