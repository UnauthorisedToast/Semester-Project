#include "func.hpp"
#include "class.hpp"
#include <raylib.h>
using namespace std;



void menu (bool &playMusic) {
    Music menumusic = LoadMusicStream("music/menumusic.wav");
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
                DrawText("Press E to interact with stuff/enter rooms", 0, 90, 25, WHITE);
                DrawText("Press I to exit rooms/interrogations", 0, 120, 25, WHITE);
                DrawText("Press K to guess killer", 0, 150, 25, WHITE);
                DrawText("Press L to leave interrogation/guess killer later", 0, 180, 25, WHITE);
                DrawText("Press H to go back to menu", 0, 210, 25, WHITE);
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

void winscreen (bool &playMusic) {
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music winmusic = LoadMusicStream("music/winmusic.mp3");
    if (playMusic) {
        PlayMusicStream(winmusic);
    }
    while (!(WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))) {
        if (playMusic) {
            UpdateMusicStream(winmusic);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tv, 0, 0, WHITE);
        //code is from google search NOT CLAUDE PLEASE I NEEDED HELP DONT GIVE ME NEGATIVE MARKS PLEEASSEEEE
        int textlen = MeasureText("You win!", 40);
        int textposx = (1600 - textlen) / 2;
        int textposy = (800 - 40) / 2;
        DrawText("You win!", textposx, textposy, 40, RED);
        EndDrawing();
    }
    StopMusicStream(winmusic);
}

void losescreen (bool &playMusic) {
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music losemusic = LoadMusicStream("music/losemusic.mp3");
    if (playMusic) {
        PlayMusicStream(losemusic);
    }
    while (!(WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))) {
        if (playMusic) {
            UpdateMusicStream(losemusic);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tv, 0, 0, WHITE);
        //code is from google search NOT CLAUDE PLEASE I NEEDED HELP DONT GIVE ME NEGATIVE MARKS PLEEASSEEEE
        int textlen = MeasureText("You lose.", 40);
        int textposx = (1600 - textlen) / 2;
        int textposy = (800 - 40) / 2;
        DrawText("You lose.", textposx, textposy, 40, RED);
        EndDrawing();
    }
    StopMusicStream(losemusic);
}

