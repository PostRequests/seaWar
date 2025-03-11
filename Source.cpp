#include "source/console/console.h"
#include "source/menu/menu.h"
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
bool getOption(myOption &gOption) {
	Menu MO = getOptionMenu();
	Coordinate CS = getConsoleSize();
	while (true)
	{
		const char* a[] = { "Человек – компьютер",
		"Компьютер – компьютер",
		"Назад", };
		MO.start.x = CS.x / 2 - MO.width / 2;
		reConstructMenu(MO, a, 3, "     Режимы игры     ");
		
		int in = getShowMenu(MO);
		if (in == 2) break;
		gOption.humanPlay = !in;
		
		while (true)
		{
			const char* a[] = { "Игрок расставляет вручную", "Компьютер расставляет за игрока", "Назад" };
			MO.start.x = CS.x / 2 - MO.width / 2 - 5;
			reConstructMenu(MO, a, 3, "     Расстановка кораблей:     ");
			
			int in = getShowMenu(MO);
			if (in == 2) break;
			gOption.shipPos = in;
			
			while (true)
			{
				const char* a[] = { "   Легко  ", "Средне", "Назад" };
				MO.start.x = CS.x / 2 - MO.width / 2 + 10;
				reConstructMenu(MO, a, 3, "Сложность:");
				
				int in = getShowMenu(MO);
				if (in == 2) break;
				gOption.difficulty = in;
				std::cout << "humanPlay " << gOption.humanPlay << " shipPos " << gOption.shipPos << " shipPos " << gOption.difficulty;
				return true; //Опции выбраны
			}
		}
	}
	return false; //Опции не заполнены
	
	
}