#include "art.h"
#include "../../Game struct.h"
//#include "../../source.h"
#include <iostream>
#include <Windows.h>


void printSheep(Coordinate coordinate) {
    system("chcp 866>null");
    ColorANSI3b col;
    char sheep[][50] = {
         "***************##***************",
         "**************####**************",
         "**************####**************",
         "*****======================*****",
         "*****##******************##*****",
         "*****##==**==**==**==**==##*****",
         "*******.#**##**##**##**#.*******",
         "********#**************#********",
         "********.*===##**##===*.********",
         "****===########**########===****",
         "***############**####.#######***",
         "****###########**###=*=#####****",
         "*****##########**##.#*#.###*****",
         "******#########**###===###******",
         "*******########**########*******",
         "*******.***.##.**.##.***.*******",
         "==###===###====##====###===###==",
         "................................"
    };
    setColor(col.BlackFG, col.WhiteBG);
    int rows = sizeof(sheep) / sizeof(sheep[0]);
    setCursorPosition(coordinate);
    for (int i = 0; i < rows; i++)
    {
        for (int p = 0; sheep[i][p] != '\0'; p++) {
            if (sheep[i][p] == '*') sheep[i][p] = 178;
            if (sheep[i][p] == '#') sheep[i][p] = 219;
            if (sheep[i][p] == '=') sheep[i][p] = 220;
            if (sheep[i][p] == '.') sheep[i][p] = 223;
            std::cout << sheep[i][p];
        }
        setCursorPosition(coordinate.x, ++coordinate.y);
    }
    resetColor();
    system("chcp 1251>null");
}
void printLog(Coordinate coordinate) {
    system("chcp 866>null");
    char logo[6][60]{
      {176, 219, 219, 219, 219, 219, 219, 187, 219, 219,
      219, 219, 219, 219, 219, 187, 176, 219, 219, 219, 219, 219,
      187, 176, ' ', ' ', 176, 219, 219, 187, 176, 176, 176, 176,
      176, 176, 176, 219, 219, 187, 176, 219, 219, 219, 219, 219,
      187, 176, 219, 219, 219, 219, 219, 219, 187, 176, '\n', '\0'
  },
      {219, 219, 201, 205, 205, 205, 205, 188, 219,
      219, 201, 205, 205, 205, 205, 188, 219, 219, 201, 205, 205,
      219, 219, 187, ' ', ' ', 176, 219, 219, 186, 176, 176, 219,
      219, 187, 176, 176, 219, 219, 186, 219, 219, 201, 205, 205,
      219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, '\n', '\0'
  },
      {200, 219, 219, 219, 219, 219, 187, 176, 219, 219, 219, 219,
      219, 187, 176, 176, 219, 219, 219, 219, 219, 219, 219, 186,
      ' ', ' ', 176, 200, 219, 219, 187, 219, 219, 219, 219, 187,
      219, 219, 201, 188, 219, 219, 219, 219, 219, 219, 219, 186,
      219, 219, 219, 219, 219, 219, 201, 188, '\n', '\0'

  },
      {176, 200, 205, 205, 205, 219, 219, 187, 219, 219, 201, 205,
      205, 188, 176, 176, 219, 219, 201, 205, 205, 219, 219, 186,
      ' ', ' ', 176, 176, 219, 219, 219, 219, 201, 205, 219, 219,
      219, 219, 186, 176, 219, 219, 201, 205, 205, 219, 219, 186,
      219, 219, 201, 205, 205, 219, 219, 187, '\n' ,'\0'
  },
      {219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 219, 219,
      219, 219, 219, 187, 219, 219, 186, 176, 176, 219, 219, 186,
      ' ', ' ', 176, 176, 200, 219, 219, 201, 188, 176, 200, 219,
      219, 201, 188, 176, 219, 219, 186, 176, 176, 219, 219, 186,
      219, 219, 186, 176, 176, 219, 219, 186, '\n', '\0'
  },
      {200, 205, 205, 205, 205, 205, 188, 176, 200, 205, 205, 205,
      205, 205, 205, 188, 200, 205, 188, 176, 176, 200, 205, 188,
      ' ', ' ', 176, 176, 176, 200, 205, 188, 176, 176, 176, 200,
      205, 188, 176, 176, 200, 205, 188, 176, 176, 200, 205, 188,
      200, 205, 188, 176, 176, 200, 205, 188, '\n', '\0'
  } };
    setColor(6);
    int rows = sizeof(logo) / sizeof(logo[0]);
    setCursorPosition(coordinate);
    for (int i = 0; i < rows; i++)
    {
        std::cout << logo[i];
        setCursorPosition(coordinate.x, ++coordinate.y);
    }
    resetColor();
    system("chcp 1251>null");
}
void printGameRules(Coordinate coordinate) {
    system("chcp 1251>nul");
    setCursorPosition(coordinate);
    const char * a[]  = {
        "Правила игры «Морской бой»:",
        "----------------------------------------",
        "1. Играют два игрока: человек и компьютер (или два компьютера).",
        "2. Каждый игрок имеет своё поле размером 10x10 клеток.",
        "3. На поле размещаются корабли следующих размеров:",
        "   - 1 корабль на 4 клетки",
        "   - 2 корабля на 3 клетки",
        "   - 3 корабля на 2 клетки",
        "   - 4 корабля на 1 клетку",
        "4. Корабли не могут пересекаться или соприкасаться (включая диагонали).",
        "5. Игроки по очереди делают «выстрелы», называя координаты клетки (например, A1).",
        "6. Если выстрел попадает в корабль, игрок получает право на ещё один выстрел.",
        "7. Если выстрел не попадает в корабль, ход переходит к другому игроку.",
        "8. Цель игры — первым потопить все корабли противника.",
        "----------------------------------------",
        "Удачи в игре!"
    };
    int len = sizeof(a) / sizeof(a[0]);
    int y = coordinate.y;
    for (int i = 0; i < len; i++)
    {
        std::cout << a[i];
        setCursorPosition(coordinate.x, ++y);
    }
    system("pause");
    drawEmptyRectangle(coordinate.x, coordinate.y, 17, 200);
    setCursorPosition(0,0);
}
void printPlacementRulles(Coordinate cp) {
    setCursorPosition(cp);
    std::cout << "Правила размещения кораблей";
    setCursorPosition(cp.x, ++cp.y);
    setCursorPosition(cp.x, ++cp.y);
    std::cout << "Места соприкосновения кораблей: ";
    numToColor(2);
    std::cout<< numToCharShip(2);
    resetColor();
    setCursorPosition(cp.x, ++cp.y);
    std::cout << "Корабль нельзя разместить: ";
    numToColor(3);
    std::cout << numToCharShip(1);
    resetColor();
    setCursorPosition(cp.x, ++cp.y);
    std::cout << "Корабль можно разместить: ";
    numToColor(1);
    std::cout<< numToCharShip(1);
    resetColor();
}
void showT(Coordinate co, int** table) {
    ColorANSI3b color;
    setCursorPosition(co.x + 3, co.y);
    //std::cout << "  А Б В Г Д Е Ж З И К"; //ToDo
    for (int i = 0; i < fieldSize; i++)
        std::cout << " " << char('А' + i);
    //std::cout << "  0 1 2 3 4 5 6 7 8 9";
    for (int i = 0; i <= fieldSize-1; i++){
        setCursorPosition(co.x, co.y + i +1 );
        std::cout << i + 1;
    }
    co.x+=3;
    co.y++;
    setCursorPosition(co);
    // Рисуем синие клетки
    setColor(color.BlueBG);
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++) 
            if (!table[i][j] or table[i][j] == 2) {
                setCursorPosition(co.x + (j *2), co.y + i );
                std::cout << skinSea;
            }
    //Рисуем зеленые клетки 
    setColor(color.GreenBG);
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++) 
            if (table[i][j] == 1) {
                setCursorPosition(co.x + (j * 2), co.y + i);
                std::cout << skinShip;
            }
        
    resetColor();
    setCursorPosition({ 0,0 });
}
