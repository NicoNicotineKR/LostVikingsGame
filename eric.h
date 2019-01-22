#pragma once
#include "characterInfo.h"

enum {

};

class eric : public characterInfo
{
private:
	float _accel;
	bool _isBreath;
	bool _isJumping;
	bool _isMoving;
//	bool _isWall;
	bool _isWallAni;
	bool _isStuning;
	bool _isRoof; //���� ��Ҵ���



	// �ܽ�Ʈ ����

	const POINTFLOAT BEGIN_POS = { WINSIZEX / 2, WINSIZEY / 2 - 100 };
	const float ACCEL_VALUE = 0.4f;
	const float MIN_SPEED = 0;
	const float MAX_SPEED = 5.0f;
	const float JUMP_POWER = -8.0f;
	const float GRAVITY = 0.15f;
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
	void onLadderMotionStart();

	//�������ִ°�
	void ericRightStun();
	void ericLeftStun();



	static void rightMoving(void* obj);
	static void leftMoving(void* obj);
	static void rightStanding(void* obj);
	static void leftStanding (void* obj);
	static void rightStuning(void* obj);
	static void leftStuning(void* obj);
	static void rightFlying(void* obj);
	static void leftFlying(void* obj);

	//������

	

	

};

