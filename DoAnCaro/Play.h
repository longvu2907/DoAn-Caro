#pragma once
#include "Board.h"
#include "mainMenu.h"
#include "Start.h"
#include "checkTurn.h"
#include <string.h>


void Play(int&, int&, int&, int, int, int, int, std::string , std::string);
int checkXO(int);
void tickXO(int, int, int&, int);
void resetBoard();
void Init(int, std::string ,std::string,int load = 1);
void AnConTro();
void HienConTro();
void Continue();
void loadData(int data[60][60]);