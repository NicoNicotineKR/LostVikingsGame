#pragma once
#include "objects.h"

enum stateObject
{
	LOCATION_X = 3392,
	LOCATION_Y = 444,
};

class object1 : public objects // ��������������
{
private:
	//�׸���ȯ��
	int Num;
	
	//���ν���
	bool mainActivate;

	//�����
	bool activate;
	int activateCount;

public:
	object1();
	~object1();

	HRESULT init();
	void update();
	void release();
	void render();

	//�����
	void setMainActivate(bool v){ mainActivate = v ;}
	//�̰Ǿ��������ƴѵ�?
};

