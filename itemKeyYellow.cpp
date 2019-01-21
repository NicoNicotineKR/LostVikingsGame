#include "stdafx.h"
#include "itemKeyYellow.h"


itemKeyYellow::itemKeyYellow()
{
}


itemKeyYellow::~itemKeyYellow()
{
}

HRESULT itemKeyYellow::init()
{

	IMAGEMANAGER->addFrameImage("item_key_yellow", "images/item/item_key_yellow.bmp", 29, 48, 1, 1, true, 0xFF00FF);
	_itemInfo.img = IMAGEMANAGER->findImage("item_key_yellow");
	_itemInfo.pos = { 2398, 472 - 70 };
	_itemInfo.rc = RectMakeCenter(_itemInfo.pos.x, _itemInfo.pos.y, _itemInfo.img->getFrameWidth(), _itemInfo.img->getFrameHeight());

	_itemInfo.kindof = E_KEY_YELLOW;


	return S_OK;
}

void itemKeyYellow::release()
{
}

void itemKeyYellow::update()
{
}

void itemKeyYellow::render()
{
	_itemInfo.img->frameRender(getMemDC(), _itemInfo.rc.left, _itemInfo.rc.top);
}

void itemKeyYellow::UsingFunc()
{
}
