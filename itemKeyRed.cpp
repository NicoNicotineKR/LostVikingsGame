#include "stdafx.h"
#include "itemKeyRed.h"


itemKeyRed::itemKeyRed()
{
}


itemKeyRed::~itemKeyRed()
{
}

HRESULT itemKeyRed::init()
{
	IMAGEMANAGER->addFrameImage("item_key_red", "images/item/item_key_red.bmp", 30, 54, 1, 1, true, 0xFF00FF);
	_itemInfo.img = IMAGEMANAGER->findImage("item_key_red");
	_itemInfo.pos = { 1534, 434 - 70 };
	_itemInfo.rc = RectMakeCenter(_itemInfo.pos.x, _itemInfo.pos.y, _itemInfo.img->getFrameWidth(), _itemInfo.img->getFrameHeight());

	_itemInfo.kindof = E_KEY_RED;


	return S_OK;
}

void itemKeyRed::release()
{

}

void itemKeyRed::update()
{
}

void itemKeyRed::render()
{
	_itemInfo.img->frameRender(getMemDC(), _itemInfo.rc.left, _itemInfo.rc.top);
}

void itemKeyRed::UsingFunc()
{
}
