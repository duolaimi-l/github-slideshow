#pragma once

class wall
{
public:
	enum
	{
		ROW = 25, //������y����
		COL = 75,//������x����
		up = 1,//�ϱ߽�
		left = 2//��߽�
	};
	//����ǽ��
public:
	void drawWall();
};