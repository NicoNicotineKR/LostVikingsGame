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

	//키애니메이션 이미지 만들고
	imageInit();
	//기본모션은 오른쪽서있는거
	_motion = KEYANIMANAGER->findAnimation("ericRightStop");
	

	_pos = BEGIN_POS;
	_vec.x = MIN_SPEED;
	_accel = ACCEL_VALUE;	//가속도

	//현재 플레이중인지
	_isPlaying = false;
	// 숨쉬어야하는지
	_isBreath = false;
	_isRushing = false;
	_isGround = false;
	_isJumping = false;
	_isMoving = false;
	


	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());

	return S_OK;
}

void eric::release()
{
}
	// 점차 추가해야할것

	// ladder more think
	// if(KEYMANAGER->isOnceKeyUP

	// hit is later

	// wall push after the map is created

	// all death after the map is created

	// all airflying is after the map is created

void eric::update()
{
	characterInfo::update();

	_isJumping = false;

	// 플레이중이 아니고 상태가 움직이는거였으면 idle로
	_pos.y = PixelColFunction(0, _pos.x, _pos.y, 64, 5,
		IMAGEMANAGER->findImage("씬2_1픽셀"),
		IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(),
		RGB(255, 0, 0),
		&_isGround);

	if (_isPlaying && !_isFlying)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _status != P_R_FLYING && _status != P_R_JUMP)
		{
			_motion->stop();
			_status = P_R_MOVE;
			_motion = KEYANIMANAGER->findAnimation("ericRightMove");
			_motion->start();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _status != P_L_FLYING && _status != P_L_JUMP)
		{
			_motion->stop();
			_status = P_L_MOVE;
			_motion = KEYANIMANAGER->findAnimation("ericLeftMove");
			_motion->start();
		}



		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && _status != P_R_FLYING && _status != P_R_JUMP)
		{
			_motion->stop();
			_motion_Count = 0;
			_status = P_R_IDLE;
			_motion = KEYANIMANAGER->findAnimation("ericRightStop");
			_motion->start();
			//최대속도에 도달해서 isBreath가 true가 되면
			if (_isBreath)
			{
				_motion->stop();
				_status = P_R_BREATH;
				_motion = KEYANIMANAGER->findAnimation("ericRightBreath");
				_isBreath = false;
				_motion->start();
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && _status != P_L_FLYING && _status != P_L_JUMP)
		{
			_motion->stop();
			_motion_Count = 0;
			_status = P_L_IDLE;
			_motion = KEYANIMANAGER->findAnimation("ericLeftStop");
			_motion->start();
			//최대속도에 도달해서 isBreath가 true가 되면
			if (_isBreath)
			{
				_motion->stop();
				_status = P_L_BREATH;
				_motion = KEYANIMANAGER->findAnimation("ericLeftBreath");
				_isBreath = false;
				_motion->start();
			}
		}

		if (KEYMANAGER->isOnceKeyDown('Z') && 
			(_status != P_R_JUMP && _status != P_L_JUMP && _status != P_R_FLYING && _status != P_L_FLYING && _status != P_L_FALLING && _status != P_R_FALLING))
		{
			_vec.y = JUMP_POWER;
			_isJumping = true;
			_motion->stop();
			if (_status == P_R_IDLE || _status == P_R_MOVE || _status == P_R_BREATH)
			{
				_status = P_R_JUMP;
				_motion = KEYANIMANAGER->findAnimation("ericRightJump");
			}
			else if (_status == P_L_IDLE || _status == P_L_MOVE || _status == P_L_BREATH)
			{
				_status = P_L_JUMP;
				_motion = KEYANIMANAGER->findAnimation("ericLeftJump");
			}
			_motion->start();
		}
	}
	if (_isJumping)
	{
		_vec.y += GRAVITY;
		_pos.y += _vec.y;
	}



	if (_isGround)
	{
		_isFlying = false;
		if (_status == P_R_FLYING)
		{
			if (_isMoving)
			{
				_motion->stop();
				_status = P_R_MOVE;
				_motion = KEYANIMANAGER->findAnimation("ericRightMove");
				_motion->start();
			}
			else
			{
				_motion->stop();
				_status = P_R_IDLE;
				_motion = KEYANIMANAGER->findAnimation("ericRightStop");
				_motion->start();
			}
		}
		if (_status == P_L_FLYING)
		{
			if (_isMoving)
			{
				_motion->stop();
				_status = P_L_MOVE;
				_motion = KEYANIMANAGER->findAnimation("ericLeftMove");
				_motion->start();
			}
			else
			{
				_motion->stop();
				_status = P_L_IDLE;
				_motion = KEYANIMANAGER->findAnimation("ericLeftStop");
				_motion->start();
			}
		}
	}
	else if (!_isGround && !_isJumping)
	{
		_vec.y += GRAVITY;
		_pos.y += _vec.y;
	}



	if (!_isGround &&_vec.y >= 0)
	{
		if (_status == P_R_IDLE || _status == P_R_JUMP)
		{
			_status = P_R_FLYING;
		}
		else if (_status == P_L_IDLE || _status == P_L_JUMP)
		{
			_status = P_L_FLYING;
		}
	}
	else if (_vec.y < 0)
	{
		if (_status == P_R_IDLE)
		{
			_status = P_R_JUMP;
		}
		else if (_status == P_L_IDLE)
		{
			_status = P_L_JUMP;
		}
	}

	if (_status == P_R_FLYING)
	{
		_motion->stop();
		_motion = KEYANIMANAGER->findAnimation("ericRightFly");
		_motion->start();
	}
	else if (_status == P_L_FLYING)
	{
		_motion->stop();
		_motion = KEYANIMANAGER->findAnimation("ericLeftFly");
		_motion->start();
	}

	//가만히 있을때 모션 2개중에 랜덤으로 틀어주는거
	IdleMotion();
	move();
	isNotPlaying();

	

	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());
	//_rc = RectMake(_pos.x - _cameraX + WINSIZEX / 2, _pos.y - _cameraY + WINSIZEY / 2, _img->getFrameWidth(),_img->getFrameHeight());
}

