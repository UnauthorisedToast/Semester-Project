#include "class.hpp"
#include "func.hpp"
#include <raylib.h>
#include <chrono>
#include <string>
using namespace std;

bool interactable::inRange(int shuraimx, int shuraimy, int range = 100) {
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

void interactable::dispname() {
    DrawText(name, xcoord + 40, ycoord - 10, 25, BLUE);
}

void interactable::dispsearch() {
    Texture obj = LoadTexture(path);
    if ((ycoord - 35) > 100) {
        DrawText("Press E to search", xcoord, ycoord - 10, 25, BLUE);
    }
    else (DrawText("Press E to search", xcoord, ycoord + obj.height + 20, 25, BLUE));
}

void interactable::giveClue(int &points) {
    if (!searched) {
        searched = 1;
        points = points + 100;
    }
    DrawText(clue, 910, 650, 15, RED);
}

void interactable::displayInter() {
    DrawText("Hold E to Interact", xcoord, ycoord - 40, 25, BLUE);
}

void interactable::interrogation (bool &playMusic, int &questionsLeft, int &points) {
    SetTargetFPS(60);
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music intemusic = LoadMusicStream("music/interrogationmusic.mp3");
    PlayMusicStream(intemusic);
    int linestartx, lineendx, liney;
    linestartx = 120;
    lineendx = 1000;
    bool isquestionasked = 0;
    if (playMusic) {
        PlayMusicStream(intemusic);
    }
    while (!(IsKeyPressed(KEY_I))) {
        if (playMusic) {
            UpdateMusicStream(intemusic);
        }
        BeginDrawing();
        ClearBackground(GRAY);
        DrawTexture(tv, 0, 0, WHITE);
        //checks if u hv questions left
        if (questionsLeft>0) {
            DrawText("Q1. Where were you at the time of murder?", 140, 140, 25, RED);
            DrawText("Q2. What were you doing at the time of murder?", 140, 170, 25, RED);
            DrawText("Q3. What were your relations like with the victim?", 140, 200, 25, RED);
            DrawText("Q4. Why are you so nervous?", 140, 230, 25, RED);
            DrawText("Q5. Anything suspicious that you would like to report?", 140, 260, 25, RED);
            if (!isquestionasked) {
                DrawText("Press question number on keyboard to ask question.", 910, 650, 15, RED);            

            }
            //Checks if a questions been asked or no
            if ((IsKeyPressed(KEY_ONE)) && (!q[0])) {
                q[0] = 1;
                isquestionasked = 1;
                points = points + 5;
                questionsLeft--;
            }
            if (IsKeyPressed(KEY_TWO) && (!q[1])) {
                q[1] = 1;
                isquestionasked = 1;
                points = points + 10;
                questionsLeft--;
            }
            if (IsKeyPressed(KEY_THREE) && (!q[2])) {
                q[2] = 1;
                isquestionasked = 1;
                points = points + 15;
                questionsLeft--;
            }
            if (IsKeyPressed(KEY_FOUR) && (!q[3])) {
                q[3] = 1;
                isquestionasked = 1;
                points = points + 20;
                questionsLeft--;
            }
            if (IsKeyPressed(KEY_FIVE) && (!q[4])) {
                q[4] = 1;
                isquestionasked = 1;
                points = points + 25;
                questionsLeft--;
            }

            //cuts out question if a questions been asked
            for (int i=0; i<5; i++) {
                if (q[i]) {
                    liney = ((i+4)*30) + 32;
                    DrawLine(linestartx, liney, lineendx, liney, WHITE);
                }
            }
        }

        if (q[0]) {
                DrawText(ans1, 912, 650, 15, RED);
            }
            if (q[1]) {
                DrawText(ans2, 912, 666, 15, RED);
            }
            if (q[2]) {
                DrawText(ans3, 912, 682, 15, RED);
            }
            if (q[3]) {
                DrawText(ans4, 912, 698, 15, RED);
            }
            if (q[4]) {
                DrawText(ans5, 912, 714, 15, RED);
            }
        
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
    StopMusicStream(intemusic);
}
