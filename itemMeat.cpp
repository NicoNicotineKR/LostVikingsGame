#include "stdafx.h"
#include "itemMeat.h"


itemMeat::itemMeat()
{
}


itemMeat::~itemMeat()
{
}

HRESULT itemMeat::init()
{
	IMAGEMANAGER->addFrameImage("item_meat", "images/item/item_meat.bmp", 52, 45, 1, 1, true, 0xFF00FF);
	_itemInfo.img = IMAGEMANAGER->findImage("item_meat");
	_itemInfo.pos = { 2114, 884 - 70 };
	_itemInfo.rc = RectMakeCenter(_itemInfo.pos.x, _itemInfo.pos.y, _itemInfo.img->getFrameWidth(), _itemInfo.img->getFrameHeight());

	_itemInfo.kindof = E_MEAT;

	return S_OK;
}

void itemMeat::release()
{
}

void itemMeat::update()
{
}

void itemMeat::render()
{
	_itemInfo.img->frameRender(getMemDC(), _itemInfo.rc.left, _itemInfo.rc.top);
}

void itemMeat::UsingFunc()
{
}
