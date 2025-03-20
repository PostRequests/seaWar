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

struct MyMenu
{
    Coordinate pos;//��������� ���������� ��������� ����
    char* Caption = nullptr;//����� ����
    MyMenu* sub = nullptr;//������ ����
    int count_sub = 0;//���������� ������� ����
    void (*Action)(MyMenu&, Game&) = nullptr;//�������� ��� ������ ������� ������ ����
    int selected = 0;//������� ����� ����
    MenuColor color;
};


