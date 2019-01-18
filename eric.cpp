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

	//¾ØÀÌ¸Ş¼õÀÓÀÌÁãµé=============================================================================================================================================
	_img = IMAGEMANAGER->addFrameImage("eric", "images/character/eric.bmp", 1024, 2688, 8, 21, true, RGB(255, 0, 255));

	//¼­ÀÖ´Â°Å
	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStop", "eric", rightStop, 1, 1, true);
	int leftStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStop", "eric", leftStop, 1, 1, true);

	//´«±ôºıÀÌ±â
	int rightMotionOne[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMotionOne", "eric", rightMotionOne, 1, 3, false, rightStand, this);
	int leftMotionOne[] = { 14 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMotionOne", "eric", leftMotionOne, 1, 3, false, leftStand, this);

	//½Å¹ß²ö¹­±â
	int rightMotionTwo[] = { 5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMotionTwo", "eric", rightMotionTwo, 3, 6, false, rightStand, this);
	int leftMotionTwo[] = { 10,9,8 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMotionTwo", "eric", leftMotionTwo, 3, 6, false, leftStand, this);

	//¿òÁ÷ÀÌ´Â°Å
	int rightMove[] = { 16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMove", "eric", rightMove, 8, 10, true);
	int leftMove[] = { 31,30,29,28,27,26,25,24 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMove", "eric", leftMove, 8, 10, true);

	//µ¹ÁøÇÏ´Â½ºÅ³
	int rightRush[] = { 32,33,34,35,36,37,38,39,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightRush", "eric", rightRush, 11, 5, false, rightMoving, this);
	int leftRush[] = { 47,46,45,44,43,42,41,40,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftRush", "eric", leftRush, 11, 5, false, leftMoving, this);

	//½ºÅÏ¸ÔÀº°Å (º®¹Ú±â, ¸÷¹Ú±â, ³«µ©ÀÔ±â)
	int rightStun[] = { 48,49,50,51,52,50,51,52,50,51,52,53,54,55 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStun", "eric", rightStun, 14, 3, false, rightStand, this);
	int leftStun[] = { 63,62,61,60,59,61,60,59,61,60,59,58,57,56 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStun", "eric", leftStun, 14, 3, false, leftStand, this);

	//»ç´Ù¸® Å¸°íÀÖ´ÂÁß(on)
	int rightOnLadder[] = { 64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOnLadder", "eric", rightOnLadder, 4, 5, true);
	int leftOnLadder[] = { 77,76,75,74 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOnLadder", "eric", leftOnLadder, 4, 5, true);

	//»ç´Ù¸®À§¿¡ °ÉÄ£°Å(off)
	int rightOffLadder[] = { 68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOffLadder", "eric", rightOffLadder, 2, 2, false, rightStand, this);
	int leftOffLadder[] = { 73,72 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOffLadder", "eric", leftOffLadder, 2, 2, false, leftStand, this);

	//ÇÃ·¹ÀÌ¾î º®¹Ú±â
	int rightCrashWall[] = { 80,81,82 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightCrashWall", "eric", rightCrashWall, 3, 3, false, rightStuning, this);
	int leftCrashWall[] = { 92,91,90 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftCrashWall", "eric", leftCrashWall, 3, 3, false, leftStuning, this);

	//¸÷ÇÑÅ× ¸Â±â
	int rightHit[] = { 83 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightHit", "eric", rightHit, 1, 5, false, rightStand, this);
	int leftHit[] = { 89 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftHit", "eric", leftHit, 1, 5, false, leftStand, this);

	//Ãß¶ôµ¥¹ÌÁö ³ª¿À±âÀü °øÁß ¸ğ¼Ç -> ¶¥¿¡ ´êÀ¸¸é ÇÇ1±î°í ½ºÅÏµÊ
	int rightFalling[] = { 84 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFalling", "eric", rightFalling, 1, 1, true);
	int leftFalling[] = { 88 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFalling", "eric", leftFalling, 1, 1, true);

	//º®¹Ì´Â ¸ğ¼Ç
	int rightWallPush[] = { 96, 97, 98, 99 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightWallPush", "eric", rightWallPush, 4, 3, true);
	int leftWallPush[] = { 107,106,105,104 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftWallPush", "eric", leftWallPush, 4, 3, true);

	//¸Â¾Æ¼­ Á×´Â ¸ğ¼Ç
	int rightHitDead[] = { 112,113,114,115,116,117,118,119 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightHitDead", "eric", rightHitDead, 8, 5, false);
	int  leftHitDead[] = { 127,126,125,124,123,122,121,120 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftHitDead", "eric", leftHitDead, 8, 5, false);

	//ºüÁ®Á×´Â¸ğ¼Ç
	int rightWaterDead[] = { 128,129,130,131,132 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightWaterDead", "eric", rightWaterDead, 5, 5, false);
	int  leftWaterDead[] = { 140,139,138,137,136 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftWaterDead", "eric", leftWaterDead, 5, 5, false);

	//³«µ©À¸·Î Á×´Â ¸ğ¼Ç
	int rightFallDead[] = { 144,145,146,147,148,149 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFallDead", "eric", rightFallDead, 5, 5, false);
	int  leftFallDead[] = { 157,156,155,154,153,152 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFallDead", "eric", leftFallDead, 5, 5, false);

	//Á¡ÇÁÇÏ´Â ¸ğ¼Ç
	int rightJump[] = { 160,161 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightJump", "eric", rightJump, 2, 3, false, rightFlying, this);
	int leftJump[] = { 167,166 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftJump", "eric", leftJump, 2, 3, false, leftFlying, this);

	//³«µ©À» ÀÔÁö ¾Ê´Â ¶³¾îÁö´Â¸ğ¼Ç
	int rightFly[] = { 162,163 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFly", "eric", rightFly, 2, 3, true);
	int leftFly[] = { 165,164 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFly", "eric", leftFly, 2, 3, true);

	//¾ØÀÌ¸Ş¼õÀÓÀÌÁãµé=============================================================================================================================================

	_pos = _beginPos;
	_isPlaying = true;


	_motion = KEYANIMANAGER->findAnimation("ericRightStop");

	_rc = RectMake(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());

	return S_OK;
}

void eric::release()
{
}

void eric::update()
{
	characterInfo::update();

	//°¡¸¸¾²
	if (_status == P_R_IDLE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightStop");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_IDLE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftStop");
		_motion->start();
		_isMotionPlay = false;
	}

	//¸ğ¼Ç1 (´«±ôºı)
	if (_status == P_R_MOTION_ONE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightMotionOne");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_MOTION_ONE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftMotionOne");
		_motion->start();
		_isMotionPlay = false;
	}

	//¸ğ¼Ç2 (½Å¹ß²ö)
	if (_status == P_R_MOTION_TWO && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightMotionTwo");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_MOTION_TWO && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftMotionTwo");
		_motion->start();
		_isMotionPlay = false;
	}

	//¿òÁ÷ÀÌ±â
	if (_status == P_R_MOVE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericRightMove");
		_motion->start();
		_isMotionPlay = false;
	}
	else if (_status == P_L_MOVE && _isMotionPlay)
	{
		_motion = KEYANIMANAGER->findAnimation("ericLeftMove");
		_motion->start();
		_isMotionPlay = false;
	}

	move();



	_rc = RectMake(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());
	//_rc = RectMake(_pos.x - _cameraX + WINSIZEX / 2, _pos.y - _cameraY + WINSIZEY / 2, _img->getFrameWidth(),_img->getFrameHeight());
}

void eric::render()
{
	Rectangle(getMemDC(), _rc.left - _cameraX + WINSIZEX / 2, _rc.top - _cameraY + WINSIZEY / 2, _rc.right - _cameraX + WINSIZEX / 2, _rc.bottom - _cameraY + WINSIZEY / 2);
	_img->aniRender(getMemDC(), _rc.left- _cameraX + WINSIZEX / 2, _rc.top - _cameraY + WINSIZEY / 2, _motion);

//	Rectangle(getMemDC(), _rc);
//	_img->aniRender(getMemDC(), _rc.left, _rc.top,_motion);
	
	char str1[128];
	sprintf_s(str1, "%d");
	TextOut(getMemDC(), 900, 700, str1, strlen(str1));
}

void eric::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_pos.x += _speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pos.x -= _speed;
	}
}

void eric::rightMoving(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_MOVE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightMove"));
	Eric->getCharacterMotion()->start();
}

void eric::leftMoving(void * obj)
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

void eric::rightStuning(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_STUN);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightStun"));
	Eric->getCharacterMotion()->start();
}

void eric::leftStuning(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_L_STUN);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericLeftStun"));
	Eric->getCharacterMotion()->start();
}

void eric::rightFlying(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_FLYING);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightStop"));
	Eric->getCharacterMotion()->start();
}

void eric::leftFlying(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_L_FLYING);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericLeftStop"));
	Eric->getCharacterMotion()->start();
}
