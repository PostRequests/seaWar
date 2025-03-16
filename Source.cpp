#include "source/console/console.h"
#include "source/menu/menu.h"
#include "source/art/art.h"
#include "Game struct.h"
#include "source.h"
#include <iostream>

Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Морской бой";
	const char* item[] = {
		"Начать игру",
		"Об игре",
		"Выход",
	};
	Coordinate startMenu = { 0,  0 };
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { 0,0,0,c.BlackFG, c.BlueBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	m.start = { cSize.x / 2 - m.width/2,  cSize.y / 3 };
	//Формируем шапку меню
	menuColor colorHead = { 0,0, 0 };
	Coordinate startHead = { m.start.x,m.start.y - 3 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,1,0,1 };//{top, left, down, right}


	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}
Menu getOptionMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Режимы игры:";
	const char* item[] = {
		"Человек – компьютер",
		"Компьютер – компьютер",
		"Назад",
	};
	Coordinate startMenu = { 0,  0 };
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { 0,0,0,c.BlackFG, c.BlueBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	m.start = { cSize.x / 2 - m.width / 2,  cSize.y / 3 };
	//Формируем шапку меню
	menuColor colorHead = { 0,0, 0 };
	Coordinate startHead = { m.start.x,m.start.y - 3 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,1,0,1 };//{top, left, down, right}


	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}
