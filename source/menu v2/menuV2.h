#pragma once

//+-------------------------------------------------+
//|�� �������� ��� �����������                      |
//|#include "../console/console.h"                  |
//|� �������� �����                                 |
//+-------------------------------------------------+

//�������� ������� ���� (BG,FG,borderFG,hiBG,hiFG )
struct MenuColor {
    int BG; //���� ���� ��������� ����
    int FG; //���� ������ �������� ����
    int borderFG; //���� ��������� ����
    int hiBG; //���� ����������� ���� �������� ����
    int hiFG; //���� ����������� ������ �������� ����
};

struct Menu
{
    Coordinate pos;//��������� ���������� ��������� ����
    char* Caption = nullptr;//����� ����
    Menu* sub = nullptr;//������ ����
    int count_sub = 0;//���������� ������� ����
    void (*Action)(Menu&, Game&) = nullptr;//�������� ��� ������ ������� ������ ����
    int selected = 0;//������� ����� ����
    int width;
    Game* g;
};


void CreateMenu(Menu& menu, const char* cap, Coordinate pos);
void AddItemMenu(Menu& menu, const char* cap, void (*Action)(Menu&, Game& ));
int MaxLen(Menu& menu);
void drawMenu(Menu& menu);
void StartMenu(Menu& menu, Game& g);