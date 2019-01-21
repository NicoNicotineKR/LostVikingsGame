#pragma once
#include "characterInfo.h"


class baleog : public characterInfo
{
private:

	POINTFLOAT _fallStartPos;

	bool _isGround;
	bool _isWall;

	bool _isFlyMotion;

	bool _isLeftMove;
	bool _isRightMove;

public:
	baleog();
	~baleog();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();

	void olafKeyInput();

	void idleMotionStart(string direction);
	void moveMotionStart(string direction);
	void fallMotionStart(string direction);
	void onLadderMotionStart();

	static void rightIdle(void* obj);
	static void leftIdle(void* obj);


};

