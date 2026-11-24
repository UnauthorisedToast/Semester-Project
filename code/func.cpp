#include "func.hpp"
#include "class.hpp"
#include <raylib.h>
using namespace std;



void menu (bool &playMusic, bool isplayed) {
    SetTargetFPS(60);
    Music menumusic = LoadMusicStream("music/menumusic.wav");
    Texture2D menu = LoadTexture("sprites/menu.png");
    Font cfont = LoadFontEx("font/qadang.ttf", 10, 0, 0);
    SetTextureFilter(cfont.texture, TEXTURE_FILTER_POINT);
    PlayMusicStream(menumusic);
    if (!playMusic) {
        PauseMusicStream(menumusic);
    }
    while (!IsKeyPressed(KEY_ENTER)) {
        float fontsize = 20.0f;
        float space = fontsize / 10.0f;
        if (playMusic) {
            UpdateMusicStream(menumusic);
        }
        BeginDrawing();
        DrawTexture(menu, 0, 0, WHITE);
        DrawText("Main Menu", 140, 140, 40, WHITE);
        DrawText("Press 1 to view controls", 140, 200, 25, WHITE);
        DrawText("Press M to mute/unmute music", 140, 230, 25, WHITE);
        DrawText("Press Enter to return to game", 140, 260, 25, WHITE);
        DrawText("Press Esc to quit game", 140, 290, 25, WHITE);


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
                DrawTexture(menu, 0, 0, WHITE);
                DrawText("Controls", 140, 140, 40, WHITE);
                DrawText("WASD for movement", 140, 200, 25, WHITE);
                DrawText("Press E to interact with stuff/enter rooms", 140, 230, 25, WHITE);
                DrawText("Press I to exit rooms/interrogations", 140, 260, 25, WHITE);
                DrawText("Press K to guess killer", 140, 290, 25, WHITE);
                DrawText("Press L to leave interrogation/guess killer later", 140, 320, 25, WHITE);
                DrawText("Press H to go back to menu", 140, 350, 25, WHITE);
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

void winscreen (bool &playMusic, int &points) {
    SetTargetFPS(60);
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music winmusic = LoadMusicStream("music/winmusic.mp3");
    if (playMusic) {
        PlayMusicStream(winmusic);
    }
    while (!(IsKeyPressed(KEY_ESCAPE))) {
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
        DrawText("Points: ", 910, 650, 20, RED);
        DrawText(TextFormat("%i", points), 910, 690, 20, RED);
        EndDrawing();
    }
    StopMusicStream(winmusic);
    CloseWindow();
}

void losescreen (bool &playMusic, int &points) {
    Texture2D tv = LoadTexture("sprites/tv.png");
    Music losemusic = LoadMusicStream("music/losemusic.mp3");
    if (playMusic) {
        PlayMusicStream(losemusic);
    }
    while (!(IsKeyPressed(KEY_ESCAPE))) {
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
    CloseWindow();
}

void incrim (bool &playMusic, int &points, bool isplayed) {
    SetTargetFPS(60);
    Music incrimmusic = LoadMusicStream("music/incrimmusic.mp3");
    Texture2D incrimscreen = LoadTexture("sprites/incrimscreen.png");
    if (playMusic) {
        PlayMusicStream(incrimmusic);
    }
    while (!IsKeyPressed(KEY_I)) {
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
            winscreen(playMusic, points);
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
            losescreen(playMusic, points);
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
            losescreen(playMusic, points);
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
            losescreen(playMusic, points);
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
            losescreen(playMusic, points);
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
            menu(playMusic, isplayed);
            if (playMusic) {
                PlayMusicStream(incrimmusic);
            }
        }
    }
    StopMusicStream(incrimmusic);
}

void room2 (bool playMusic, int &questionsLeft, int &points, bool isplayed) {
    SetTargetFPS(60);
    //Object Testing
    static interactable kingsnote;
    kingsnote.id = 2;
    kingsnote.xcoord = 520;
    kingsnote.ycoord = 410;
    Texture2D kingsnoted = LoadTexture("sprites/paperonfloor.png");
    kingsnote.clue = "The queen's cold shoulder saddens me. -King";

    static interactable kingsl;
    kingsl.xcoord = 350;
    kingsl.ycoord = 370;
    Texture2D kingsld = LoadTexture("sprites/paperonfloor.png");
    kingsl.clue = "A love letter from the king to... not the madame...";

    static interactable door;
    door.id = 4;
    door.xcoord = 1460;
    door.ycoord = 320;
    Texture2D doord = LoadTexture("sprites/door.png");

    static interactable cloth;
    cloth.xcoord = 200;
    cloth.ycoord = 160;
    Texture2D clothd = LoadTexture("sprites/pieceofcloth.png");
    cloth.clue = "A piece of torn cloth from someone's garment";

    static interactable rug;
    rug.xcoord = 500;
    rug.ycoord = 270;
    Texture2D rugd = LoadTexture("sprites/kingroomrug.png");

    static interactable books;
    books.xcoord = 100;
    books.ycoord = 100;
    Texture2D booksh = LoadTexture("sprites/bookshelf.png");

    static interactable bed;
    bed.xcoord = 100;
    bed.ycoord = 350;
    Texture2D bedd = LoadTexture("sprites/bed.png");

    static interactable butler;
    butler.name = " Butler";
    butler.xcoord = 1200;
    butler.ycoord = 200;
    Texture2D butlerd = LoadTexture("sprites/butler.png");
    butler.ans1 = "I was in the lawn.";
    butler.ans2 = "I was about to leave the estate.";
    butler.ans3 = "He was amazing. The madame on the contrary...";
    butler.ans4 = "Can't be nervous here... The madame isn't around...";
    butler.ans5 = "The chef has been leaving in the afternoon lately.";

    //Initialising and importing music and textures n stuff idk
    Texture2D backdrop = LoadTexture("sprites/woodfloor.png");
    Music gamemusic = LoadMusicStream("music/gamemusic.wav");
    PlayMusicStream(gamemusic);
    Texture2D tv = LoadTexture("sprites/tv.png");
    int shuraimxcoord = 1500;
    int shuraimycoord = 350;
    int speed = 5;
    bool exitroom = 0;
    Texture2D shuraim = LoadTexture("sprites/sh.png");
    Texture2D kst = LoadTexture("sprites/kingsidetable.png");
    if (playMusic) {
        PlayMusicStream(gamemusic);
    }
    while (!((door.inRange(shuraimxcoord, shuraimycoord, 100)) && IsKeyDown(KEY_I))) {
        if (playMusic) {
            UpdateMusicStream(gamemusic);
        }
        if (IsKeyDown(KEY_D) && ((shuraimxcoord + 72) + speed <= 1500)) {
            shuraimxcoord = shuraimxcoord + speed;
        }
        if (IsKeyDown(KEY_A) && (shuraimxcoord - speed >= 100)) {
            shuraimxcoord = shuraimxcoord - speed;
        }
        if (IsKeyDown(KEY_W) && (shuraimycoord - speed >= 100)) {
            shuraimycoord = shuraimycoord - speed;
        }
        if (IsKeyDown(KEY_S) && ((shuraimycoord + 165) + speed <= 620)) {
            shuraimycoord = shuraimycoord + speed;
        }
        if (IsKeyDown(KEY_K)) {
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            incrim(playMusic, points, isplayed);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            } 
        }
        BeginDrawing();
        //Dont draw anything here (backdrop goes first dude i found out the hard way by messing around for like too long dude)
        DrawTexture(backdrop, 0, 0, WHITE);
        for (int i=0; 100 + (i*200) < 1490; i++) {
            DrawTexture(booksh, 100 + (i*200), 100, WHITE);
        }
        DrawTexture(rugd, rug.xcoord, rug.ycoord, WHITE);
        if (rug.searched) {
            DrawTexture(kingsnoted, kingsnote.xcoord, kingsnote.ycoord, WHITE);
        }
        DrawTexture(doord, door.xcoord, door.ycoord, WHITE);
        DrawTexture(butlerd, butler.xcoord, butler.ycoord, WHITE);
        DrawTexture(kst, 100, 300, WHITE);
        DrawTexture(bedd, bed.xcoord, bed.ycoord, WHITE);
        DrawTexture(kst, 100, 550, WHITE);
        if (bed.searched) {
            DrawTexture(kingsld, kingsl.xcoord, kingsl.ycoord, WHITE);
        }
        if (books.searched) {
            DrawTexture(clothd, cloth.xcoord, cloth.ycoord, WHITE);
        }
        //Draw shuraim on top of everything so it doesnt look like hes walking under stuff...
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        
        if (kingsnote.inRange(shuraimxcoord, shuraimycoord, 100) && rug.searched) {
            kingsnote.displayInter();
        }
        if (butler.inRange(shuraimxcoord, shuraimycoord, 100)) {
            butler.dispname();
        }
        if (rug.inRange(shuraimxcoord, shuraimycoord, 100) && !rug.searched) {
            rug.dispsearch();
        }
        if (cloth.inRange(shuraimxcoord, shuraimycoord, 100) && books.searched) {
            cloth.dispsearch();
        }
        if (books.inRange(shuraimxcoord, shuraimycoord, 100) && !books.searched) {
            books.dispsearch();
        }
        if (kingsl.inRange(shuraimxcoord, shuraimycoord, 200) && bed.searched) {
            kingsl.displayInter();
        }
        if (bed.inRange(shuraimxcoord, shuraimycoord, 400) && !bed.searched) {
            bed.dispsearch();
        }
        DrawTexture(tv, 0, 0, WHITE);
        DrawText("King's Bedroom", 100, 50, 40, RED);
        if (IsKeyDown(KEY_E)) {
            if ((kingsnote.inRange(shuraimxcoord, shuraimycoord, 100)) && (rug.searched)) {
                kingsnote.giveClue(points);
            }
            if (butler.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                butler.interrogation(playMusic, questionsLeft, points, isplayed);
                if (playMusic) {
                    PlayMusicStream(gamemusic);
                }
                BeginDrawing();
            }
            if (rug.inRange(shuraimxcoord, shuraimycoord, 100) && !rug.searched) {
                rug.searched = 1;
            }
            if (books.inRange(shuraimxcoord, shuraimycoord, 100) && !books.searched) {
                books.searched = 1;
            } 
            if (cloth.inRange(shuraimxcoord, shuraimycoord, 100) && books.searched) {
                cloth.giveClue(points);
            }
            if (bed.inRange(shuraimxcoord, shuraimycoord, 400) && !bed.searched) {
                bed.searched = 1;
            }
            if (kingsl.inRange(shuraimxcoord, shuraimycoord, 200) && bed.searched) {
                kingsl.giveClue(points);
            }
        }
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            //Note: Its better if the main game file handles all game music rather than passing it onto the function which causes audio glitches.
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            menu(playMusic, isplayed);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            }
        }
        
    }
    StopMusicStream(gamemusic);


}

