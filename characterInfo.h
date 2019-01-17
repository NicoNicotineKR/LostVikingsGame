#pragma once
#include "gameNode.h"
//#include "CONFIG.h"
struct tagPlayer
{
	RECT rc;
	POINTFLOAT pos;
	tagVector2D vec;
	float gravity;
	float speed;
	int hp;
	string itemSlot[4];
	bool isPlaying;
	bool isAlive;

};
class characterInfo : public gameNode
{
private:

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

