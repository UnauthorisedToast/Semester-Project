#pragma once
#include <raylib.h>
using namespace std;

void menu (bool &playMusic);

void room2 (bool playMusic, int &questionsLeft);

void room3 (bool playMusic, int &questionsLeft);

void interrogation (bool &playMusic);

void incrim (bool &playMusic);

void winscreen (bool &playMusic);

void losescreen (bool &playMusic);