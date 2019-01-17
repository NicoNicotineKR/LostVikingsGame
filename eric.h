#pragma once
#include "characterInfo.h"
class eric :
	public characterInfo
{
private:
	float _accel;


public:
	eric();
	~eric();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
};

