#pragma once
struct myOption {//����� ����
	bool humanPlay;//true - ������� � ���������; false - ��������� � ���������.
	bool shipPos;//true - ����� ����������� �������; false - ��������� ����������� �� ������.
	bool difficulty;//true - ��������� �������; false - ���������������� ����. ��������� ������ ��������� ����, � �� �������� ��������.
};
const int fieldSize = 10; //������ ���� (10x10)
const int shipSize[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; //������� �������� 
const char skinSea[] = "..";
const char skinShip[] = "[]";
const char skinToDo[] = "**";
struct cShip {
	int x;
	int y;
};