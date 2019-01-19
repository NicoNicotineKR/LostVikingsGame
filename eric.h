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


	// 콘스트 변수

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

	void move();			//움직임 연산
	void imageInit();		//에릭 이미지 + 키애니메이션 이미지 초기화
	void IdleMotion();		//가만히 있을때 특수행동 모션
	void isNotPlaying();		// 얘가 플레이 중이 아닐때 idle로 변경해주는거


	static void rightMoving(void* obj);
	static void leftMoving(void* obj);
	static void rightStanding(void* obj);
	static void leftStanding (void* obj);
	static void rightStuning(void* obj);
	static void leftStuning(void* obj);
	static void rightFlying(void* obj);
	static void leftFlying(void* obj);

	//플레이어 상태 접근자, 설정자
	
	

	//플레이어 애니메이션 접근자, 설정자

};

