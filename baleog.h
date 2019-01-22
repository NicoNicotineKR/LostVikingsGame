#pragma once
#include "characterInfo.h"


class baleog : public characterInfo
{
private:

	POINTFLOAT _fallStartPos;


	bool _isFlyMotion;

	bool _isLeftMove;
	bool _isRightMove;
	bool _isFire;


	POINTFLOAT _arrowPos;
	POINTFLOAT _arrowStartPos;
	bool _isArrowDirection;
	image* _arowImg[2];
public:
	baleog();
	~baleog();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();

	void olafKeyInput();
	void arrowFire();
	void arrowMove(bool isArrowDirection);

	void idleMotionStart(string direction);
	void moveMotionStart(string direction);
	void fallMotionStart(string direction);
	void onLadderMotionStart();
	void swordAttackMotionStart(string direction);
	void bowAttackMotionStart(string direction);

	static void rightIdle(void* obj);
	static void leftIdle(void* obj);
	static void hitDead(void* obj);

	//RECT getArrowRc() { return _arrowRc; }
};

