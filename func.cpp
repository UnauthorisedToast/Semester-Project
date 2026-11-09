#include "func.hpp"
#include <raylib.h>

void menu (bool &playMusic) {
    Music menumusic = LoadMusicStream("music/foxsparrow.mp3");
    Music gamemusic = LoadMusicStream("music/buckshotroulleteost.mp3");
    if (IsMusicStreamPlaying) {
        StopMusicStream(gamemusic);
        PlayMusicStream(menumusic);
    }
    while (!IsKeyPressed(KEY_ENTER)) {
        BeginDrawing();
        ClearBackground(RED);
        if (IsKeyPressed(KEY_ENTER)) {
            StopMusicStream(menumusic);
            EndDrawing();
            break;
        }
        EndDrawing();
        if (IsKeyPressed(KEY_ONE)) {
            //Controls
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
        if (WindowShouldClose() || (IsKeyPressed(KEY_ESCAPE))) {
            CloseWindow();
        }
        if (playMusic) {
            UpdateMusicStream(menumusic);
        }

    }
    if (playMusic) {
        StopMusicStream(menumusic);
        PlayMusicStream(gamemusic);
    }
}