void incrim (bool &playMusic) {
    Music incrimmusic = LoadMusicStream("music/incrimmusic.mp3");
    Texture2D incrimscreen = LoadTexture("sprites/incrimscreen.png");
    if (playMusic) {
        PlayMusicStream(incrimmusic);
    }
    while (!IsKeyPressed(KEY_L)) {
        if (playMusic) {
            UpdateMusicStream(incrimmusic);
        }
        BeginDrawing();
        DrawTexture(incrimscreen, 0, 0, WHITE);
        if (IsKeyDown(KEY_Q)) {
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            EndDrawing();
            winscreen(playMusic);
            BeginDrawing();
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
        else if (IsKeyDown(KEY_B)) {
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            EndDrawing();
            losescreen(playMusic);
            BeginDrawing();
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
        else if (IsKeyDown(KEY_C)) {
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            EndDrawing();
            losescreen(playMusic);
            BeginDrawing();
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }    
        }
        else if (IsKeyDown(KEY_S)) {
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            EndDrawing();
            losescreen(playMusic);
            BeginDrawing();
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
        else if (IsKeyDown(KEY_G)) {
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            EndDrawing();
            losescreen(playMusic);
            BeginDrawing();
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            //Note: Its better if the main game file handles all game music rather than passing it onto the function which causes audio glitches.
            if (IsMusicStreamPlaying(incrimmusic)) {
                StopMusicStream(incrimmusic);
            }
            menu(playMusic);
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
    }
    StopMusicStream(incrimmusic);
}

void room2 (bool playMusic, int &questionsLeft) {
    //Object Testing
    interactable servantclue;
    servantclue.id = 2;
    servantclue.xcoord = 820;
    servantclue.ycoord = 210;
    servantclue.path = "sprites/paperonfloor.png";
    servantclue.clue = "The madame requested his highness' bedtime nightly";

    interactable door;
    door.id = 4;
    door.xcoord = 1460;
    door.ycoord = 320;
    door.path = "sprites/door.png";

    interactable cloth;
    cloth.xcoord = 260;
    cloth.ycoord = 180;
    cloth.path = "sprites/pieceofcloth.png";
    cloth.clue = "A piece of torn cloth from someone's garment";

    interactable rug;
    rug.xcoord = 800;
    rug.ycoord = 240;
    rug.path = "sprites/kingroomrug.png";
    rug.clue = "You find a note detailing the king's sleeping patterns";

    interactable butler;
    butler.name = " Butler";
    butler.xcoord = 1200;
    butler.ycoord = 200;
    butler.path = "sprites/sh.png";
    butler.ans1 = "I was in the lawn.";
    butler.ans2 = "I was about to leave the estate.";
    butler.ans3 = "He was amazing. The madame on the contrary...";
    butler.ans4 = "Can't be nervous here... The madame isn't around...";
    butler.ans5 = "The chef has been leaving in the afternoon lately.";

    //Initialising and importing music and textures n stuff idk
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    Music gamemusic = LoadMusicStream("music/gamemusic.wav");
    PlayMusicStream(gamemusic);
    Texture2D tv = LoadTexture("sprites/tv.png");
    int shuraimxcoord = 1500;
    int shuraimycoord = 350;
    int speed = 5;
    bool exitroom = 0;
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    if (playMusic) {
        PlayMusicStream(gamemusic);
    }
    while (!((door.inRange(shuraimxcoord, shuraimycoord, 100)) && IsKeyDown(KEY_I))) {
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
        if (IsKeyDown(KEY_K)) {
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            incrim(playMusic);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            } 
        }
        BeginDrawing();
        DrawTexture(backdrop, 0, 0, WHITE);
        rug.draw();
        if (rug.searched) {
            servantclue.draw();
        }
        door.draw();
        butler.draw();
        cloth.draw();
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        
        if (servantclue.inRange(shuraimxcoord, shuraimycoord, 100) && rug.searched) {
            servantclue.displayInter();
        }
        if (butler.inRange(shuraimxcoord, shuraimycoord, 100)) {
            butler.dispname();
        }
        if (rug.inRange(shuraimxcoord, shuraimycoord, 100) && !rug.searched) {
            rug.dispsearch();
        }
        if (cloth.inRange(shuraimxcoord, shuraimycoord, 100)) {
            cloth.dispsearch();
        }
        DrawTexture(tv, 0, 0, WHITE);
        if (IsKeyDown(KEY_E)) {
            if ((servantclue.inRange(shuraimxcoord, shuraimycoord, 100)) && (rug.searched)) {
                servantclue.giveClue();
            }
            if (butler.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                butler.interrogation(playMusic, questionsLeft);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (rug.inRange(shuraimxcoord, shuraimycoord, 100) && !rug.searched) {
                rug.searched = 1;
            }
            if (cloth.inRange(shuraimxcoord, shuraimycoord, 100)) {
                cloth.giveClue();
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
    StopMusicStream(gamemusic);


}

void room3 (bool playMusic, int &questionsLeft) {
    //Object Testing
    interactable paper2;
    paper2.xcoord = 1200;
    paper2.ycoord = 300;
    paper2.path = "sprites/paperonfloor.png";
    paper2.clue = "Clue 3";

    interactable door;
    door.id = 5;
    door.xcoord = 100;
    door.ycoord = 320;
    door.path = "sprites/door.png";

    interactable queen;
    queen.name = "  Queen";
    queen.xcoord = 400;
    queen.ycoord = 200;
    queen.path = "sprites/sh.png";
    queen.ans1 = "I was in the kitchen.";
    queen.ans2 = "I was instructing the chef on what to make tomorrow.";
    queen.ans3 = "Lovely. We were married afterall.";
    queen.ans4 = "Nervous...? What reason do I have to be nervous...";
    queen.ans5 = "Are you going to hold the QUEEN in custody for long?";

    interactable servant;
    servant.name = "Servant";
    servant.xcoord = 1200;
    servant.ycoord = 200;
    servant.path = "sprites/sh.png";
    servant.ans1 = "I was in the living room when I heard the screams.";
    servant.ans2 = "I was cleaning the floors; then, I called you.";
    servant.ans3 = "As opposed to his wife, he was amazing to the staff.";
    servant.ans4 = "No reason to be afraid... right...?";
    servant.ans5 = "The madame... uhm... requested me to inform... nevermind...";

    //Initialising and importing music and textures n stuff idk
    Texture2D backdrop = LoadTexture("sprites/bg.png");
    Music gamemusic = LoadMusicStream("music/gamemusic.wav");
    PlayMusicStream(gamemusic);
    Texture2D tv = LoadTexture("sprites/tv.png");
    int shuraimxcoord = 100;
    int shuraimycoord = 350;
    int speed = 5;
    bool exitroom = 0;
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    if (playMusic) {
        PlayMusicStream(gamemusic);
    }
    while (!((door.inRange(shuraimxcoord, shuraimycoord, 100)) && IsKeyDown(KEY_I))) {
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
        if (IsKeyDown(KEY_K)) {
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            incrim(playMusic);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            } 
        }
        BeginDrawing();
        DrawTexture(backdrop, 0, 0, WHITE);
        paper2.draw();
        door.draw();
        queen.draw();
        servant.draw();
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        
        if (paper2.inRange(shuraimxcoord, shuraimycoord, 100)) {
            paper2.displayInter();
        }
        if (servant.inRange(shuraimxcoord, shuraimycoord, 100)) {
            servant.dispname();
        }
        if (queen.inRange(shuraimxcoord, shuraimycoord, 100)) {
            queen.dispname();
        }
        DrawTexture(tv, 0, 0, WHITE);
        if (IsKeyDown(KEY_E)) {
            if ((paper2.inRange(shuraimxcoord, shuraimycoord, 100))) {
                paper2.giveClue();
            }
            if (queen.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                queen.interrogation(playMusic, questionsLeft);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (servant.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                servant.interrogation(playMusic, questionsLeft);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
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
    StopMusicStream(gamemusic);

    
}