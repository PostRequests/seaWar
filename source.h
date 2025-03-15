#pragma once
#include "Game struct.h"


Menu getMainMenu();
Menu getOptionMenu();
bool getOption(myOption& gOption);
void clearTable(int** table);
int** manualPlacement(Coordinate coor);
void numToColor(int num);