void room3 (bool playMusic, int &questionsLeft, int &points, bool isplayed) {
    SetTargetFPS(60);
    //Object Testing

    static interactable bed;
    bed.xcoord = 1200;
    bed.ycoord = 300;
    Texture2D bedd = LoadTexture("sprites/emptybed.png");

    static interactable servantsnote;
    servantsnote.xcoord = 1210;
    servantsnote.ycoord = 450;
    Texture2D servantsnoted = LoadTexture("sprites/paperonfloor.png");
    servantsnote.clue = "The king sleeps at 8pm nightly madame.";

    static interactable drt;
    drt.xcoord = 800;
    drt.ycoord = 100;
    Texture2D drtd = LoadTexture("sprites/dressingtablesmall.png");

    static interactable paper2;
    paper2.xcoord = 850;
    paper2.ycoord = 225;
    Texture2D paper2d = LoadTexture("sprites/paperonfloor.png");
    paper2.clue = "A reminiscent note of the 'King's love'";

    static interactable door;
    door.id = 5;
    door.xcoord = 100;
    door.ycoord = 320;
    Texture2D doord = LoadTexture("sprites/door.png");

    static interactable queen;
    queen.name = "  Queen";
    queen.xcoord = 530;
    queen.ycoord = 300;
    Texture2D queend = LoadTexture("sprites/queen.png");
    queen.ans1 = "I was in the kitchen.";
    queen.ans2 = "I was instructing the chef on what to make tomorrow.";
    queen.ans3 = "Lovely. We were married afterall.";
    queen.ans4 = "Nervous...? What reason do I have to be nervous...";
    queen.ans5 = "Are you going to hold the QUEEN in custody for long?";

    static interactable servant;
    servant.name = "Servant";
    servant.xcoord = 900;
    servant.ycoord = 400;
    Texture2D servantd = LoadTexture("sprites/servant.png");
    servant.ans1 = "I was in the living room when I heard the screams.";
    servant.ans2 = "I was cleaning the floors; then, I called you.";
    servant.ans3 = "As opposed to his wife, he was amazing to the staff.";
    servant.ans4 = "No reason to be afraid... right...?";
    servant.ans5 = "The madame... uhm... requested me to inform... nevermind...";

    Texture2D rugd = LoadTexture("sprites/kingroomrug.png");
    Texture2D qst = LoadTexture("sprites/queensidetable.png");

    //Initialising and importing music and textures n stuff idk
    Texture2D backdrop = LoadTexture("sprites/woodfloor.png");
    Music gamemusic = LoadMusicStream("music/gamemusic.wav");
    Texture2D booksh = LoadTexture("sprites/bookshelf.png");
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
        if (IsKeyDown(KEY_D) && ((shuraimxcoord + 72) + speed <= 1500)) {
            shuraimxcoord = shuraimxcoord + speed;
        }
        if (IsKeyDown(KEY_A) && (shuraimxcoord - speed >= 100)) {
            shuraimxcoord = shuraimxcoord - speed;
        }
        if (IsKeyDown(KEY_W) && (shuraimycoord - speed >= 100)) {
            shuraimycoord = shuraimycoord - speed;
        }
        if (IsKeyDown(KEY_S) && ((shuraimycoord + 165) + speed <= 620)) {
            shuraimycoord = shuraimycoord + speed;
        }
        if (IsKeyDown(KEY_K)) {
            if (IsMusicStreamPlaying(gamemusic)) {
                StopMusicStream(gamemusic);
            }
            incrim(playMusic, points, isplayed);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            } 
        }
        BeginDrawing();
        DrawTexture(backdrop, 0, 0, WHITE);
        for (int i=0; 100 + (i*200) < 1490; i++) {
            DrawTexture(booksh, 100 + (i*200), 100, WHITE);
        }
        DrawTexture(rugd, 300, 270, WHITE);
        DrawTexture(doord, door.xcoord, door.ycoord, WHITE);
        DrawTexture(queend, queen.xcoord, queen.ycoord, WHITE);
        DrawTexture(servantd, servant.xcoord, servant.ycoord, WHITE);
        DrawTexture(qst, 1445, 250, WHITE);
        DrawTexture(qst, 1445, 500, WHITE);
        DrawTexture(bedd, bed.xcoord, bed.ycoord, WHITE);
        DrawTexture(drtd, drt.xcoord, drt.ycoord, WHITE);
        DrawTexture(shuraim, shuraimxcoord, shuraimycoord, WHITE);
        if (servant.inRange(shuraimxcoord, shuraimycoord, 100)) {
            servant.dispname();
        }
        if (queen.inRange(shuraimxcoord, shuraimycoord, 100)) {
            queen.dispname();
        }
        if (drt.inRange(shuraimxcoord, shuraimycoord, 200) && !drt.searched) {
            drt.dispsearch();
        }
        if (drt.searched) {
            DrawTexture(paper2d, paper2.xcoord, paper2.ycoord, WHITE);
            if (paper2.inRange(shuraimxcoord, shuraimycoord, 200)) {
                paper2.displayInter();
            }
        }
        if (bed.inRange(shuraimxcoord, shuraimycoord, 150) && !bed.searched) {
            bed.dispsearch();
        }
        if (bed.searched) {
            DrawTexture(servantsnoted, servantsnote.xcoord, servantsnote.ycoord, WHITE);
            if (servantsnote.inRange(shuraimxcoord, shuraimycoord, 100)) {
                servantsnote.displayInter();
            }
        }
        DrawTexture(tv, 0, 0, WHITE);
        DrawText("Queen's Bedroom", 100, 50, 40, RED);
        if (IsKeyDown(KEY_E)) {
            if (drt.inRange(shuraimxcoord, shuraimycoord, 200) && !drt.searched) {
                drt.searched = 1;
            }
            if (paper2.inRange(shuraimxcoord, shuraimycoord, 200) && drt.searched) {
                paper2.giveClue(points);
            }
            if (bed.inRange(shuraimxcoord, shuraimycoord, 150) && !bed.searched) {
                bed.searched = 1;
            }
            if (servantsnote.inRange(shuraimxcoord, shuraimycoord, 100) && bed.searched) {
                servantsnote.giveClue(points);
            }
            if (queen.inRange(shuraimxcoord, shuraimycoord, 100)) {
                EndDrawing();
                if (IsMusicStreamPlaying(gamemusic)) {
                    StopMusicStream(gamemusic);
                }
                queen.interrogation(playMusic, questionsLeft, points, isplayed);
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
                servant.interrogation(playMusic, questionsLeft, points, isplayed);
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
            menu(playMusic, isplayed);
            if (playMusic) {
                PlayMusicStream(gamemusic);
            }
        }
        
    }
    StopMusicStream(gamemusic);
}