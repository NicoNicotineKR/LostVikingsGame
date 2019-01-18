#pragma once
#include "characterInfo.h"


class olaf : public characterInfo
{
private:
	image* map;
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
};

