#include "stdafx.h"
#include "itemBomb.h"


itemBomb::itemBomb()
{
}


itemBomb::~itemBomb()
{
}

HRESULT itemBomb::init()
{
	IMAGEMANAGER->addFrameImage("item_bomb", "images/item/item_bomb.bmp", 48, 48, 1, 1, true, 0xFF00FF);
	_itemInfo.img = IMAGEMANAGER->findImage("item_bomb");
	_itemInfo.pos = { 1762, 594 - 70 };
	_itemInfo.rc = RectMakeCenter(_itemInfo.pos.x, _itemInfo.pos.y, _itemInfo.img->getFrameWidth(), _itemInfo.img->getFrameHeight());

	_itemInfo.kindof = E_BOMB;


	return S_OK;
}

void itemBomb::release()
{
}

void itemBomb::update()
{
}

void itemBomb::render()
{
	_itemInfo.img->frameRender(getMemDC(), _itemInfo.rc.left, _itemInfo.rc.top);
}

void itemBomb::UsingFunc()
{
}
