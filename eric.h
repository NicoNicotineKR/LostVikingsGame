#pragma once
#include "characterInfo.h"

enum {

};

class eric : public characterInfo
{
private:
	float _accel;
	bool _isBreath;
	bool _isRushing;
	bool _isGround;
	bool _isJumping;
	bool _isMoving;


	// �ܽ�Ʈ ����

	const POINTFLOAT BEGIN_POS = { WINSIZEX / 2, WINSIZEY / 2 };
	const float ACCEL_VALUE = 0.05f;
	const float MIN_SPEED = 0;
	const float MAX_SPEED = 4.0f;
	const float JUMP_POWER = -10.0f;
	const float GRAVITY = 0.2f;
public:
	eric();
	~eric();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();			//������ ����
	void imageInit();		//���� �̹��� + Ű�ִϸ��̼� �̹��� �ʱ�ȭ
	void IdleMotion();		//������ ������ Ư���ൿ ���
	void isNotPlaying();		// �갡 �÷��� ���� �ƴҶ� idle�� �������ִ°�


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

