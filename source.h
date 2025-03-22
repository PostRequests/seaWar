#pragma once
#include "Game struct.h"
#include "source/menu v2/menuV2.h"


/*---------����---------*/
//������� � ��������� ���� ����� ��� ���� ��������� ����
void menuPause(Game& g, bool pause);
//���������� ������ ���� � ����
Menu1 getMainMenu();
//���������� ���� ����� � ����
Menu1 getOptionMenu();
//���������� �� ���� ���� � ��������� ��������������� ���������
bool getOption(myOption& gOption);
//����� ������ ���� �������, ���������
bool GameModeMenu(Menu1& MO, myOption& gOption);
//����� ����������� ��������
bool shipPos(Menu1& MO, myOption& gOption);
//����� ���������
bool DifficultyLevel(Menu1& MO, myOption& gOption);

/*-------����������� ��������-----*/
//������ �����������
int** manualPlacement(Coordinate coor);
//��������� �����������
int** randPlacement();
//������� ������� � ��������� �����������
void moveShip(Coordinate*& ship, int size, int d1 = 0, int d2 = 0);
//����������� ����� ��� ����� �������, ���������� ������� ���� �� �����
void clsSheep(int** m, Coordinate*& ship, int size, Coordinate coor);
//������������ ������� ��������� ��� ���� � ������ ����
void rotationS(Coordinate* ship, int lenShip, char& orientation);
//��������� �� ����� ������� � ����� �������
void initShip(int** m, Coordinate* ship, int lenShip, Coordinate coor);
//��������, ����� �� ���������� ������� � ��� �����
bool isEmpty(int** m, Coordinate* ship, int lenShip);
//������� ��������������� �������� � ����� (2)
void delAuxiliary(int** m);


/*-------������--------*/
//������� ���������� map
void clearTable(int** table);
//������������� ���� ��������������� ������
void numToColor(int num);
//���������� ��������� ������ �� ��������������� ������� ��������
char rndChar(const char t[], int count);
//���������� ���� ������� ������������ ������
const char* numToCharShip(int num);
// ������� ��� ������������ ������ � MyMap
void cleanupMyMap(MyMap& map);
// ������� ��� ������������ ������ � Player
void cleanupPlayer(Player& player);
// ������� ��� ������������ ������ � Game
void cleanupGame(Game& game);

/*-------����-------*/
//����������� �������������� ���������� ��� �����
void creatingPlayers(Game& g);
//����� ����
void startGame(Game& g);
//������� ��������� ��� �������� �������
void DelPrioritet(Coordinate*& c, int& numCoors, int numDel);
//������� ��������� �� �������� �����������
void DelPrioritet(Coordinate*& c, int& numCoors, Coordinate cotDel);
//��������� ���������� �������� ������� ��� ��������
void addElShip(Coordinate*& s, int& c, Coordinate n);
//������� ������������ �������� �������, ������� ������ � ������ �� �� �����������.
void markAndClearShipPerimeter(Player& player, Player& opponent, Ship ship);
Ship isShipDestroyed(int** m, Coordinate cFier);
//������ ���� �������, � ��������� ������, ������� �������� ���������, ������� �����, �������� �������/�����
void showGame(Game& g);
//������� ��� �������� ����������
void delPrioritetAll(Coordinate*& pri, int& count);
//���������� �������� � ��������� ��� �� ����, ���� ������� ��������, ���������� true
bool fier(Player& player, Player& opponent, Coordinate cFier);
//������� ������ ���� ����������� �������� � ��������� �����
bool stupidBotPlay(Game& g, Player& player, Player& opponent);
//������� ����� ��������� �������� ����
void newPrioritet(Player& player, Player& opponent, Coordinate cFier);
//������� ������ ���� �������� �� ������)
bool botPlay(Game& g, Player& player, Player& opponent);
//������� ������ ����������� ������ ������� �������
bool humanPlay(Game& g, Player& player, Player& opponent);
//�������� �������������� ��������� �������� � ����� ����� �� �����
void createPriPlayer(Player& p);
//������������ ����� �������� �����, ����������� ���������� � ����������� ����� � ������
void creatingPlayers(Game& g);