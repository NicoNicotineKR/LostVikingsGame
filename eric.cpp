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
	characterInfo::init();
	_img = IMAGEMANAGER->addFrameImage("eric", "images/character/eric.bmp", 1024, 2560, 8, 20, true, RGB(255, 0, 255));
	
	_pos = _beginPos;
	
	_rc = RectMake(_pos.x,_pos.y, _img->getFrameWidth(),_img->getFrameHeight());

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStop", "eric", rightStop, 1, 1, true);

	int leftStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStop", "eric", leftStop, 1, 1, true);

	int rightMove[] = { 16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMove", "eric", rightMove, 8, 5, true);

	int leftMove[] = { 31,30,29,28,27,26,25,24 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMove", "eric", leftMove, 8, 5, true);

	int rightRush[] = { 32,33,34,35,36,37,38,39,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightRush", "eric", rightRush, 11, 5, false,rightRushing,this);

	int leftRush[] = { 47,46,45,44,43,42,41,40,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftRush", "eric", leftRush, 11, 5, false,leftRushing,this);


	_motion = KEYANIMANAGER->findAnimation("ericRightStop");

	return S_OK;
}

void eric::release()
{
}

void eric::update(int characterSelect, float cameraX, float cameraY)
{
	characterInfo::update(characterSelect, cameraX, cameraY);

	if (_status == P_R_IDLE)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightStop");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_IDLE)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftStop");
		_motion->start();
		_isMotionPlay = false;
	}

	if (_status == P_R_MOVE)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightMove");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_MOVE)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftMove");
		_motion->start();
		_isMotionPlay = false;
	}

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

void eric::rightRushing(void * obj)
{
	eric* e = (eric*)obj;

	e->setCharacterStatus(P_R_MOVE);
	e->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightMove"));
	e->getCharacterMotion()->start();
}

void eric::leftRushing(void * obj)
{
	eric* e = (eric*)obj;

	e->setCharacterStatus(P_L_MOVE);
	e->setCharacterMotion(KEYANIMANAGER->findAnimation("ericLeftMove"));
	e->getCharacterMotion()->start();
}
