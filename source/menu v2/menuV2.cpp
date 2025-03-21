#include "../console/console.h"
#include "../../Game struct.h"
#include "menuV2.h"
#include <iostream>
#include <string>
#include <windows.h>

void redrawItemMenu(int c_sub_last, Menu& m) {
    ColorANSI3b c;
    int x = m.pos.x + 1;
    int y = m.pos.y + 4;
    setCursorPosition(x + m.width / 2 - strlen(m.sub[m.selected].Caption) / 2, y + c_sub_last * 2 - 1);
    resetColor();
    std::cout << m.sub[c_sub_last].Caption;
    setColor(c.BlueBG);
    setCursorPosition(x + m.width / 2 - strlen(m.sub[m.selected].Caption) / 2, y + m.selected * 2 - 1);
    std::cout << m.sub[m.selected].Caption;
    resetColor();
}

void StartMenu(Menu& menu, Game& g)
{
    drawMenu(menu);
    do
    {
        char key = catchKey();
        int tempSub = menu.selected;
        switch (key)
        { 
        case 'w'://up
            ((!menu.selected)? menu.selected = menu.count_sub - 1:menu.selected--);
            redrawItemMenu(tempSub, menu);
            break;
        case 's'://down
            ((menu.selected == menu.count_sub - 1)? menu.selected = 0: menu.selected++);
            redrawItemMenu(tempSub, menu);
            break;
        case 13:
            menu.sub[menu.selected].Action(menu.sub[menu.selected], g);
            break;
        }
    } while (true);
}
void CreateMenu(Menu& menu, const char* cap, Coordinate pos){
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

void AddItemMenu(Menu& menu, const char* cap, void (*Action)(Menu&, Game& g))
{
    Menu* nsub = new Menu[menu.count_sub + 1];
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
    menu.width = MaxLen(menu) + 2;
}
int MaxLen(Menu& menu)
{
    int r = strlen(menu.Caption);
    for (int i = 0; i < menu.count_sub; i++)
    {
        r = max(r, (int)strlen(menu.sub[i].Caption));
    }
    return r;
}

void drawMenu(Menu& menu) {
    
    BorderCP866 bord;
    ColorANSI3b col;
    setCursorPosition(menu.pos);
    Coordinate tmp = menu.pos;
    drawFillRectangle(menu.pos, { menu.pos.x + menu.width + 1, menu.pos.y + menu.count_sub * 2 + 2 });
    setCursorPosition(++tmp.x + menu.width /2 - strlen(menu.Caption) / 2, ++tmp.y);
    system("chcp 1251>nul");
    std::cout << menu.Caption;
    system("chcp 866>nul");
    setCursorPosition(tmp.x, ++tmp.y);
    printRowChars(menu.width, bord.H2);
    for (int  i = 0; i < menu.count_sub; i++)
    {
        system("chcp 1251>nul");
        if (i == menu.selected) setColor(col.BlueBG);
        setCursorPosition(tmp.x + menu.width / 2 - strlen(menu.sub[i].Caption) / 2, ++tmp.y);
        std::cout << menu.sub[i].Caption;
        if (i == menu.selected) resetColor();
        setCursorPosition(tmp.x, ++tmp.y);
    }
}