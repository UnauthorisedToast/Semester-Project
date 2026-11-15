#pragma once
#include <raylib.h>
#include <string>


class interactable {
    public:
        int id;
        int xcoord;
        int ycoord;
        const char* path;
        const char* clue;
        bool q[5] = {0, 0, 0, 0, 0};
        //location of texture in file not location of texture on window
        

        bool inRange (int shuraimx, int shuraimy, int range); 
        void draw();
        void giveClue();
        void displayInter();
        void interrogation(bool &playMusic, int &questionsLeft);
};