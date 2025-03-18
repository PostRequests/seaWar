#pragma once
#include "../console/console.h"
#include "../../Game struct.h"


//Рисует корабль в указанных координатах
void printSheep(Coordinate coordinate);
//Рисуют лого SeaWar по указанным координатам
void printLog(Coordinate coordinate);
void printPlacementRulles(Coordinate cp);
void printGameRules(Coordinate coordinate);
void showT(Coordinate coordinate, int** table);
void numToColor(int num);
const char* numToCharShip(int num);