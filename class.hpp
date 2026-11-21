#pragma once
#include <raylib.h>
#include <string>
using namespace std;

class interactable {
    public:
        int id;
        int xcoord;
        int ycoord;
        const char* name;
        const char* path;
        const char* clue;
        bool q[5] = {0, 0, 0, 0, 0};
        bool searched = 0;
        string ans[5] = {""};
        const char* ans1;
        const char* ans2;
        const char* ans3;
        const char* ans4;
        const char* ans5;
        //location of texture in file not location of texture on window
        

        bool inRange (int shuraimx, int shuraimy, int range); 
        void draw();
        void giveClue(int &points);
        void displayInter();
        void interrogation(bool &playMusic, int &questionsLeft, int &points);
        void dispname();
        void dispsearch();
    };