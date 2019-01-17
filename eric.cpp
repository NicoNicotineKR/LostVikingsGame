#include "stdafx.h"
#include "eric.h"


eric::eric()
{
}

eric::~eric()
{
}

HRESULT eric::init()
{
//	_pos = { WINSIZEX / 2, WINSIZEY / 2 };
//	_rc = RectMake(_pos.x,_pos.y, 50, 50);
	_img = IMAGEMANAGER->addFrameImage("eric", "images/character/eric.bmp", 1024, 2560, 8, 20, true, RGB(255, 0, 255));
	return S_OK;
}

void eric::release()
{
}

void eric::update(int characterSelect, float cameraX, float cameraY)
{
//	_cameraX = cameraX;
//	_cameraY = cameraY;
//
//	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
//	{
//		_pos.x += 5;
//	}
//	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
//	{
//		_pos.x-= 5;
//	}
//
//	_rc = RectMake(_pos.x, _pos.y, 50, 50);
}

void eric::render()
{
//	Rectangle(getMemDC(),_rc.left - _cameraX + WINSIZEX/2,_rc.top - _cameraY + WINSIZEY/2,_rc.right - _cameraX + WINSIZEX/2, _rc.bottom - _cameraY + WINSIZEY/2);
//	char str1[128];
//	sprintf_s(str1, "%f", _pos.x);
//	TextOut(getMemDC(), 900, 700, str1, strlen(str1));
}

void eric::move()
{
}
