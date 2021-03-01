#include "unit.h"
#include <windows.h>
unit::unit(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}

unit::~unit()
{
}

void unit::show()
{
	gotoxy(m_iX, m_iY);
	cout << m_cPic;
}

void unit::erase()
{
	gotoxy(m_iX, m_iY);
	cout << " ";
}

void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);//�½���� screen
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;//����û������� COORD postion����ôpostion��ʵ��һ���ṹ�������
	position.Y = y;//����X��Y�����ĳ�Ա��ͨ���޸�postion.X��postion.Y��ֵ�Ϳ���ʵ�ֹ���λ�ÿ��ơ�
	//���ع��
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;// ���û��ֵ�Ļ������ع����Ч
	SetConsoleCursorInfo(screen, &cinfo);
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);//SetConsoleCursorPosition��API�ж�λ���λ�õĺ���
}