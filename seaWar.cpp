
#include "source/art/art.h"
#include "source/console/console.h"
#include "source/menu/menu.h"
#include "source.h"
#include "Game struct.h"
#include <iostream>

void main2();

int main()
{
    system("pause>null");
    main2();
   
}

void main2() {
    FullScreenMode();
    myOption opt;
    Coordinate CS = getConsoleSize();
    Coordinate cLog = { CS.x / 2 - 25, 1 };
    printLog(cLog);
    
    printSheep({ CS.x / 2 - 16, CS.y - 17 });
    Menu main = getMainMenu();

    while (true)
    {
        int in = getShowMenu(main);
        if (in == 0)
            if (getOption(opt)) //Заканчиваем цикл опций?
                break;
        if (in == 1) {
            Coordinate c = { CS.x / 2 - 25, cLog.y + 8};
            printGameRules(c);
        }
        if (in == 2)
            break;
    }

    
}



