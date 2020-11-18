#pragma once
#include "Board.h"
#include "mainMenu.h"
#include "Start.h"
#include "checkTurn.h"

void Play(int&, int&, int&, int, int, int, int);
int checkXO(int);
void tickXO(int, int, int&, int);
void resetBoard();
void Init(int);
void AnConTro();
void HienConTro();