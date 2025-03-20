#include "../console/console.h"
#include "../../Game struct.h"
#include "menuV2.h"
#include <iostream>
#include <string>
#include <windows.h>

void CreateMenu(MyMenu& menu, const char* cap, Coordinate pos){
    if (menu.sub)
        delete[]menu.sub;
    menu.count_sub = 0;
    menu.sub = nullptr;
    menu.Action = nullptr;
    menu.selected = -1;
    if (menu.Caption)
        delete[]menu.Caption;
    menu.Caption = new char[strlen(cap) + 1];
    strcpy_s(menu.Caption, strlen(cap) + 1, cap);
    menu.pos = pos;
}

void AddItemMenu(MyMenu& menu, const char* cap, void (*Action)(MyMenu&, Game& g))
{
    MyMenu* nsub = new MyMenu[menu.count_sub + 1];
    for (int i = 0; i < menu.count_sub; i++)
    {
        nsub[i] = menu.sub[i];
    }
    nsub[menu.count_sub].Caption = new char[strlen(cap) + 1];
    strcpy_s(nsub[menu.count_sub].Caption, strlen(cap) + 1, cap);
    nsub[menu.count_sub].Action = Action;
    if (menu.sub)
        delete[] menu.sub;
    menu.sub = nsub;
    menu.count_sub++;
    menu.selected = 0;
}
int MaxLen(MyMenu& menu)
{
    int r = strlen(menu.Caption);
    for (int i = 0; i < menu.count_sub; i++)
    {
        r = max(r, (int)strlen(menu.sub[i].Caption));
    }
    return r;
}

void drawMenu(MyMenu& menu) {
    
    BorderCP866 bord;
    setCursorPosition(menu.pos);
    Coordinate tmp = menu.pos;
    int width = MaxLen(menu) + 2;
    drawFillRectangle(menu.pos, { menu.pos.x + width + 1, menu.pos.y + menu.count_sub * 2 + 1 });
    setCursorPosition(++tmp.x, ++tmp.y);
    system("chcp 1251>nul");
    std::cout << menu.Caption;
    system("chcp 866>nul");
    printRowChars(width, bord.H2);
    for (int  i = 0; i < menu.count_sub; i++)
    {
        system("chcp 1251>nul");
        std::cout << menu.sub[i].Caption;
        system("chcp 866>nul");
        printRowChars(width, bord.H2);
    }
}