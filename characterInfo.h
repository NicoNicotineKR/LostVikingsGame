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
public:
	characterInfo();
	~characterInfo();
};

