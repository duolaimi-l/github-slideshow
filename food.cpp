#include "food.h"
#include"wall.h"
#include"snake.h"
#include <cstdlib>
#include <ctime>
food::food(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}
food::~food()
{
}
void food::createpos()
{
	srand((int)time(0));//srand()��������rand()���������ʱ����������ӡ� 
	//�ڵ���rand()�������������ǰ������������srand()�����������ӣ�seed��,
	//���δ�����������,rand()�������������ֵ��һ��
	m_iX = wall::left + 1 + rand() % (wall::COL - 2);//��[3,73]֮�������
	m_iY = wall::up + 1 + rand() % (wall::ROW - 2);//��[2,23]֮�������
}
