#include "class.hpp"
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
    DrawText(clue, 0, 0, 20, BLACK);
}

void interactable::displayInter() {
    DrawText("Hold E to Interact", xcoord, ycoord - 30, 25, RED);
}