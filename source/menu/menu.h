#pragma once
#include "../console/console.h"
//+-------------------------------------------------+
//|�� �������� ��� �����������                      |
//|#include "../console/console.h"                  |
//|� �������� �����                                 |
//+-------------------------------------------------+

//�������� ������� ���� (BG,FG,borderFG,hiBG,hiFG )
struct menuColor1 {
    int BG; //���� ���� ��������� ����
    int FG; //���� ������ �������� ����
    int borderFG; //���� ��������� ����
    int hiBG; //���� ����������� ���� �������� ����
    int hiFG; //���� ����������� ������ �������� ����
};

//�������������� ����� ��������� ����
struct Info1 {
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    int width; //�������� ������ ������ ������
    int height;//�������� ������ ������ ������+
    char** text; //����� ����� ���������� �� �������� ����
    bool border;//���������
    bool enable = false;//���������� �� ������
    bool visible = false; //����� �� ������
    menuColor1 color;//�������� ������� 
};

struct Head1 {
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    char* text = nullptr;
    int inTop;//������ ������
    int inLeft;//������ �����
    int inDown;//������ �����
    int inRight;//������ ������
    int width; //������ ����
    int height;//������ ����
    bool border;//��������� ����
    bool enable = false;//���������
    bool visible = false; //����� �� ������
    menuColor1 color;//�������� ������� 

};

//����
struct Menu1 {
    Coordinate start;//���������� ������ ����� ������ ����
    Coordinate finish;//���������� ����� ����� ������ ����
    char** item = nullptr;//�������� ����
    int count; //���������� ��������� � ����
    int n; //����� ���������� �������� ����
    menuColor1 color;//�������� ������� ����
    int lineSkip; //���������� ����������� ����� ����� ���������� ����
    int width; //������ ����
    int height;//������ ����
    bool border;//��������� ����
    bool visible = false; //����� �� ������

    /*�� ������������ ���������, �������� ��������*/
    Head1 head; //����� ����

    Info1 info; //�������� ���������� ����
};

/// <summary>
/// ��������� ����������� �� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="closeEnd">��������� ����� ������ �������� ����? True �� ��������� ���������</param>
/// <returns>���������� ����� �������� ���������� ������ ����</returns>
int getShowMenu(Menu1 &m, bool closeEnd = true);
/// <summary>
/// ������� ��������� � ����. �� ������� �������� ��� ��������� ������.
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(Menu1& m);
/// <summary>
/// � ������ ������� ��������� �������� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="start">��������� ����������, ��� ����� �������� ���������� ����</param>
/// <param name="item">�������� ����, ������ �� �����, ��� ������ ������ ������� ����</param>
/// <param name="count">���������� ��������� ����(������ ������� item)</param>
/// <param name="color">�������� ������� ���� (BG,FG,borderFG,hiBG,hiFG )</param>
/// <param name="lineSkip">���������� ����� ����������</param>
/// <param name="place">l - �� ������ ���� r - �� ������� ���� c - �� ������</param>
/// <param name="border">������� ��������� ������ ����</param>
void constructMenu(Menu1 &m, Coordinate start, const char** item, int count, menuColor1 color, int lineSkip = 1, char place = 'l', bool border = false);
/// <summary>
/// ��������� ��������� ���� (�� �����������)
/// </summary>
/// <param name="m">��������� ��� ����� ���������� ����</param>
/// <param name="start">��������� ������� ��������� ������ ����</param>
/// <param name="head">�������� ����</param>
/// <param name="margin">������� [������, �����, �����, ������]</param>
/// <param name="border">������� ���������</param>
/// <param name="color">�������� ������� (BG,FG,borderFG,hiBG,hiFG)</param>
void addHeadMenu(Menu1& m, Coordinate start, char* head, int margin[4], bool border, menuColor1 color = { 0 });
/// <summary>
/// ��������� ���������� �� ��������� ���� (�� �����������)
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="start">��������� ������� ��������� ����</param>
/// <param name="finish">������ ������ ���� ��������� ����</param>
/// <param name="textInfo">������ �� ��������� ����</param>
/// <param name="border">������� ���������</param>
/// <param name="color">�������� ������� (BG,FG,borderFG,hiBG,hiFG)</param>
void addInfoMenu(Menu1& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor1 color = { 0 });
//������� � ������ ���������� ����
void clsMenu(Menu1 &m);
//������� � ������ ���������� ���������
void clsHead(Menu1 &m);
//������� � ������ ���������� ���������� ��������� ����
void clsInfo(Menu1 &m);
//������ ��������� ����
void showHeadMenu(Head1 h);
void reConstructMenu(Menu1& m, const char** item, int count,  const char* header = 0, const char place = 'c');
