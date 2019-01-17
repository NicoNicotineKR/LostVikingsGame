#pragma once
#include "gameNode.h"

class characterInfo : public gameNode
{
protected:
	image* _img;
	RECT _rc;
	POINTFLOAT _pos;
	tagVector2D _vec;
	float _gravity;
	float _speed;
	int _hp;
	string _itemSlot[4];
	bool _isPlaying;
	bool _isAlive;
	E_PLAYER_STATUS _status;

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
};

