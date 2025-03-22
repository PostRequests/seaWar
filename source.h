#pragma once
#include "Game struct.h"
#include "source/menu v2/menuV2.h"


/*---------Меню---------*/
//Создает и запускает меню паузы или меню окончания игры
void menuPause(Game& g, bool pause);
//Генерирует первое меню в игре
Menu1 getMainMenu();
//Генерирует меню опции в игре
Menu1 getOptionMenu();
//Проходится по всем меню и формирует соответствующие настройки
bool getOption(myOption& gOption);
//Выбор режима игры человек, компьютер
bool GameModeMenu(Menu1& MO, myOption& gOption);
//Выбор расстановки кораблей
bool shipPos(Menu1& MO, myOption& gOption);
//Выбор сложности
bool DifficultyLevel(Menu1& MO, myOption& gOption);

/*-------Расстановка кораблей-----*/
//Ручная расстановка
int** manualPlacement(Coordinate coor);
//Случайная расстановка
int** randPlacement();
//Смещает корабль в указанном направлении
void moveShip(Coordinate*& ship, int size, int d1 = 0, int d2 = 0);
//Закрашивает место где стоял корабль, элементами которые были на карте
void clsSheep(int** m, Coordinate*& ship, int size, Coordinate coor);
//Поворачивает корабль оставаясь при этом в рамках поля
void rotationS(Coordinate* ship, int lenShip, char& orientation);
//переносит на карту корабль и ориол корабля
void initShip(int** m, Coordinate* ship, int lenShip, Coordinate coor);
//Проверка, можно ли установить корабль в это место
bool isEmpty(int** m, Coordinate* ship, int lenShip);
//Удаляем вспомогательные элементы с карты (2)
void delAuxiliary(int** m);


/*-------Прочее--------*/
//Очистка указателей map
void clearTable(int** table);
//Устанавливает цвет соответствующий номеру
void numToColor(int num);
//Генерирует случайный символ из представленного массива символов
char rndChar(const char t[], int count);
//Возвращает скин корабля относительно номера
const char* numToCharShip(int num);
// Функция для освобождения памяти в MyMap
void cleanupMyMap(MyMap& map);
// Функция для освобождения памяти в Player
void cleanupPlayer(Player& player);
// Функция для освобождения памяти в Game
void cleanupGame(Game& game);

/*-------Игра-------*/
//Расставляет первоначальные приоритеты для ботов
void creatingPlayers(Game& g);
//Старт игры
void startGame(Game& g);
//Удаляет приоритет под заданным номером
void DelPrioritet(Coordinate*& c, int& numCoors, int numDel);
//Удаляет приоритет по заданным координатам
void DelPrioritet(Coordinate*& c, int& numCoors, Coordinate cotDel);
//Добавляет координаты элемента корабля для расчетов
void addElShip(Coordinate*& s, int& c, Coordinate n);
//Функция обрабатывает периметр корабля, помечая клетки и удаляя их из приоритетов.
void markAndClearShipPerimeter(Player& player, Player& opponent, Ship ship);
Ship isShipDestroyed(int** m, Coordinate cFier);
//Расует поля игроков, и стартовые данные, сколько кораблей потоплено, сколько ходов, названия игроков/ботов
void showGame(Game& g);
//Удаляет все заданные приоритеты
void delPrioritetAll(Coordinate*& pri, int& count);
//Совершение выстрела и отрисовка его на поле, если выстрел попадает, возвращает true
bool fier(Player& player, Player& opponent, Coordinate cFier);
//Функция задает боту возможность стрелять в случайные места
bool stupidBotPlay(Game& g, Player& player, Player& opponent);
//Создает умный приоритет стрельбы боту
void newPrioritet(Player& player, Player& opponent, Coordinate cFier);
//Функция задает боту стрелять по умному)
bool botPlay(Game& g, Player& player, Player& opponent);
//Функция задает возможность игроку сделать выстрел
bool humanPlay(Game& g, Player& player, Player& opponent);
//Задается второстипенный приоритет стрелять в любое место на карте
void createPriPlayer(Player& p);
//Относительно ранее заданных опций, расставляет приоритеты и возможности ботов и игрока
void creatingPlayers(Game& g);