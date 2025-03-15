#pragma once
struct myOption {//Опции игры
	bool humanPlay;//true - Человек – компьютер; false - Компьютер – компьютер.
	bool shipPos;//true - Игрок расставляет вручную; false - Компьютер расставляет за игрока.
	bool difficulty;//true - Случайный выстрел; false - Интеллектуальная игра. Компьютер строит стратегию игры, а не стреляет случайно.
};
const int fieldSize = 10; //Размер поля (10x10)
const int shipSize[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; //Размеры кораблей 
const char skinSea[] = "..";
const char skinShip[] = "[]";
const char skinToDo[] = "**";
struct cShip {
	int x;
	int y;
};