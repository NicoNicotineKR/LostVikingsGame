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

	//서있는거
	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStop", "eric", rightStop, 1, 1, true);
	int leftStop[]  = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStop",  "eric",  leftStop, 1, 1, true);

	//움직이는거
	int rightMove[] = { 16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMove", "eric", rightMove, 8, 5, true);
	int leftMove[]  = { 31,30,29,28,27,26,25,24 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMove",  "eric",  leftMove, 8, 5, true);

	//돌진하는스킬
	int rightRush[] = { 32,33,34,35,36,37,38,39,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightRush", "eric", rightRush, 11, 5, false, rightStuning,this);
	int leftRush[]  = { 47,46,45,44,43,42,41,40,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftRush",  "eric",  leftRush, 11, 5, false,  leftStuning,this);

	//스턴먹은거 (벽박기, 몹박기, 낙뎀입기)
	int rightStun[] = { 48,49,50,51,52,50,51,52,50,51,52,53,54,55 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStun", "eric", rightStun, 14, 3, false, rightStand, this);
	int leftStun[]  =  { 63,62,61,60,59,61,60,59,61,60,59,58,57,56 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStun",  "eric",  leftStun, 14, 3, false,  leftStand, this);

	//사다리 타고있는중(on)
	int rightOnLadder[] = { 64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOnLadder", "eric", rightOnLadder, 4, 5, true);
	int leftOnLadder[]  = { 77,76,75,74 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOnLadder",  "eric", leftOnLadder, 4, 5,  true);

	//사다리위에 걸친거(off)
	int rightOffLadder[] = { 68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOffLadder", "eric", rightOffLadder, 2, 2, false, rightStand, this);
	int leftOffLadder[]  = { 73,72 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOffLadder",  "eric", leftOffLadder, 2, 2,  false,  leftStand, this);

	//플레이어 벽박기
	int rightCrashWall[] = { 80,89,90 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightCrashWall", "eric", rightCrashWall, 3, 3, false, rightStuning, this);
	int leftCrashWall[]  = { 100,99,98 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftCrashWall",  "eric",  leftCrashWall, 3, 3, false,  leftStuning, this);

	//몹한테 맞기

	//추락데미지




	_motion = KEYANIMANAGER->findAnimation("ericRightStop");

	return S_OK;
}

void eric::release()
{
}

void eric::update()
{
	characterInfo::update();

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

void eric::rightStuning(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_MOVE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightMove"));
	Eric->getCharacterMotion()->start();
}

void eric::leftStuning(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_L_MOVE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericLeftMove"));
	Eric->getCharacterMotion()->start();
}

void eric::rightStand(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_IDLE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightStop"));
	Eric->getCharacterMotion()->start();
}

void eric::leftStand(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_L_IDLE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericLeftStop"));
	Eric->getCharacterMotion()->start();
}
