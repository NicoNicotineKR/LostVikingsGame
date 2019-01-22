#pragma once
#include "characterInfo.h"


class olaf : public characterInfo
{
private:
	RECT _shiled;
	int  _shiledX, _shiledY;
	int  _shiledWidth, _shiledHeight;

	float _acceleration;
	POINTFLOAT _fallStartPos;

	bool _isShiledUp;

	bool _isFlyMotion;

	bool _isLeftMove;
	bool _isRightMove;

public:
	olaf();
	~olaf();

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
	static void hitDead(void* obj);

};

