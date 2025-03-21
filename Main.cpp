﻿#include "git hub/git.h"
#include "source/art/art.h"
#include "source/console/console.h"
#include "source/menu/menu.h"
#include "source/menu v2/menuV2.h"
#include "source.h"
#include "Game struct.h"
#include <iostream>

void main2();

int main()
{
    //
    gitPush("Готово к экзамену");
    /*Game g;
    menuPause(g);*/
    srand(time(0));
    system("chcp 1251 > null");
   main2();
   
}

void main2() {
    FullScreenMode();
    system("cls");
    myOption opt;
    Game g;
    Coordinate CS = getConsoleSize();
    draws();
    Coordinate cLog = { CS.x / 2 - 25, 1 };
    
    Menu1 main = getMainMenu();
    while (true)
    {
        int in = getShowMenu(main);
        if (in == 0)
            if (getOption(opt)) { //Заканчиваем цикл опций?
                break;
            }
        if (in == 1) {
            Coordinate c = { CS.x / 2 - 35, cLog.y + 8};
            printGameRules(c);
        }
        if (in == 2)
            exit(0);
    }
    int** map1;
    int** map2;
    if (opt.shipPos) {
        printPlacementRulles({CS.x / 2 - 10, 16 + fieldSize});
        map1 = manualPlacement({ CS.x / 2 - fieldSize / 2 - 3, 12 });
        drawEmptyRectangle({ CS.x / 2 - 10, 16 + fieldSize }, { CS.x / 2 + 25, 16 + fieldSize + 6 }, 0);
    }
    else 
        map1 = randPlacement();
    map2 = randPlacement();
    /*Переносим все опции в игру*/
    Coordinate m1{ CS.x / 2 - fieldSize * 2 - 7, CS.y / 2 - fieldSize }; //Координаты поля слева
    Coordinate m2{ CS.x / 2 + fieldSize, CS.y / 2 - fieldSize }; //Координаты поля справа
    g.option = opt;
    g.p1.map.m = map1;
    g.p1.map.pos = {m1};
    g.p2.map.m = map2;
    g.p2.map.pos = { m2 };
    if (g.option.humanPlay) {//Если играет человек, заполняем пустую карту для стрельбы
        int** map3 = new int* [fieldSize];
        for (int i = 0; i < fieldSize; ++i)
            map3[i] = new int[fieldSize] {0};
        g.mapGhost.m = map3;
        g.mapGhost.pos = m2;
        
    }
    clearMenu(main);
    startGame(g);
}



