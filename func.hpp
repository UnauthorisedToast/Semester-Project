#pragma once
#include <raylib.h>
using namespace std;

void menu (bool &playMusic, bool isplayed);

void room2 (bool playMusic, int &questionsLeft, int &points, bool isplayed);

void room3 (bool playMusic, int &questionsLeft, int &points, bool isplayed);

void interrogation (bool &playMusic, int &points, bool isplayed);

void incrim (bool &playMusic, int &points, bool isplayed);

void winscreen (bool &playMusic, int &points);

void losescreen (bool &playMusic, int &points);