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
	void update(int characterSelect, float cameraX, float cameraY);
	void render();

	void move();


};

