#pragma once

//+-------------------------------------------------+
//|Не работает без подключения                      |
//|#include "../console/console.h"                  |
//|В основном файле                                 |
//+-------------------------------------------------+

//Цветовая палитра меню (BG,FG,borderFG,hiBG,hiFG )
struct MenuColor {
    int BG; //Цвет фона элементов меню
    int FG; //Цвет текста элемента меню
    int borderFG; //Цвет окантовки меню
    int hiBG; //Цвет выделенного фона элемента меню
    int hiFG; //Цвет выделенного текста элемента меню
};

struct Menu
{
    Coordinate pos;//Стартовые координаты отрисовки меню
    char* Caption = nullptr;//шапка меню
    Menu* sub = nullptr;//пункты меню
    int count_sub = 0;//количество пунктов меню
    void (*Action)(Menu&, Game&) = nullptr;//действие при выборе данного пункта меню
    int selected = 0;//текущий пункт меню
    int width;
    Game* g;
};


void CreateMenu(Menu& menu, const char* cap, Coordinate pos);
void AddItemMenu(Menu& menu, const char* cap, void (*Action)(Menu&, Game& ));
int MaxLen(Menu& menu);
void drawMenu(Menu& menu);
void StartMenu(Menu& menu, Game& g);