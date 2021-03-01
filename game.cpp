#include "game.h"
#include "conio.h"
#include "wall.h"
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
game::game()
{
	this->m_pFood = new food();
	this->m_pSnake = new snake();
}
game::~game()
{
	delete m_pFood;
	delete m_pSnake;
	m_pFood = NULL;
	m_pSnake = NULL;
}

void game::run()
{
	PlaySound(L"C:\\Users\\yu\\Desktop\\ר��\\snakegame\\̰����.wav", NULL, SND_FILENAME | SND_ASYNC);// \�ַ���ת���ַ�������
	m_pFood->createpos();
	int i;
	for (i = 0; i < m_pSnake->Slenth; i++)
	{
		if (m_pFood ->m_iX == m_pSnake->SheadX &&m_pFood->m_iY == m_pSnake->SheadY)      //���������һ�������غϣ�����������ʳ��
			m_pFood->createpos();
	}
	m_pFood->show();
	m_pSnake->showSnake();
	int key = 1;
	while (1)
	{
		unit::gotoxy(wall::COL + 10, wall::up + 4);
		cout << "��ǰ�÷֣�" << m_pSnake->grade << "��";
		if (_kbhit())//�л�������
		{
			key = _getch();//��ȡ����ֵ,����Ҫ�س�
		}
		//s.move();
		m_pSnake->changedir(key);
		m_pSnake->move();

		if (m_pSnake->eatfood(m_pFood))
		{
			m_pSnake->growup();

			m_pFood->erase();
			m_pFood->createpos();
			m_pFood->show();

			Sleep(m_pSnake->speedup());

		}
		if (m_pSnake->die())
		{
			unit::gotoxy(32, 15);
			cout << "GAME OVER";
			break;
		}
		else
			continue;
	}
}
