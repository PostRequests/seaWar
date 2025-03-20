#pragma once
#include "../console/console.h"
//+-------------------------------------------------+
//|Не работает без подключения                      |
//|#include "../console/console.h"                  |
//|В основном файле                                 |
//+-------------------------------------------------+

//Цветовая палитра меню (BG,FG,borderFG,hiBG,hiFG )
struct menuColor1 {
    int BG; //Цвет фона элементов меню
    int FG; //Цвет текста элемента меню
    int borderFG; //Цвет окантовки меню
    int hiBG; //Цвет выделенного фона элемента меню
    int hiFG; //Цвет выделенного текста элемента меню
};

//Информационный текст элементов меню
struct Info1 {
    Coordinate start;//Координаты начала места печати
    Coordinate finish;//Координаты конца места печати
    int width; //Полезная ширина вывода текста
    int height;//Полезная высота вывода текста+
    char** text; //Текст текст информации по элементу меню
    bool border;//Окантовка
    bool enable = false;//Существует ли объект
    bool visible = false; //Видим на экране
    menuColor1 color;//Цветовая палитра 
};

struct Head1 {
    Coordinate start;//Координаты начала места печати
    Coordinate finish;//Координаты конца места печати
    char* text = nullptr;
    int inTop;//Отступ сверху
    int inLeft;//Отступ слева
    int inDown;//Отступ снизу
    int inRight;//Отступ справа
    int width; //Ширина окна
    int height;//Высота окна
    bool border;//Окантовка меню
    bool enable = false;//Видимость
    bool visible = false; //Видим на экране
    menuColor1 color;//Цветовая палитра 

};

//Меню
struct Menu1 {
    Coordinate start;//Координаты начала места печати меню
    Coordinate finish;//Координаты конца места печати меню
    char** item = nullptr;//Элементы меню
    int count; //Количество элементов в меню
    int n; //Номер выбранного элемента меню
    menuColor1 color;//Цветовая палитра меню
    int lineSkip; //Количество пропущенных строк между элементами меню
    int width; //Ширина меню
    int height;//Высота меню
    bool border;//Окантовка меню
    bool visible = false; //Видим на экране

    /*Не обязательные параметры, задаются отдельно*/
    Head1 head; //Шапка меню

    Info1 info; //Элементы информации меню
};

/// <summary>
/// Анимирует перемещение по меню
/// </summary>
/// <param name="m">Структура меню</param>
/// <param name="closeEnd">Закрывать после выбора элемента меню? True по умолчанию закрывать</param>
/// <returns>Возвращает номер элемента выбранного пункта меню</returns>
int getShowMenu(Menu1 &m, bool closeEnd = true);
/// <summary>
/// Очищает указатели в меню. Не требует очищения без выделения памяти.
/// </summary>
/// <param name="m">Структура меню</param>
void clearMenu(Menu1& m);
/// <summary>
/// В первую очередь заполняем элементы меню
/// </summary>
/// <param name="m">Структура меню</param>
/// <param name="start">Стартовые координаты, где будет начинать рисоваться меню</param>
/// <param name="item">Элементы меню, массив из строк, где каждая строка элемент меню</param>
/// <param name="count">Количество элементов меню(Размер массива item)</param>
/// <param name="color">Цветовая палитра меню (BG,FG,borderFG,hiBG,hiFG )</param>
/// <param name="lineSkip">Расстояние между элементами</param>
/// <param name="place">l - по левому краю r - по правому краю c - по центру</param>
/// <param name="border">Наличие окантовки вокруг меню</param>
void constructMenu(Menu1 &m, Coordinate start, const char** item, int count, menuColor1 color, int lineSkip = 1, char place = 'l', bool border = false);
/// <summary>
/// Добавляет заголовок меню (Не обязательно)
/// </summary>
/// <param name="m">Структура уже ранее созданного меню</param>
/// <param name="start">Стартовая позиция отрисовки головы меню</param>
/// <param name="head">Название меню</param>
/// <param name="margin">Отступы [Сверху, Слева, Снизу, Справа]</param>
/// <param name="border">Наличие окантовки</param>
/// <param name="color">Цветовая палитра (BG,FG,borderFG,hiBG,hiFG)</param>
void addHeadMenu(Menu1& m, Coordinate start, char* head, int margin[4], bool border, menuColor1 color = { 0 });
/// <summary>
/// Добавляет информацию об элементах меню (Не обязательно)
/// </summary>
/// <param name="m">Структура меню</param>
/// <param name="start">Стартовая позиция отрисовки меню</param>
/// <param name="finish">Нижний правый угол отрисовки меню</param>
/// <param name="textInfo">Массив из элементов меню</param>
/// <param name="border">Наличие окантовки</param>
/// <param name="color">Цветовая палитра (BG,FG,borderFG,hiBG,hiFG)</param>
void addInfoMenu(Menu1& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor1 color = { 0 });
//Очищает с экрана содержание меню
void clsMenu(Menu1 &m);
//Очищает с экрана содержание заголовка
void clsHead(Menu1 &m);
//Очищает с экрана содержание информации элементов меню
void clsInfo(Menu1 &m);
//Рисует заголовок меню
void showHeadMenu(Head1 h);
void reConstructMenu(Menu1& m, const char** item, int count,  const char* header = 0, const char place = 'c');
