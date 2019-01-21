#pragma once
#include "gameNode.h"



//enum E_ITEMICONS {
//	E_EMPTY = 0,
//	E_BOMB,
//	E_KEY_RED,
//	E_KEY_YELLOW,
//	E_MEAT,
//};


class item : public gameNode
{
protected:
	struct tagItemInfo {
		image* img;
		RECT rc;
		POINT pos;
		E_ITEMICONS kindof;


	};

	tagItemInfo _itemInfo;


public:
	item();
	~item();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void UsingFunc();

	RECT getRc() { return _itemInfo.rc; }

	POINT getPos() { return _itemInfo.pos; }

	image* getImg() { return _itemInfo.img; }

	int getPosX() { return _itemInfo.pos.x; }
	int getPosY() { return _itemInfo.pos.y; }



};

