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

struct MyMenu
{
    Coordinate pos;//Стартовые координаты отрисовки меню
    char* Caption = nullptr;//шапка меню
    MyMenu* sub = nullptr;//пункты меню
    int count_sub = 0;//количество пунктов меню
    void (*Action)(MyMenu&, Game&) = nullptr;//действие при выборе данного пунтка меню
    int selected = 0;//текущий пункт меню
    MenuColor color;
};