void eric::render()
{
	Rectangle(getMemDC(), _rc.left - _cameraX + WINSIZEX / 2, _rc.top - _cameraY + WINSIZEY / 2, _rc.right - _cameraX + WINSIZEX / 2, _rc.bottom - _cameraY + WINSIZEY / 2);
	_img->aniRender(getMemDC(), _rc.left- _cameraX + WINSIZEX / 2, _rc.top - _cameraY + WINSIZEY / 2, _motion);

//	Rectangle(getMemDC(), _rc);
//	_img->aniRender(getMemDC(), _rc.left, _rc.top,_motion);
	
	char str1[128];
	sprintf_s(str1, "%d",_status);
	TextOut(getMemDC(), 900, 700, str1, strlen(str1));
}

void eric::move()
{
	if (_status == P_R_IDLE || _status == P_R_BREATH || _status == P_R_FLYING)
	{
		_isMoving = false;
		_vec.x -= _accel;
		if (_vec.x < MIN_SPEED)
		{
			_vec.x = MIN_SPEED;
		}
	}
	else if (_status == P_L_IDLE || _status == P_L_BREATH || _status == P_L_FLYING)
	{
		_isMoving = false;
		_vec.x += _accel;
		if (_vec.x > MIN_SPEED)
		{
			_vec.x = MIN_SPEED;
		}
	}
	if (_isPlaying)
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_isMoving = true;
			_vec.x += _accel;
			if (_vec.x > MAX_SPEED)
			{
				_vec.x = MAX_SPEED;
				_isBreath = true;
			}
		}
		else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_isMoving = true;
			_vec.x -= _accel;
			if (_vec.x < -MAX_SPEED)
			{
				_vec.x = -MAX_SPEED;
				_isBreath = true;
			}
		}
	}
	
		_pos.x += _vec.x;
}

