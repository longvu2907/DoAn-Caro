#pragma once
#include "Board.h"
#include "mainMenu.h"
#include "Start.h"
#include "checkTurn.h"

void Play(int&, int&, int&, int, int, int);
int checkXO();
void tickXO(int, int, int&);
void resetBoard();
void init(int);
void AnConTro();
void HienConTro();