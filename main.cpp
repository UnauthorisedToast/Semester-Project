#include <raylib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include "class.hpp"
#include "func.hpp"
using namespace std;

//DEV NOTE CURRENT
//fix ram issue D:

int main () {
    SetTargetFPS(60);
    InitWindow(1600, 800, "Shuraim Homeless");
    InitAudioDevice();
    SetExitKey(KEY_NULL);
    int points = 0;
    //default coords
    int shuraimxcoord = 800;
    int shuraimycoord = 400;
    int speed = 5;
    int questionsLeft = 15;

    static interactable obj1;
    obj1.id = 1;
    obj1.xcoord = 800;
    obj1.ycoord = 200;
    Texture2D obj1d = LoadTexture("sprites/paperonfloor.png");
    obj1.clue = "The servants have been acting quite suspiciously.";
    
    static interactable guard;
    guard.name = "  Guard";
    guard.xcoord = 800;
    guard.ycoord = 400;
    Texture2D guardd = LoadTexture("sprites/sh.png");
    guard.ans1 = "Right outside the door.";
    guard.ans2 = "Standing guard. Watched the butler leave.";
    guard.ans3 = "Amazing. Once made a mistake, he didn't even say nun.";
    guard.ans4 = "Nervous? Me? I'm trained in a bajillion martial arts";
    guard.ans5 = "Not really to be honest.";

    static interactable chef;
    chef.name = "   Chef";
    chef.xcoord = 400;
    chef.ycoord = 200;
    chef.path = "sprites/sh.png";
    Texture2D chefd = LoadTexture("sprites/sh.png");
    chef.ans1 = "In my quarters.";
    chef.ans2 = "Thinking what to make the next day.";
    chef.ans3 = "He was a good man. Its a shame what happened.";
    chef.ans4 = "I've got food on the stove and you're holding me up.";
    chef.ans5 = "Nup.";

    static interactable door;
    door.id = 3;
    door.xcoord = 100;
    door.ycoord = 320;
    door.path = "sprites/door.png";
    Texture2D doord = LoadTexture("sprites/door.png");

    static interactable door2;
    door2.xcoord = 1460;
    door2.ycoord = 320;
    door2.path = "sprites/door2.png";
    Texture2D door2d = LoadTexture("sprites/door.png");


    //asset list
    //visual
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D controls;
    Texture2D wasd;
    Texture2D tv = LoadTexture("sprites/tv.png");
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    bool playMusic = 1;
    //audio/music
    // Music menumusic = LoadMusicStream("music/foxsparrow.mp3");
    Music gamemusic = LoadMusicStream("music/gamemusic.wav");
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
        //ROOM 1 AND ROOM 2 DISPLAYS ARE PURELY FOR TESTING
        //Using them later isnt a bad idea tho tbh...

        DrawTexture(backdrop, 0, 0, WHITE);
        
        if (obj1.inRange(shuraimxcoord, shuraimycoord, 100)) {
            obj1.displayInter();
        }
        if (chef.inRange(shuraimxcoord, shuraimycoord, 100)) {
            chef.dispname();
        }
        if (guard.inRange(shuraimxcoord, shuraimycoord, 100)) {
            guard.dispname();
        }
        DrawTexture(obj1d, obj1.xcoord, obj1.ycoord, WHITE);
        DrawTexture(doord, door.xcoord, door.ycoord, WHITE);
        DrawTexture(door2d, door2.xcoord, door2.ycoord, WHITE);
        DrawTexture(guardd, guard.xcoord, guard.ycoord, WHITE);
        DrawTexture(chefd, chef.xcoord, chef.ycoord, WHITE);
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        DrawTexture(tv, 0, 0, WHITE);
        //static Interactables and stuff yk type shi
        if (IsKeyDown(KEY_E)) {
            if ((obj1.inRange(shuraimxcoord, shuraimycoord, 100))) {
                obj1.giveClue(points);
            }
            if (door.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                room2(playMusic, questionsLeft, points);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (door2.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                room3(playMusic, questionsLeft, points);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (guard.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                guard.interrogation(playMusic, questionsLeft, points);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (chef.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                chef.interrogation(playMusic, questionsLeft, points);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
        }
        if (IsKeyDown(KEY_K)) {
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            incrim(playMusic, points);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            } 
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
    CloseWindow();
    return 0;
}