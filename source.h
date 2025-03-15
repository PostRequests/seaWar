#pragma once
#include "Game struct.h"


Menu getMainMenu();
Menu getOptionMenu();
bool getOption(myOption& gOption);
void clearTable(int** table);
int** manualPlacement(Coordinate coor);
void numToColor(int num);
bool GameModeMenu(Menu& MO, myOption& gOption);
bool DifficultyLevel(Menu& MO, myOption& gOption);
bool shipPos(Menu& MO, myOption& gOption);