#include "class.hpp"
#include <raylib.h>

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