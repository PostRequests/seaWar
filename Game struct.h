#pragma once
struct myOption {//����� ����
	bool humanPlay = false;//true - ������� � ���������; false - ��������� � ���������.
	bool shipPos = false;//true - ����� ����������� �������; false - ��������� ����������� �� ������.
	bool difficulty = true;//true - ��������� �������; false - ���������������� ����. ��������� ������ ��������� ����, � �� �������� ��������.
};
const int fieldSize = 10; //������ ���� (10x10)
const int shipSize[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; //������� �������� 

const char skinSea[] = "..";
const char skinShip[] = "[]";
const char skinToDo[] = "**";
//������� �������� �������
struct eShip {
	int x;
	int y;
};

struct fShip {
	eShip* ch;
	int count;
};
struct MyMap {
	int** m = nullptr;//����� ����
	Coordinate pos;//���������� ��������� �����
};
struct Game;
struct Player {
	void (*action)(Player& player, Player& opponent);
	Coordinate* pri1 = nullptr;//������� ���������� 1
	int cPri1 = 0; //���������� ����������� 1
	Coordinate* pri2 = nullptr;//������� ���������� 2
	int cPri2 = 0;//���������� ����������� 2
	MyMap map;//�����
	int ch = 0;//���������� �������� ��������
};

struct Game {
	MyMap mapGhost;//������ �����
	myOption option;//����� ����
	Player p1;//����� ��� ���, ��� ��������������
	Player p2;//��� � ��� �����������
};