void eric::imageInit()
{
	//앤이메숑임이쥐들=============================================================================================================================================
	_img = IMAGEMANAGER->addFrameImage("eric", "images/character/eric.bmp", 1024, 2688, 8, 21, true, RGB(255, 0, 255));

	//서있는거
	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStop", "eric", rightStop, 1, 1, true);
	int leftStop[] = { 15 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStop", "eric", leftStop, 1, 1, true);

	//숨벅차하는거
	int rightBreath[] = { 2,3,4,2,3,4,2,3,4 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightBreath", "eric", rightBreath, 9, 10, false, rightStanding, this);
	int leftBreath[] = { 13,12,11,13,12,11,13,12,11 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftBreath", "eric", leftBreath, 9, 10, false, leftStanding, this);


	//눈깜빡이기
	int rightMotionOne[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMotionOne", "eric", rightMotionOne, 1, 3, false, rightStanding, this);
	int leftMotionOne[] = { 14 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMotionOne", "eric", leftMotionOne, 1, 3, false, leftStanding, this);

	//신발끈묶기
	int rightMotionTwo[] = { 5,6,7,6,7,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMotionTwo", "eric", rightMotionTwo, 7, 6, false, rightStanding, this);
	int leftMotionTwo[] = { 10,9,8,9,8,9,8 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMotionTwo", "eric", leftMotionTwo, 7, 6, false, leftStanding, this);

	//움직이는거
	int rightMove[] = { 16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightMove", "eric", rightMove, 8, 10, true);
	int leftMove[] = { 31,30,29,28,27,26,25,24 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftMove", "eric", leftMove, 8, 10, true);

	//돌진하는스킬
	int rightRush[] = { 32,33,34,35,36,37,38,39,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightRush", "eric", rightRush, 11, 5, false, rightMoving, this);
	int leftRush[] = { 47,46,45,44,43,42,41,40,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftRush", "eric", leftRush, 11, 5, false, leftMoving, this);

	//스턴먹은거 (벽박기, 몹박기, 낙뎀입기)
	int rightStun[] = { 48,49,50,51,52,50,51,52,50,51,52,53,54,55 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightStun", "eric", rightStun, 14, 3, false, rightStanding, this);
	int leftStun[] = { 63,62,61,60,59,61,60,59,61,60,59,58,57,56 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftStun", "eric", leftStun, 14, 3, false, leftStanding, this);

	//사다리 타고있는중(on)
	int rightOnLadder[] = { 64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOnLadder", "eric", rightOnLadder, 4, 5, true);
	int leftOnLadder[] = { 77,76,75,74 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOnLadder", "eric", leftOnLadder, 4, 5, true);

	//사다리위에 걸친거(off)
	int rightOffLadder[] = { 68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightOffLadder", "eric", rightOffLadder, 2, 2, false, rightStanding, this);
	int leftOffLadder[] = { 73,72 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftOffLadder", "eric", leftOffLadder, 2, 2, false, leftStanding, this);

	//플레이어 벽박기
	int rightCrashWall[] = { 80,81,82 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightCrashWall", "eric", rightCrashWall, 3, 3, false, rightStuning, this);
	int leftCrashWall[] = { 92,91,90 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftCrashWall", "eric", leftCrashWall, 3, 3, false, leftStuning, this);

	//몹한테 맞기
	int rightHit[] = { 83 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightHit", "eric", rightHit, 1, 5, false, rightStanding, this);
	int leftHit[] = { 89 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftHit", "eric", leftHit, 1, 5, false, leftStanding, this);

	//추락데미지 나오기전 공중 모션 -> 땅에 닿으면 피1까고 스턴됨
	int rightFalling[] = { 84 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFalling", "eric", rightFalling, 1, 1, true);
	int leftFalling[] = { 88 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFalling", "eric", leftFalling, 1, 1, true);

	//벽미는 모션
	int rightWallPush[] = { 96, 97, 98, 99 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightWallPush", "eric", rightWallPush, 4, 3, true);
	int leftWallPush[] = { 107,106,105,104 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftWallPush", "eric", leftWallPush, 4, 3, true);

	//맞아서 죽는 모션
	int rightHitDead[] = { 112,113,114,115,116,117,118,119 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightHitDead", "eric", rightHitDead, 8, 5, false);
	int  leftHitDead[] = { 127,126,125,124,123,122,121,120 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftHitDead", "eric", leftHitDead, 8, 5, false);

	//빠져죽는모션
	int rightWaterDead[] = { 128,129,130,131,132 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightWaterDead", "eric", rightWaterDead, 5, 5, false);
	int  leftWaterDead[] = { 140,139,138,137,136 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftWaterDead", "eric", leftWaterDead, 5, 5, false);

	//낙뎀으로 죽는 모션
	int rightFallDead[] = { 144,145,146,147,148,149 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFallDead", "eric", rightFallDead, 5, 5, false);
	int  leftFallDead[] = { 157,156,155,154,153,152 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFallDead", "eric", leftFallDead, 5, 5, false);

	//점프하는 모션
	int rightJump[] = { 160,161 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightJump", "eric", rightJump, 2, 3, false, rightFlying, this);
	int leftJump[] = { 167,166 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftJump", "eric", leftJump, 2, 3, false, leftFlying, this);

	//낙뎀을 입지 않는 떨어지는모션
	int rightFly[] = { 162,163 };
	KEYANIMANAGER->addArrayFrameAnimation("ericRightFly", "eric", rightFly, 2, 3, true);
	int leftFly[] = { 165,164 };
	KEYANIMANAGER->addArrayFrameAnimation("ericLeftFly", "eric", leftFly, 2, 3, true);

	//앤이메숑임이쥐들=============================================================================================================================================
}

void eric::IdleMotion()
{
	if (_status == P_R_IDLE)
	{
		_motion_Count += TIMEMANAGER->getElpasedTime();
		if (_motion_Count >= 5)
		{
			int rand = RND->getInt(2);
			_motion_Count = 0;
			switch (rand)
			{
			case 0:
				_status = P_R_MOTION_ONE;
				_motion = KEYANIMANAGER->findAnimation("ericRightMotionOne");
				break;
			case 1:
				_status = P_R_MOTION_TWO;
				_motion = KEYANIMANAGER->findAnimation("ericRightMotionTwo");
				break;
			}
			_motion->start();
		}
	}
	else if (_status == P_L_IDLE)
	{
		_motion_Count += TIMEMANAGER->getElpasedTime();
		if (_motion_Count >= 5)
		{
			int rand = RND->getInt(2);
			_motion_Count = 0;
			switch (rand)
			{
			case 0:
				_status = P_L_MOTION_ONE;
				_motion = KEYANIMANAGER->findAnimation("ericLeftMotionOne");
				break;
			case 1:
				_status = P_L_MOTION_TWO;
				_motion = KEYANIMANAGER->findAnimation("ericLeftMotionTwo");
				break;
			}
			_motion->start();
		}
	}
}

void eric::isNotPlaying()
{
	if (!_isPlaying && _status == P_R_MOVE)
	{
		_motion->stop();
		_motion_Count = 0;
		_status = P_R_IDLE;
		_motion = KEYANIMANAGER->findAnimation("ericRightStop");
		_motion->start();
		//최대속도에 도달해서 isBreath가 true가 되면
		if (_isBreath)
		{
			_motion->stop();
			_status = P_R_BREATH;
			_motion = KEYANIMANAGER->findAnimation("ericRightBreath");
			_isBreath = false;
			_motion->start();
		}
	}
	else if (!_isPlaying && _status == P_L_MOVE)
	{
		_motion->stop();
		_motion_Count = 0;
		_status = P_L_IDLE;
		_motion = KEYANIMANAGER->findAnimation("ericLeftStop");
		_motion->start();
		//최대속도에 도달해서 isBreath가 true가 되면
		if (_isBreath)
		{
			_motion->stop();
			_status = P_L_BREATH;
			_motion = KEYANIMANAGER->findAnimation("ericLeftBreath");
			_isBreath = false;
			_motion->start();
		}
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

void eric::rightStanding(void * obj)
{
	eric* Eric = (eric*)obj;

	Eric->setCharacterStatus(P_R_IDLE);
	Eric->setCharacterMotion(KEYANIMANAGER->findAnimation("ericRightStop"));
	Eric->getCharacterMotion()->start();
}

void eric::leftStanding(void * obj)
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
