#pragma once
#include "characterInfo.h"


class olaf : public characterInfo
{
private:

	bool _isShiledUp;
	bool _isGround;
	bool _isWall;
public:
	olaf();
	~olaf();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
	void olafKeyInput();
};

