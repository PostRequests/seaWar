#pragma once
#include "../console/console.h"
#include "../../Game struct.h"


//������ ������� � ��������� �����������
void printSheep(Coordinate coordinate);
//������ ���� SeaWar �� ��������� �����������
void printLog(Coordinate coordinate);
void printPlacementRulles(Coordinate cp);
void printGameRules(Coordinate coordinate);
void showT(Coordinate coordinate, int** table);
void numToColor(int num);
const char* numToCharShip(int num);