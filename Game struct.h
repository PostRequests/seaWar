#pragma once
struct myOption {//Опции игры
	bool humanPlay = false;//true - Человек – компьютер; false - Компьютер – компьютер.
	bool shipPos = false;//true - Игрок расставляет вручную; false - Компьютер расставляет за игрока.
	bool difficulty = true;//true - Случайный выстрел; false - Интеллектуальная игра. Компьютер строит стратегию игры, а не стреляет случайно.
};
const int fieldSize = 10; //Размер поля (10x10)
const int shipSize[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; //Размеры кораблей 

const char skinSea[] = "..";
const char skinShip[] = "[]";
const char skinMiss[] = "**";
const char skinAim[] = "><";

struct Ship {
	Coordinate* ch;
	int count;
};
struct MyMap {
	int** m = nullptr;//Карта боев
	Coordinate pos;//Координаты отрисовки карты
};
struct Game;
struct Player {
	bool (*action)(Player& player, Player& opponent);
	Coordinate* pri1 = nullptr;//Уровень приоритета 1
	int cPri1 = 0; //Количество приоритетов 1
	Coordinate* pri2 = nullptr;//Уровень приоритета 2
	int cPri2 = 0;//Количество приоритетов 2
	MyMap map;//Карта
	int ch = 0;//Количество подбитых кораблей
	Coordinate aim{fieldSize/2,fieldSize/2};
	int sh = 0; //Количество выстрелов
};

struct Game {
	MyMap mapGhost;//Пустая карта
	myOption option;//Опции игры
	Player p1;//Игрок или бот, его характеристики
	Player p2;//Бот и его возможности
};