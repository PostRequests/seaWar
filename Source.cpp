#include "source/console/console.h"
#include "source/menu/menu.h"
#include "source/art/art.h"
#include "Game struct.h"
#include "source.h"
#include <iostream>
#include <Windows.h>
/*---------Меню---------*/
Menu1 getMainMenu() {
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
	menuColor1 colorMenu = { 0,0,0,c.BlackFG, c.BlueBG };
	Menu1 m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	m.start = { cSize.x / 2 - m.width/2,  cSize.y / 3 };
	//Формируем шапку меню
	menuColor1 colorHead = { 0,0, 0 };
	Coordinate startHead = { m.start.x,m.start.y - 3 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,1,0,1 };//{top, left, down, right}


	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}
Menu1 getOptionMenu() {
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
	menuColor1 colorMenu = { 0,0,0,c.BlackFG, c.BlueBG };
	Menu1 m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	m.start = { cSize.x / 2 - m.width / 2,  cSize.y / 3 };
	//Формируем шапку меню
	menuColor1 colorHead = { 0,0, 0 };
	Coordinate startHead = { m.start.x,m.start.y - 3 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,1,0,1 };//{top, left, down, right}


	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}
bool getOption(myOption& gOption) {
	Menu1 MO = getOptionMenu();
	return GameModeMenu(MO, gOption);
}
bool GameModeMenu(Menu1& MO, myOption& gOption) {
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
bool shipPos(Menu1& MO, myOption& gOption) {
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
bool DifficultyLevel(Menu1& MO, myOption& gOption) {
	Coordinate CS = getConsoleSize();
	const char* a[] = { "   Легко  ", "Средне", "Назад" };
	reConstructMenu(MO, a, 3, "Сложность:");
	int out = getShowMenu(MO);
	if (out == 2)
		if (gOption.humanPlay)
			shipPos(MO, gOption);
		else GameModeMenu(MO, gOption);
	else
		gOption.difficulty = !out;
	return true;
}

/*-------Расстановка кораблей-----*/
int** manualPlacement(Coordinate coor) {
	ColorANSI3b col;
	int** m = new int* [fieldSize];
	for (int i = 0; i < fieldSize; ++i)
		m[i] = new int[fieldSize] {0};
	char orientation = 'h'; //Ориентация v - вертикальная h - горизонтальная 
	showT(coor, m);
	coor.x += 3;
	coor.y += 1;
	int len = sizeof(shipSize) / sizeof(shipSize[0]);
	for (int i = 0; i < len; i++)
	{
		int lenShip = shipSize[i];
		Coordinate* ship = new Coordinate[lenShip];
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
				moveShip(ship, lenShip, 0, -1);
				isMoowe = true;
			}
			else if (key == 's' and ship[lenShip - 1].y < fieldSize - 1) {
				clsSheep(m, ship, lenShip, coor);
				moveShip(ship, lenShip, 0, 1);
				isMoowe = true;
			}
			else if (key == 'a' and ship[0].x > 0) {
				clsSheep(m, ship, lenShip, coor);
				moveShip(ship, lenShip, -1, 0);
				isMoowe = true;
			}
			else if (key == 'd' and ship[lenShip - 1].x < fieldSize - 1) {
				clsSheep(m, ship, lenShip, coor);
				moveShip(ship, lenShip, 1, 0);
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
					if (m[ship[j].y][ship[j].x]) {
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
	delAuxiliary(m);
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
		Coordinate* ship = new Coordinate[lenShip];
		do {
			char orientation = rndChar("vh", 2);
			int rnd1 = rand() % fieldSize;
			int rnd2 = rand() % fieldSize;
			for (int j = 0; j < lenShip; j++)
			{
				ship[j].x = rnd1 + ((orientation == 'v') ? j : 0);
				ship[j].y = rnd2 + ((orientation == 'h') ? j : 0);
			}
		} while (!isEmpty(m, ship, lenShip));
		initShip(m, ship, lenShip, { -1,-1 });
	}
	resetColor();
	delAuxiliary(m);
	return m;

}
void moveShip(Coordinate*& ship, int size, int d1, int d2) {
	for (int i = 0; i < size; i++)
	{
		ship[i].x += d1;
		ship[i].y += d2;
	}
}
void clsSheep(int** m, Coordinate*& ship, int size, Coordinate coor) {
	for (int i = 0; i < size; i++)
	{
		numToColor(m[ship[i].y][ship[i].x]);
		setCursorPosition(coor.x + (ship[i].x * 2), coor.y + ship[i].y);
		std::cout << numToCharShip(m[ship[i].y][ship[i].x]);
	}
}
void rotationS(Coordinate* ship, int lenShip, char& orientation) {
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

void initShip(int** m, Coordinate* ship, int lenShip, Coordinate coor) {
	Coordinate ds{ fieldSize , fieldSize }; //координаты начала квадрата ориола корабля
	Coordinate de{ 0,0 }; //координаты конца ориола корабля
	for (int i = 0; i < lenShip; i++)
	{
		m[ship[i].y][ship[i].x] = 1;
		//Определяем крайние точки координат
		if (ds.x > ship[i].x) ds.x = ship[i].x;
		if (de.x < ship[i].x) de.x = ship[i].x;
		if (ds.y > ship[i].y) ds.y = ship[i].y;
		if (de.y < ship[i].y) de.y = ship[i].y;
	}
	//Добавляем отступ к координатам
	ds.x--;	ds.y--;	de.x++;	de.y++;
	int dist = 2; //Это номер ориола
	numToColor(dist);

	for (int y = ds.y; y < de.y + 1; y++) {
		for (int x = ds.x; x < de.x + 1; x++) {
			if (x >= 0 && x < fieldSize && y >= 0 && y < fieldSize && !m[y][x]) {
				m[y][x] = dist;
				if (coor.x == -1) continue;
				setCursorPosition(coor.x + (x * 2), coor.y + y);
				std::cout << skinMiss;

			}
		}
	}
}
bool isEmpty(int** m, Coordinate* ship, int lenShip) {
	//Проверяем в границах ли поля корабль
	if (ship[lenShip - 1].x >= fieldSize or ship[lenShip - 1].y >= fieldSize)
		return false;
	//Проверяем, пусто ли место установки
	for (int j = 0; j < lenShip; j++)
		if (m[ship[j].y][ship[j].x])
			return false;
	return true;
}
void delAuxiliary(int** m) {
	for (int i = 0; i < fieldSize; i++)
		for (int j = 0; j < fieldSize; j++)
			if (m[i][j] == 2)
				m[i][j] = 0;
}

/*-------Прочее--------*/
void clearTable(int** table) {
	for (int i = 0; i < fieldSize; i++)
		delete[] table[i];
	delete table;
	table = nullptr;
}
void numToColor(int num) {
	ColorANSI3b c;
	switch (num) {
	case 0:	setColor(c.BlueBG);	break;
	case 1:	setColor(c.GreenBG); break;
	case 2:	setColor(c.CyanBG); break;
	case 3:	setColor(c.RedBG); break;
	case 4:	setColor(c.GreenBG); break;
	}
}
char rndChar(const char t[], int count) {
	return t[rand() % count];
}
const char* numToCharShip(int num) {
	switch (num)
	{
	case 0:
		return skinSea;
	case 3:
	case 1:
		return skinShip;
	case 2:
		return skinMiss;
	default:
		break;
	}
}


/*-------Игра---------*/
void DelPrioritet(Coordinate*& c, int& numCoors, int numDel) {
	if (!numCoors) return;
	if (numCoors == 1) {
		delete[] c;
		c = nullptr;
		numCoors = 0;
		return;
	}
	//Сдвигаем элементы массива влево, начиная с numDel
	for (int i = numDel; i < numCoors - 1; i++) {
		c[i] = c[i + 1];
	}
	numCoors--;
	/*Нет смыла выделять и перераспределять память,
	 элементов и так не много, проще их за раз все удалить
	Вообще можно было обойтись статическим массивом
	Но уже много чего надо переписывать*/

}
void addElShip(Coordinate* &s, int &c, Coordinate n) {
	Coordinate* newS = new Coordinate[c + 1];
	if (s) {
		for (int i = 0; i < c; i++)
			newS[i] = s[i];
		delete[] s;
	}	
	newS[c] = n;
	s = newS;
	c++;
}
void delClearAndOther(Player& player, Player& opponent, fShip ship) {
	int shift[8][2] = {	{1, 0}, {-1, 0}, {0, -1},{0, 1},{-1, -1},{-1, 1},{1, -1}, {1, 1} };
	for (int sh = 0; sh < ship.count; sh++)
	{
		for (int i = 0; i < 8; i++)
		{
			int x = ship.ch[sh].x + shift[i][0];
			int y = ship.ch[sh].y + shift[i][1];
			if (x < 0 or x >= fieldSize or y < 0 or y >= fieldSize)
				continue;
			int otladka = opponent.map.m[y][x];
			if (!opponent.map.m[y][x]) {//Если клетка пуста
				opponent.map.m[y][x] = 2; //присваивается пустое поле ориола
				//Рисуем окантовку
				numToColor(2);
				setCursorPosition(x * 2 + opponent.map.pos.x + 3, y + opponent.map.pos.y + 1);
				std::cout << numToCharShip(2);
				//Удаляем координату из приоритета плеера
				for (int j = 0; j < player.cPri1; j++)
				{
					if (player.pri1[j].x == x and player.pri1[j].y == y) {
						DelPrioritet(player.pri1, player.cPri1, j);
					}
				}
			}
		}
	}
	
}
fShip isShipDestroyed(int** m, Coordinate cFier) {
	int shift[4][2] = { {1, 0},{-1, 0},{0, -1},{0, 1} };
	Coordinate* ship = nullptr;
	int count = 0;
	addElShip(ship, count, { cFier.x, cFier.y });
	
	//Проверяем 4 направлнеия, для определения положения корабля
	for (int i = 0; i < 4; i++) 
	{
		int x = cFier.x;
		int y = cFier.y;
		while (true)
		{
			x += shift[i][0];
			y += shift[i][1];
			if (x < 0 or x >= fieldSize or y < 0 or y >= fieldSize)
				break;
			if (m[y][x] == 3 or m[y][x] == 1)
				addElShip(ship, count, { x, y });
			else
				break;
		}
	}
	int isDead = true;
	
	fShip result;
	result.ch = ship;
	result.count = count;
	//Определяем уничтожен ли корабль
	for (int i = 0; i < count; i++)
		if (m[ship[i].y][ship[i].x] != 3) {//Если корабль не подбит удаляем координаты
			isDead = false;
			delete[] ship;
			ship = nullptr;
			result.count = 0;
			return result;
		}
	
	
	return result;
}
void showGame(Game& g) {
	showT(g.p1.map.pos, g.p1.map.m);
	if (g.option.humanPlay) 
		showT(g.mapGhost.pos, g.mapGhost.m);
	else
		showT(g.p2.map.pos, g.p2.map.m);
	
}
void delPrioritetAll(Coordinate* &pri, int &count) {
	delete[] pri;
	pri = nullptr;
	count = 0;
}
void fier(Player& player, Player& opponent, Coordinate cFier) {
	int x = opponent.map.pos.x + 3;
	int y = opponent.map.pos.y + 1;
	setCursorPosition(cFier.x * 2 + x, cFier.y + y);
	bool isStrike = opponent.map.m[cFier.y][cFier.x] == 1;
	if (isStrike) { //Если попадание
		
		numToColor(3);
		std::cout << numToCharShip(1);
		opponent.map.m[cFier.y][cFier.x] = 3; //Обозначаем что корабль подбит
		fShip shipStrike = isShipDestroyed(opponent.map.m, cFier);
		if (shipStrike.count) {
			player.ch++;
			delClearAndOther(player, opponent, shipStrike);
		}
	}
	else {
		numToColor(2);
		std::cout << numToCharShip(2);
		opponent.map.m[cFier.y][cFier.x] = 2; //Обозначаем что на клетке промах
	}
}
void stupidBotPlay(Player& player, Player& opponent) {
	int r = rand() % player.cPri1;
	Coordinate randFier = player.pri1[r];
	DelPrioritet(player.pri1, player.cPri1, r);
	fier(player, opponent, randFier);
	
	
	
}
void humanPlay(Player& player, Player& opponent) {
	while (true)
	{
		ColorANSI3b c;
		int num = opponent.map.m[player.aim.y][player.aim.x];
		setCursorPosition(player.aim.x * 2 + opponent.map.pos.x + 3,
			player.aim.y + opponent.map.pos.y + 1);
		num = opponent.map.m[player.aim.y][player.aim.x];
		if (num == 0 or num == 1) {
			setColor(c.GreenBG);
			std::cout << skinSea;
		}
		else {
			setColor(c.RedBG);
			std::cout << numToCharShip(num);
		}

		char key = catchKey();
		if (!key ) continue;
		bool mowe = false;
		Coordinate temp = player.aim;
		
		if (key == 'w' and player.aim.y - 1 != -1) {
			mowe = true;
			player.aim.y--;
		}else if (key == 's' and player.aim.y + 1 < fieldSize) {
			mowe = true;
			player.aim.y++;
		}
		else if (key == 'a' and player.aim.x - 1 != -1) {
			mowe = true;
			player.aim.x--;
		}
		else if (key == 'd' and player.aim.x + 1 < fieldSize) {
			mowe = true;
			player.aim.x++;
		}
		else if (key == 13) {
			int num = opponent.map.m[player.aim.y][player.aim.x];
			if (num == 1 or num == 0) {
				fier(player, opponent, { temp.x, temp.y });
				break;
			}
				
		}
		else if (key == 27) {
			continue;
		}
		
		if (mowe) {
			int num = opponent.map.m[temp.y][temp.x];
			setCursorPosition(temp.x * 2 + opponent.map.pos.x + 3,
				temp.y + opponent.map.pos.y + 1);
			if (num == 0 or num == 1) {
				numToColor(0);
				std::cout << skinSea;
			}
			else {
				numToColor(num);
				std::cout << numToCharShip(num);
			}
			setCursorPosition(player.aim.x * 2 + opponent.map.pos.x + 3,
				player.aim.y + opponent.map.pos.y + 1);
			num = opponent.map.m[player.aim.y][player.aim.x];
			if (num == 0 or num == 1) {
				setColor(c.GreenBG);
				std::cout << skinSea;
			}
			else {
				setColor(c.RedBG);
				std::cout << numToCharShip(num);
			}
		}
			
	}
}
void createPriPlayer(Player& p) {
	p.ch = 0;
	int priSize = fieldSize * fieldSize;//Количество элементов приоритете
	//Очищаем память, если осталась
	if (p.pri1) 	delPrioritetAll(p.pri1, p.cPri1);
	if (p.pri2) 	delPrioritetAll(p.pri2, p.cPri2);
	p.pri2 = new Coordinate[priSize];
	p.cPri2 = priSize;
	p.pri1 = new Coordinate[priSize];
	p.cPri1 = priSize;
	int iter = 0;
	//Разделяем диагонали по приоритетам
	for (int y = 0; y < fieldSize; y++)
		for (int x = 0; x < fieldSize; x++)
			{
				p.pri1[iter] = { x,y };
				iter++;
			}
}
void creatingPlayers(Game& g) {
	createPriPlayer(g.p2);
	if (g.option.difficulty) {
		g.p2.action = stupidBotPlay;
	}
	
	if (g.option.humanPlay) {//Игроку приоритеты не нужны
		g.p1.action = humanPlay;
		return;
	} 

	createPriPlayer(g.p1);
	if (g.option.difficulty) {
		g.p1.action = stupidBotPlay;
	}
	
				
}
void startGame(Game &g) {
	showGame(g);
	creatingPlayers(g);
	int countShip = sizeof(shipSize) / sizeof(shipSize[0]);
	while ( true )
	{
		setCursorPosition(0, 0);
		for (int i = 0; i < fieldSize; i++)
		{
			for (int j = 0; j < fieldSize; j++)
			{
				std::cout << g.p2.map.m[i][j];
			}
			std::cout << std::endl;
		}
		Sleep(100);
		g.p1.action(g.p1, g.p2);
		if (g.p1.ch == countShip) {
			setCursorPosition(g.p1.map.pos.x + fieldSize / 2,
				g.p1.map.pos.y - 2);
			std::cout << ((g.option.humanPlay)?"Победил игрок":"Победил Бот1");
			break;
		}
		
		g.p2.action(g.p2, g.p1);
		if (g.p2.ch == countShip) {
			setCursorPosition(g.p2.map.pos.x + fieldSize / 2,
				g.p2.map.pos.y - 2);
			std::cout << ((g.option.humanPlay) ? "Победил Бот" : "Победил Бот2");
			break;
		}
	}
	setCursorPosition(0,0);
	resetColor();
}