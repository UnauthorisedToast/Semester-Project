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