#pragma once
#include "characterInfo.h"

enum {

};

class eric : public characterInfo
{
private:
	float _accel;
	float _jumpPower;
	bool _isBreath;


	// �ܽ�Ʈ ����

	const POINTFLOAT BEGIN_POS = { WINSIZEX / 2, WINSIZEY / 2 };
	const float ACCEL_VALUE = 0.05f;
	const float MIN_SPEED = 0;
	const float MAX_SPEED = 6.0f;
public:
	eric();
	~eric();

	HRESULT init();
	void release();
	void update();
	void render();

	void imageInit();
	void move();

	static void rightMoving(void* obj);
	static void leftMoving(void* obj);
	static void rightStanding(void* obj);
	static void leftStanding (void* obj);
	static void rightStuning(void* obj);
	static void leftStuning(void* obj);
	static void rightFlying(void* obj);
	static void leftFlying(void* obj);

	//�÷��̾� ���� ������, ������
	
	

	//�÷��̾� �ִϸ��̼� ������, ������

};

