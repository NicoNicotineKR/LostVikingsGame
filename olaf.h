#pragma once
#include "characterInfo.h"


class olaf : public characterInfo
{
private:
	RECT _shiled;
	int  _shiledX, _shiledY;
	int  _shiledWidth, _shiledHeight;

	bool _isShiledUp;

	bool _isGround;
	bool _isWall;

	bool _isFlyMotion;

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
};

