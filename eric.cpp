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
	_img = IMAGEMANAGER->addFrameImage("eric", "images/character/eric.bmp", 1024, 2560, 8, 20, true, RGB(255, 0, 255));
	return S_OK;
}

void eric::release()
{
}

void eric::update()
{
}

void eric::render()
{
}

void eric::move()
{
	if (KEYMANAGER->isStayKeyDown)
	{

	}
}
