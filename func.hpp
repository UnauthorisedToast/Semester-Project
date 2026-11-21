#pragma once
#include <raylib.h>
using namespace std;

void menu (bool &playMusic);

void room2 (bool playMusic, int &questionsLeft, int &points);

void room3 (bool playMusic, int &questionsLeft, int &points);

void interrogation (bool &playMusic, int &points);

void incrim (bool &playMusic, int &points);

void winscreen (bool &playMusic, int &points);

void losescreen (bool &playMusic, int &points);