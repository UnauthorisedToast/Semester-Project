#include "func.hpp"
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
    }
    StopMusicStream(menumusic);
}