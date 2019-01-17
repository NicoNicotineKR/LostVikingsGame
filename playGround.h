#pragma once
#include "gameNode.h"
#include "scene2_1.h"

//추가
#include "camera.h"


class playGround : public gameNode
{
private:
	scene2_1* _scene2_1;
	//추가
	camera* _camera;

	char str[128];
	
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();
};

