#pragma once
#include "../console/console.h"
#include "../../Game struct.h"


void draws();
//������ ������� � ��������� �����������
void printSheep(Coordinate coordinate);
//������ ���� SeaWar �� ��������� �����������
void printLog(Coordinate coordinate);
void printPlacementRulles(Coordinate cp);
//������� �� ����� ������� ����
void printGameRules(Coordinate coordinate);
//������ ����� ����
void showT(Coordinate coordinate, int** table);
void numToColor(int num);
const char* numToCharShip(int num);
/// <summary>
/// �������� �����
/// </summary>
/// <param name="s">������ �����</param>
/// <param name="symbol">������� ����������</param>
/// <param name="color1">���� ������� ANSI</param>
/// <param name="color2">���� ������� ANSI</param>
void printRowChars(int s, char symbol, int color1, int color2);
/// <summary>
/// ������ �������������� �����
/// </summary>
/// <param name="c">���������� ������</param>
/// <param name="e">������ �����</param>
/// <param name="s">���������� ��������� �����</param>
void drawVerticalLine(Coordinate c, char e, int s);