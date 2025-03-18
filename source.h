#pragma once
#include "Game struct.h"


/*---------Меню---------*/
//Генерирует первое меню в игре
Menu getMainMenu();
//Генерирует меню опции в игре
Menu getOptionMenu();
//Проходится по всем меню и формирует соответствующие настройки
bool getOption(myOption& gOption);
//Выбор режима игры человек, компьютер
bool GameModeMenu(Menu& MO, myOption& gOption);
//Выбор расстановки кораблей
bool shipPos(Menu& MO, myOption& gOption);
//Выбор сложности
bool DifficultyLevel(Menu& MO, myOption& gOption);

/*-------Расстановка кораблей-----*/
//Ручная расстановка
int** manualPlacement(Coordinate coor);
//Случайная расстановка
int** randPlacement();
//Смещает корабль в указанном направлении
void moveShip(eShip*& ship, int size, int d1 = 0, int d2 = 0);
//Закрашивает место где стоял корабль, элементами которые были на карте
void clsSheep(int** m, eShip*& ship, int size, Coordinate coor);
//Поворачивает корабль оставаясь при этом в рамках поля
void rotationS(eShip* ship, int lenShip, char& orientation);
//переносит на карту корабль и ориол корабля
void initShip(int** m, eShip* ship, int lenShip, Coordinate coor);
//Проверка, можно ли установить корабль в это место
bool isEmpty(int** m, eShip* ship, int lenShip);
//Удаляем вспомогательные элементы с карты (2)
void delAuxiliary(int** m);


/*-------Прочее--------*/
//Очистка указателей map
void clearTable(int** table);
//Устанавливает цвет соответствующий номеру
void numToColor(int num);
//Генерирует случайный символ из представленного массива символов
char rndChar(const char t[], int count);
//Возвращает скин корабля относительно номера
const char* numToCharShip(int num);


/*-------Игра-------*/
//Расставляет первоначальные приоритеты для ботов
void creatingPlayers(Game& g);
void startGame(Game& g);