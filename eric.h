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
	bool _isRoof; //지붕 닿았는지



	// 콘스트 변수

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

	void move();			//움직임 연산
	void imageInit();		//에릭 이미지 + 키애니메이션 이미지 초기화
	void IdleMotion();		//가만히 있을때 특수행동 모션
	void isNotPlaying();		// 얘가 플레이 중이 아닐때 idle로 변경해주는거
	void onLadderMotionStart();

	//스턴해주는거
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

	//접근자

	

	

};

