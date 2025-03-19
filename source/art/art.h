#pragma once
#include "../console/console.h"
#include "../../Game struct.h"


void draws();
//Рисует корабль в указанных координатах
void printSheep(Coordinate coordinate);
//Рисуют лого SeaWar по указанным координатам
void printLog(Coordinate coordinate);
void printPlacementRulles(Coordinate cp);
//Выводит на экран правила игры
void printGameRules(Coordinate coordinate);
//Рисует катру поля
void showT(Coordinate coordinate, int** table);
void numToColor(int num);
const char* numToCharShip(int num);
/// <summary>
/// Печатает линию
/// </summary>
/// <param name="s">Длинна линии</param>
/// <param name="symbol">Элемент заполнения</param>
/// <param name="color1">Цвет консоли ANSI</param>
/// <param name="color2">Цвет консоли ANSI</param>
void printRowChars(int s, char symbol, int color1, int color2);
/// <summary>
/// Рисуем горизонтальную линию
/// </summary>
/// <param name="c">Координаты начала</param>
/// <param name="e">Символ линии</param>
/// <param name="s">Количество элементов линии</param>
void drawVerticalLine(Coordinate c, char e, int s);