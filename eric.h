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
	void update();
	void render();

	void move();

	static void rightStuning(void* obj);
	static void leftStuning(void* obj);
	static void rightStand(void* obj);
	static void leftStand (void* obj);
};