char rndChar(const char t[], int count) {
	return t[rand() % count];
}
bool GameModeMenu(Menu &MO, myOption& gOption) {
	Coordinate CS = getConsoleSize();
	const char* a[] = { "Человек – компьютер",
		"Компьютер – компьютер",
		"Назад", };
	reConstructMenu(MO, a, 3, "     Режимы игры     ");
	int out = getShowMenu(MO);
	if (out == 2) return false;
	else if (out or !out) {
		gOption.humanPlay = !out;
		if (!out) return shipPos(MO, gOption);
		else return DifficultyLevel(MO, gOption);
	}
	return false;
}
bool shipPos(Menu& MO, myOption& gOption) {
	Coordinate CS = getConsoleSize();
	const char* a[] = { "Игрок расставляет вручную", "Компьютер расставляет за игрока", "Назад" };
	reConstructMenu(MO, a, 3, "     Расстановка кораблей:     ");
	int out = getShowMenu(MO);
	if (out == 2) GameModeMenu(MO, gOption);
	else if (out or !out) {
		gOption.shipPos = !out;
		DifficultyLevel(MO, gOption);
	}
	return true;
}
bool DifficultyLevel(Menu& MO, myOption& gOption) {
	Coordinate CS = getConsoleSize();
	const char* a[] = { "   Легко  ", "Средне", "Назад" };
	reConstructMenu(MO, a, 3, "Сложность:");
	int out = getShowMenu(MO);
	if (out == 2)
		if (gOption.humanPlay)
			shipPos(MO, gOption);
		else GameModeMenu(MO, gOption);
	else
		gOption.difficulty = out;
	return true;
}
bool getOption(myOption &gOption) {
	Menu MO = getOptionMenu();
	return GameModeMenu(MO, gOption); 
}
void clearTable(int** table) {
	for (int i = 0; i < fieldSize; i++)
		delete[] table[i];
	delete table;
}
//void shiftShip(int** &m, cShip* ship, int lenShip) {
//	ColorANSI3b col;
//	//Определяем свободно ли место, для закраски различными цветами
//	bool isEmpty = true;
//	for (int j = 0; j < lenShip; j++)
//		if (!m[ship[j].x][ship[j].y]) {
//			isEmpty = false;
//			break;
//		}
//	setColor(((isEmpty) ? col.GreenBG : col.RedBG));
//	for (int j = 0; j < lenShip; j++)
//	{
//		setCursorPosition();
//	}
//	while (true)
//	{
//
//	}
//}
void moweShip(cShip* &ship, int size, int d1 = 0, int d2 = 0) {
	for (int i = 0; i < size; i++)
	{
		ship[i].x += d1;
		ship[i].y += d2;
	}
}
void numToColor(int num) {
	ColorANSI3b c;
	switch (num)
	{
	case 0:	setColor(c.BlueBG);	break;
	case 1:	setColor(c.GreenBG); break;
	case 2:	setColor(c.CyanBG); break;
	case 3:	setColor(c.RedBG); break;
	default:
		break;
	}
}
const char* numToCharShip(int num) {
	switch (num)
	{
	case 0 :
		return skinSea;
	case 1:
		return skinShip;
	case 2:
		return skinToDo;
	default:
		break;
	}
}
void clsSheep(int** m, cShip*& ship, int size, Coordinate coor) {
	for (int i = 0; i < size; i++)
	{
		numToColor(m[ship[i].x][ship[i].y]);
		setCursorPosition(coor.x + (ship[i].x * 2), coor.y + ship[i].y);
		std::cout << numToCharShip(m[ship[i].x][ship[i].y]);
	}
}
void rotationS(cShip* ship, int lenShip, char &orientation) {
	if (orientation == 'h') {
		orientation = 'v';
		for (int j = 1; j < lenShip; j++)
		{
			ship[j].x = ship[0].x;
			ship[j].y = ship[0].y + j;
		}
		//Смещение если не влезает по вертикали
		while (ship[lenShip - 1].y > fieldSize - 1) 
			for (int i = 0; i < lenShip; i++)
				ship[i].y--;
	}
	else if (orientation == 'v') {
		orientation = 'h';
		for (int j = 1; j < lenShip; j++)
		{
			ship[j].x = ship[0].x + j;
			ship[j].y = ship[0].y;
		}
		//Смещение если не влезает по горизонтале
		while (ship[lenShip - 1].x > fieldSize - 1)
			for (int i = 0; i < lenShip; i++)
				ship[i].x--;
	}
}
void initShip(int** m, cShip* ship, int lenShip, Coordinate coor) {
	cShip ds{ fieldSize , fieldSize }; //координаты начала квадрата ориола корабля
	cShip de{ 0,0 }; //координаты конца ориола корабля
	for (int i = 0; i < lenShip; i++)
	{
		m[ship[i].x][ship[i].y] = 1;
		//Определяем крайние точки координат
		if (ds.x > ship[i].x) ds.x = ship[i].x;
		if(de.x < ship[i].x) de.x = ship[i].x;
		if (ds.y > ship[i].y) ds.y = ship[i].y;
		if (de.y < ship[i].y) de.y = ship[i].y;
	}
	//Добавляем отступ к координатам
	ds.x--;	ds.y--;	de.x++;	de.y++;
	int dist = 2; //Это номер ориола
	numToColor(dist);

	for (int y = ds.y; y < de.y + 1; y++) {
		for (int x = ds.x; x < de.x + 1; x++) {
			if (x >= 0 && x < fieldSize && y >= 0 && y < fieldSize && !m[x][y]) {
				m[x][y] = dist;
				if (coor.x == -1) continue;
				setCursorPosition(coor.x + (x * 2), coor.y + y);
				std::cout << skinToDo;
				
			}
		}
	}
}
bool isEmpty(int** m, cShip* ship, int lenShip) {
	//Проверяем в границах ли поля корабль
	if (ship[lenShip - 1].x >= fieldSize or ship[lenShip - 1].y >= fieldSize)
		return false;
	//Проверяем, пусто ли место установки
	for (int j = 0; j < lenShip; j++)
		if (m[ship[j].x][ship[j].y])
			return false;
	return true;
}
int** manualPlacement(Coordinate coor){
	ColorANSI3b col;
	int** m = new int* [fieldSize];
	for (int i = 0; i < fieldSize; ++i) 
		m[i] = new int[fieldSize] {0}; 
	char orientation = 'h'; //Ориентация v - вертикальная h - горизонтальная 
	showT(coor, m);
	coor.x += 3;
	coor.y+=1;
	int len = sizeof(shipSize) / sizeof(shipSize[0]);
	for (int i = 0; i < len; i++)
	{
		int lenShip = shipSize[i];
		cShip* ship = new cShip[lenShip];
		//Создаем корабль в центре поля
		for (int j = 0; j < lenShip; j++)
		{
			ship[j].x = fieldSize / 2 + j - 1;
			ship[j].y = fieldSize / 2;
		}
		//Определяем свободно ли место, для закраски различными цветами
		bool iEmpty = isEmpty(m, ship, lenShip);
		setColor(((iEmpty) ? col.GreenBG : col.RedBG));
		for (int j = 0; j < lenShip; j++)
		{
			setCursorPosition(coor.x + (ship[j].x * 2), coor.y + ship[j].y);
			std::cout << skinShip;
		}
		//Двигаем корабль
		while (true)
		{
			bool isMoowe = false;
			char key = catchKey();
			if (key == 'w' and ship[0].y > 0) {
				clsSheep(m, ship, lenShip, coor);
				moweShip(ship, lenShip, 0, -1);
				isMoowe = true;
			}
			else if (key == 's' and ship[lenShip - 1].y < fieldSize - 1) {
				clsSheep(m, ship, lenShip, coor);
				moweShip(ship, lenShip, 0, 1);
				isMoowe = true;
			}
			else if (key == 'a' and ship[0].x > 0) {
				clsSheep(m, ship, lenShip, coor);
				moweShip(ship, lenShip, -1, 0);
				isMoowe = true;
			}
			else if (key == 'd' and ship[lenShip - 1].x < fieldSize - 1) {
				clsSheep(m, ship, lenShip, coor);
				moweShip(ship, lenShip, 1, 0);
				isMoowe = true;
			}
			else if (key == 32) { //Пробел
				if (lenShip < 2) continue; //Если корабль = 1, нет смысла его вращать
				clsSheep(m, ship, lenShip, coor);
				rotationS(ship, lenShip, orientation);
				isMoowe = true;
			}
			else if (key == 13) {//Enter
				if (iEmpty) {
					initShip(m, ship, lenShip, coor);
					break;
				}
			}
			if (isMoowe) {
				//Определяем свободно ли место, для закраски различными цветами
				iEmpty = true;
				for (int j = 0; j < lenShip; j++)
					if (m[ship[j].x][ship[j].y]) {
						iEmpty = false;
						break;
					}
				setColor(((iEmpty) ? col.GreenBG : col.RedBG));
				for (int j = 0; j < lenShip; j++)
				{
					setCursorPosition(coor.x + (ship[j].x * 2), coor.y + ship[j].y);
					std::cout << skinShip;
				}
				///ToDo
			}
			
		}

		delete[] ship;
	}
	resetColor();
	drawEmptyRectangle(coor.x - 3, coor.y - 1, fieldSize + 1, (fieldSize + 2) * 2);
	system("pause>null");
	return m;
}
int** randPlacement() {
	//Создаем поле
	int** m = new int* [fieldSize];
	for (int i = 0; i < fieldSize; ++i)
		m[i] = new int[fieldSize] {0};

	int len = sizeof(shipSize) / sizeof(shipSize[0]);
	for (int i = 0; i < len; i++) {
		int lenShip = shipSize[i];
		cShip* ship = new cShip[lenShip];
		do{
			char orientation = rndChar("vh", 2);
			int rnd1 = rand() % fieldSize;
			int rnd2 = rand() % fieldSize;
			for (int j = 0; j < lenShip; j++)
			{
				ship[j].x = rnd1 + ((orientation == 'v') ? j : 0);
				ship[j].y = rnd2 + ((orientation == 'h') ? j : 0);
			}
		}while (!isEmpty(m, ship, lenShip));
		initShip(m, ship, lenShip, { -1,-1 });
	}
	resetColor();
	showT({1,1}, m);
	return m;
	
}