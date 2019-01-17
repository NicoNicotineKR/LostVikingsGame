#pragma once
#include "characterInfo.h"

class eric : public characterInfo
{
private:
	float _accel;



	// 콘스트 변수
	const POINTFLOAT _beginPos = { WINSIZEX / 2, WINSIZEY / 2 };
public:
	eric();
	~eric();

	HRESULT init();
	void release();
	void update(int characterSelect, float cameraX, float cameraY);
	void render();

	void move();

	static void rightRushing(void* obj);
	static void leftRushing(void* obj);
};

