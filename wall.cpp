#include "wall.h"
#include"unit.h"
#include"snake.h"
#include<iostream>
using namespace std;
void wall::drawWall() //��ʼ��ǽ��
{
	unit::gotoxy(left, up);
	for (int j = 0; j < COL; j++)
	{
		cout << "-";
	}
	for (int i = 0; i < ROW; i++)
	{
		unit::gotoxy(left, up + 1 + i);
		cout << "|";
		unit::gotoxy(left + COL - 1, up + 1 + i);
		cout << "|";
	}

	unit::gotoxy(Left, Up + ROW + 1);
	for (int k = 0; k < COL; k++)
	{
		cout << "-";
	}

	
	unit::gotoxy(COL + 10, up + 1);
	cout << "��Ϸ���ƣ�̰����";
	unit::gotoxy(COL + 10, up + 2);
	cout << "��д�ߣ�������";
	unit::gotoxy(COL + 10, up + 3);
	cout << "��ǰ�ؿ���1";
	unit::gotoxy(COL+10, up + 5);
	cout << "���Ƽ�����������";
}