#pragma once
#include "Game struct.h"


/*---------����---------*/
//���������� ������ ���� � ����
Menu getMainMenu();
//���������� ���� ����� � ����
Menu getOptionMenu();
//���������� �� ���� ���� � ��������� ��������������� ���������
bool getOption(myOption& gOption);
//����� ������ ���� �������, ���������
bool GameModeMenu(Menu& MO, myOption& gOption);
//����� ����������� ��������
bool shipPos(Menu& MO, myOption& gOption);
//����� ���������
bool DifficultyLevel(Menu& MO, myOption& gOption);

/*-------����������� ��������-----*/
//������ �����������
int** manualPlacement(Coordinate coor);
//��������� �����������
int** randPlacement();
//������� ������� � ��������� �����������
void moveShip(eShip*& ship, int size, int d1 = 0, int d2 = 0);
//����������� ����� ��� ����� �������, ���������� ������� ���� �� �����
void clsSheep(int** m, eShip*& ship, int size, Coordinate coor);
//������������ ������� ��������� ��� ���� � ������ ����
void rotationS(eShip* ship, int lenShip, char& orientation);
//��������� �� ����� ������� � ����� �������
void initShip(int** m, eShip* ship, int lenShip, Coordinate coor);
//��������, ����� �� ���������� ������� � ��� �����
bool isEmpty(int** m, eShip* ship, int lenShip);
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


/*-------����-------*/
//����������� �������������� ���������� ��� �����
void creatingPlayers(Game& g);
void startGame(Game& g);