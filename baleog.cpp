#include "stdafx.h"
#include "baleog.h"


baleog::baleog()
{
}


baleog::~baleog()
{
}

HRESULT baleog::init()
{
	characterInfo::init();

	_img = IMAGEMANAGER->addFrameImage("baleog_sprite", "images/character/baleog_sprite.bmp", 0, 0, 1024, 2432, 8, 19, true, RGB(255, 0, 255));			//플레이어 이미지 초기화
	_arowImg[0] = IMAGEMANAGER->addImage("arowRight", "images/character/arowRight.bmp", 400, 40, true, RGB(255, 0, 255));
	_arowImg[1] = IMAGEMANAGER->addImage("arowLeft", "images/character/arowLeft.bmp", 400, 40, true, RGB(255, 0, 255));
	int rightIdleMotion[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightIdle", "baleog_sprite", rightIdleMotion, 1, 10, true);								 //오른쪽 방패내린 idle

	int leftIdleMotion[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftIdle", "baleog_sprite", leftIdleMotion, 1, 10, true);								 //왼쪽   방패내린 idle

	int rightFlying[] = { 4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightFlying", "baleog_sprite", rightFlying, 2, 10, true);					//오른쪽 방패내린 idle Motion

	int leftFlying[] = { 6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftFlying", "baleog_sprite", leftFlying, 2, 10, true);					//왼쪽 방패 내린 idle Motion

	int rightMove[] = { 8,9,10,11,12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightMove", "baleog_sprite", rightMove, 8, 10, true);									 //오른쪽 방패올린 idle

	int leftMove[] = {23,22,21,20,19,18,17,16 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftMove", "baleog_sprite", leftMove, 8, 10, true);									 //왼쪽   방패올린 idle

	int rightBow[] = {24,25,26,27,28,29,30,31};
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightBow", "baleog_sprite", rightBow, 8, 10, false,rightIdle,this);						//오른쪽 방패 올린 idle Motion

	int leftBow[] = { 39,38,37,36,35,34,33,32 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftBow", "baleog_sprite", leftBow, 8, 10, false,leftIdle,this);						//왼쪽  방패 올린 idle Motion
	//
	int rightAttack1[] = { 40,41,42,43 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightAttack1", "baleog_sprite", rightAttack1, 4, 10, false,rightIdle,this);								 //오른쪽 방패내린 move

	int leftAttack1[] = { 51,50,49,48 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftAttack1", "baleog_sprite", leftAttack1, 4, 10, false,leftIdle,this);								 //왼쪽   방패내린 move

	int rightAttack2[] = { 44,45,46,47 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightAttack2", "baleog_sprite", rightAttack2, 4, 10, false,rightIdle,this);									 //오른쪽 방패올린 move

	int leftAttack2[] = { 55,54,53,52 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftAttack2", "baleog_sprite", leftAttack2, 4, 10, false,leftIdle,this);									 //왼쪽   방패올린 move
	//
	int rightPushWall[] = { 56,57,58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightPushWall", "baleog_sprite", rightPushWall, 4, 10, true);											 //오른쪽 벽밀기

	int leftPushWall[] = { 63,62,61,60 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftPushWall", "baleog_sprite", leftPushWall, 4, 10, true);					   						 //왼쪽  벽밀기

	int rightFall[] = { 64,65,66,67,68,69 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightFall", "baleog_sprite", rightFall, 6, 5, false,rightIdle,this);									 //오른쪽 방패올린 fall

	int leftFall[] = { 77,76,75,74,73,72 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftFall", "baleog_sprite", leftFall, 6, 5, false,leftIdle,this);									 //왼쪽  방패올린 fall

	int rightFallDownDead[] = { 80,81,82,83,84,85,86 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightFallDead", "baleog_sprite", rightFallDownDead, 6, 5, false, hitDead, this);							 //오른쪽 방패올린 fall Move

	int leftFallDownDead[] = { 93,92,91,90,89,88 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftFallDead", "baleog_sprite", leftFallDownDead, 6, 5, false, hitDead, this);							 //왼쪽   방패올린 fall Move

	int rightHitDead[] = { 96,97,98,99,100,101,102 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightHitDead", "baleog_sprite", rightHitDead, 7, 5, false, hitDead,this);								 //오른쪽 방패내린 fall

	int leftHitDead[] = { 110,109,108,107,106,105,104 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftHitDead", "baleog_sprite", leftHitDead, 7, 5, false, hitDead,this);								 //왼쪽   방패내린 fall

	int ladderOn[] = { 112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogOnLadder", "baleog_sprite", ladderOn, 4, 10, true);							//오른쪽 추락 (damage)

	int rightWaterDead[] = { 120,121,123,124,125 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogRightWaterDead", "baleog_sprite", rightWaterDead, 5, 3, false);								//왼쪽  추락(damage)

	int leftWaterDead[] = { 132,131,130,129,128 };
	KEYANIMANAGER->addArrayFrameAnimation("baleogLeftWaterDead", "baleog_sprite", leftWaterDead, 5, 3, false);									//오른쪽 추락사
	
	_motion = KEYANIMANAGER->findAnimation("baleogRightIdle");
	_pos.x = 200;
	_pos.y = 120;
	_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);

	_fallStartPos.x = 0;
	_fallStartPos.y = 0;

	_hp = 3;
	_speed = 0;
	_isPlaying = false;
	_isGround = false;
	_isWall = false;
	_isFire = false;
	_isArrowDirection = false;
	_isLadderMotion = false;
	_isAlive = true;
	return S_OK;
}

void baleog::release()
{
}

void baleog::update()
{
	arrowMove(_isArrowDirection);
	if (_isAlive)
	{
		if (_isWaterDead)
		{
			_isWaterDead = false;
			_isDeadAni = true;
			//오른쪽이면
			if (_status == P_R_MOVE || _status == P_R_IDLE || _status == P_R_BREATH || _status == P_R_SKILL_ONE || _status == P_R_SKILL_TWO || _status == P_R_FALLING || _status == P_R_FLYING ||
				_status == P_R_STUN || _status == P_R_WALL_PUSH)
			{
				_motion->stop();
				_status = P_R_WATER_DEATH;
				_motion = KEYANIMANAGER->findAnimation("baleogRightWaterDead");
				_motion->start();
			}
			//왼쪽이면
			else
			{
				_motion->stop();
				_status = P_L_WATER_DEATH;
				_motion = KEYANIMANAGER->findAnimation("baleogLeftWaterDead");
				_motion->start();
			}
		}
		else if (_isDeadAni)
		{
			if (_motion->isPlay() == FALSE)
			{
				_isPlaying = false;
				_isAlive = false;
				_hp = 0;
				_pos = { -100,-100 };
			}

		}
		if (!_isDeadAni)
		{
			_pos.y = PixelColFunction(0, _pos.x, _pos.y, 64, 5,
				IMAGEMANAGER->findImage("씬2_1픽셀"),
				IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(),
				RGB(0, 0, 255),
				&_isWaterDead);
		}



		characterInfo::update();
		olafKeyInput();
		_vec.y = 0;
		_vec.x = 0;

		if (!_isWall)
		{
			move();
			if (_status == P_L_STUN || _status == P_R_STUN || _status == P_L_WALL_PUSH || _status == P_R_WALL_PUSH)
			{
				_vec.x = 0;
				_vec.y = 0;
			}
			_pos.x += _vec.x;
			_pos.y += _vec.y;
			_vec.x = 0;
			_vec.y = 0;
		}

		//벽밀때
		if (_status == P_L_MOVE)
		{
			_pos.x = PixelColFunction(3, _pos.x, _pos.y, 64, 5, IMAGEMANAGER->findImage("씬2_1픽셀"), IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(), RGB(255, 255, 0), &_isWall);
			if (_isWall)
			{
				_status = P_L_WALL_PUSH;
			}
		}
		if (_status == P_R_MOVE)
		{
			_pos.x = PixelColFunction(2, _pos.x, _pos.y, 64, 5, IMAGEMANAGER->findImage("씬2_1픽셀"), IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(), RGB(0, 255, 0), &_isWall);
			if (_isWall)
			{
				_status = P_R_WALL_PUSH;
			}
		}

		//날다가 벽
		if (_status == P_L_FLYING || _status == P_L_FALLING)
		{
			_pos.x = PixelColFunction(3, _pos.x, _pos.y, 64, 5, IMAGEMANAGER->findImage("씬2_1픽셀"), IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(), RGB(255, 255, 0), &_isWall);
		}
		else if (_status == P_R_FLYING || _status == P_R_FALLING)
		{
			_pos.x = PixelColFunction(2, _pos.x, _pos.y, 64, 5, IMAGEMANAGER->findImage("씬2_1픽셀"), IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(), RGB(0, 255, 0), &_isWall);
		}

		// 벽밀기 애니매이션
		if (_isWall)
		{
			if (_status == P_L_WALL_PUSH)
			{
				_motion = KEYANIMANAGER->findAnimation("baleogLeftPushWall");
				_motion->start();
				_isWall = false;
			}
			if (_status == P_R_WALL_PUSH)
			{
				_motion = KEYANIMANAGER->findAnimation("baleogRightPushWall");
				_motion->start();
				_isWall = false;
			}
		}

		//땅 충돌

		if (_status != P_L_ON_LADDER && _status != P_R_ON_LADDER)
		{
			_pos.y = PixelColFunction(0, _pos.x, _pos.y, 64, 10,
				IMAGEMANAGER->findImage("씬2_1픽셀"),
				IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(),
				RGB(255, 0, 0),
				&_isGround);
		}


		if (_isGround)
		{
			if (_status == P_R_FLYING && _isRightMove)
			{
				_status = P_R_MOVE;
				moveMotionStart("right");
			}
			else if (_status == P_L_FLYING && _isLeftMove)
			{
				_status = P_L_MOVE;
				moveMotionStart("left");
			}


			if (_status == P_R_FALLING)
			{
				_hp--;
				if (_hp > 0)
				{
					_status = P_R_STUN;
					_motion->resume();
				}
				else
				{
					_status = P_R_FALL_DEATH;
					_motion = KEYANIMANAGER->findAnimation("baleogRightFallDead");
					_motion->start();
				}

			}
			else if (_status == P_L_FALLING)
			{
				_hp--;
				if (_hp > 0)
				{
					_status = P_L_STUN;
					_motion->resume();
				}
				else
				{
					_status = P_L_FALL_DEATH;
					_motion = KEYANIMANAGER->findAnimation("baleogLeftFallDead");
					_motion->start();
				}
			}

			if (_isFlying)
			{
				if (_status == P_L_FLYING)
				{
					_status = P_L_IDLE;
					idleMotionStart("left");
				}
				if (_status == P_R_FLYING)
				{
					_status = P_R_IDLE;
					idleMotionStart("right");
				}
			}

			_isFlyMotion = false;
			_isFlying = false;
		}

		if (_status == P_R_ON_LADDER || _status == P_L_ON_LADDER)
		{
			_isGround = true;
		}
		if (!_isGround)
		{
			if (!_isDeadAni)
			{
				_vec.y = 6.0f;
				_pos.y += _vec.y;
			}
			if (!_isFlying)
			{
				_fallStartPos.x = _pos.x;
				_fallStartPos.y = _pos.y;
			}
			_isFlying = true;

			if (_status == P_R_MOVE)
				_status = P_R_FLYING;
			if (_status == P_L_MOVE)
				_status = P_L_FLYING;

			if (!_isFlyMotion)
			{
				_isFlyMotion = true;
				if (_status == P_R_FLYING)
				{
					fallMotionStart("right");
				}
				if (_status == P_L_FLYING)
				{
					fallMotionStart("left");
				}
			}
		}
		if (_isFlying)
		{
			if (getDistanceSqr(_pos.x, _pos.y, _fallStartPos.x, _fallStartPos.y) > 300 * 300)
			{
				if (_status == P_R_FLYING)
				{
					_status = P_R_FALLING;
					_motion = KEYANIMANAGER->findAnimation("baleogRightFall");
					_motion->start();
					_motion->pause();
				}
				else if (_status == P_L_FLYING)
				{
					_status = P_L_FALLING;
					_motion = KEYANIMANAGER->findAnimation("baleogLeftFall");
					_motion->start();
					_motion->pause();
				}
			}
		}


		if (_isLadderMotion)
		{
			onLadderMotionStart();
			_isLadderMotion = false;
		}

		if (_status != P_R_ON_LADDER && _status != P_L_ON_LADDER)
		{
			_ladderStatus = P_LADDER_NULL;
		}
		if (_ladderStatus == P_LADDER_PAUSE)
		{
			_motion->pause();
		}

		if (_ladderStatus == P_LADDER_DOWN)
		{
			_motion->resume();
		}

		_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);
	}
}

void baleog::render()
{

	if (_isAlive)
	{
		_img->aniRender(getMemDC(), (_pos.x - _img->getFrameWidth() / 2) - _cameraX + WINSIZEX / 2,
			(_pos.y - _img->getFrameHeight() / 2) - _cameraY + WINSIZEY / 2,
			_motion);

		//olaf _status 확인용
		char str[128];
		sprintf_s(str, "%d", _status, strlen(str));
		TextOut(getMemDC(), 150, 100, str, strlen(str));
	}
	if (_isFire)
	{
		if (_isArrowDirection)
		{
			_arowImg[1]->render(getMemDC(), _arrowPos.x - _cameraX + WINSIZEX / 2, _arrowPos.y - _cameraY + WINSIZEY / 2);
		}
		else
		{
			_arowImg[0]->render(getMemDC(), _arrowPos.x - _cameraX + WINSIZEX / 2, _arrowPos.y - _cameraY + WINSIZEY / 2);
		}
	}
	//Rectangle(getMemDC(), _arrowRc.left - _cameraX + WINSIZEX / 2,
	//	_arrowRc.top - _cameraY + WINSIZEY / 2,
	//	_arrowRc.right - _cameraX + WINSIZEX / 2,
	//	_arrowRc.bottom - _cameraY + WINSIZEY / 2);
}

void baleog::move()
{
	if (!_isDeadAni && _isPlaying)
	{
		if (_isRightMove)
		{
			_vec.x += 3.0f;
		}
		else if (_isLeftMove)
		{
			_vec.x -= 3.0f;
		}

		if (_ladderStatus == P_LADDER_UP)
		{
			_vec.y -= 3.0f;
		}

		if (_ladderStatus == P_LADDER_DOWN)
		{
			_vec.y += 3.0f;
		}
	}
}

void baleog::olafKeyInput()
{
	if (_isPlaying && _isAlive)
	{
		if (_hp > 0)
		{
			if (KEYMANAGER->isOnceKeyDown('D'))
			{
				_hp--;

				if (_hp <= 0)
				{
					_motion = KEYANIMANAGER->findAnimation("baleogRightHitDead");
					_motion->start();
				}

			}
			if (_status != P_R_STUN && _status != P_L_STUN)
			{
				if (!_isFlying)
				{

					if (KEYMANAGER->isOnceKeyDown('X'))
					{
						if (_status == P_L_IDLE || _status == P_L_MOVE)
						{
							_status = P_L_SKILL_ONE;
							swordAttackMotionStart("left");
						}
						else if (_status == P_R_IDLE || _status == P_R_MOVE)
						{
							_status = P_R_SKILL_ONE;
							swordAttackMotionStart("right");
						}
					}
					else if (KEYMANAGER->isOnceKeyDown('Z'))
					{
						if (!_isFire)
						{
							if (_status == P_L_IDLE || _status == P_L_MOVE)
							{
								_status = P_L_SKILL_TWO;
								bowAttackMotionStart("left");
								//arrowFire();
								_isArrowDirection = true;
							}
							else if (_status == P_R_IDLE || _status == P_R_MOVE)
							{
								_status = P_R_SKILL_TWO;
								bowAttackMotionStart("right");
								//arrowFire();
								_isArrowDirection = false;
							}
						}
					}

					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						_status = P_R_MOVE;
						moveMotionStart("right");
						_isRightMove = true;
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						_status = P_L_MOVE;
						moveMotionStart("left");
						_isLeftMove = true;
					}
					if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
					{
						_motion_Count = 0;
						if (_status != P_R_STUN || _status != P_R_ON_LADDER)
						{
							_status = P_R_IDLE;
							idleMotionStart("right");
						}
						_isRightMove = false;
					}
					if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
					{
						_motion_Count = 0;
						if (_status != P_L_STUN || _status != P_L_ON_LADDER)
						{
							_status = P_L_IDLE;
							idleMotionStart("left");
						}
						_isLeftMove = false;
					}


				}
				else
				{
					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						if (_status != P_R_STUN) _isRightMove = true;

						if (_status == P_L_FLYING)
						{
							_status = P_R_FLYING;
							fallMotionStart("right");
						}

						if (_status == P_L_FALLING)
						{
							_status = P_R_FALLING;
							_motion = KEYANIMANAGER->findAnimation("baleogRightFall");
							_motion->start();
							_motion->pause();
						}
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						if (_status != P_L_STUN) _isLeftMove = true;

						if (_status == P_R_FLYING)
						{
							_status = P_L_FLYING;
							fallMotionStart("left");
						}

						if (_status == P_R_FALLING)
						{
							_status = P_L_FALLING;
							_motion = KEYANIMANAGER->findAnimation("baleogLeftFall");
							_motion->start();
							_motion->pause();
						}
					}
					if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
					{
						_isRightMove = false;
					}
					if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
					{
						_isLeftMove = false;
					}
				}
			}
		}
	}
	// 플레이중이 아니고 상태가 움직이는거였으면 idle로
	if (!_isPlaying && _status == P_R_MOVE)
	{
		_motion_Count = 0;
		_status = P_R_IDLE;
		idleMotionStart("right");
	}
	else if (!_isPlaying && _status == P_L_MOVE)
	{
		_motion_Count = 0;
		_status = P_L_IDLE;
		idleMotionStart("left");
	}

	// ladder more think
	//if(KEYMANAGER->isOnceKeyUP

	// hit is later

	// wall push after the map is created

	// all death after the map is created

	// all airflying is after the map is created

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
				break;
			case 1:
				_status = P_R_MOTION_TWO;
				break;
			}
		}
	}
	else if (_status == P_L_IDLE)
	{
		_motion_Count += TIMEMANAGER->getElpasedTime();
		if (_motion_Count >= 5)
		{
			int rand = RND->getInt(2);

			switch (rand)
			{
			case 0:
				_status = P_L_MOTION_ONE;
				break;

			case 1:
				_status = P_L_MOTION_TWO;
				break;
			}
		}
	}
}

void baleog::arrowFire()
{
	if (!_isFire)
	{
		if(_status == P_R_SKILL_TWO)	_arrowPos.x = _rc.right;
		else if (_status == P_L_SKILL_TWO)	_arrowPos.x = _rc.left - _arowImg[0]->GetWidth();

		_arrowPos.y = _pos.y;
		_arrowStartPos.x = _arrowPos.x;
		_arrowStartPos.y = _arrowPos.y;
		_arrowRc = RectMake(_arrowPos.x, _arrowPos.y, 100, 10);
		_isFire = true;
	}
}

void baleog::arrowMove(bool isArrowDirection)
{
	if (_isFire)
	{
		if (_isArrowDirection)
		{
			_arrowPos.x -= 10.0f;
		}
		else if (!_isArrowDirection)
		{
			_arrowPos.x += 10.0f;
		}
		_arrowRc = RectMake(_arrowPos.x, _arrowPos.y, 100, 10);
		
		if (getDistanceSqr(_arrowPos.x, _arrowPos.y, _arrowStartPos.x, _arrowStartPos.y) > 1000 * 1000)
		{
			_isFire = false;
			_arrowRc = RectMake(-100, -100, 100, 10);
		}
	}
}

void baleog::idleMotionStart(string direction)
{
	if (direction == "right")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogRightIdle");
		_motion->start();
	}
	else if (direction == "left")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogLeftIdle");
		_motion->start();
	}
}

void baleog::moveMotionStart(string direction)
{
	if (direction == "right")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogRightMove");
		_motion->start();
	}
	else if (direction == "left")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogLeftMove");
		_motion->start();
	}
}

void baleog::fallMotionStart(string direction)
{
	if (direction == "right")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogRightFlying");
		_motion->start();
	}
	else if (direction == "left")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogLeftFlying");
		_motion->start();
	}
}

void baleog::onLadderMotionStart()
{
	_motion = KEYANIMANAGER->findAnimation("baleogOnLadder");
	_motion->start();
}

void baleog::swordAttackMotionStart(string direction)
{
	int rndNum = RND->getInt(2);
	if (rndNum == 0)
	{
		if (direction == "right")
		{
			_motion = KEYANIMANAGER->findAnimation("baleogRightAttack1");
			_motion->start();
		}
		else if (direction == "left")
		{
			_motion = KEYANIMANAGER->findAnimation("baleogLeftAttack1");
			_motion->start();
		}
	}
	else
	{
		if (direction == "right")
		{
			_motion = KEYANIMANAGER->findAnimation("baleogRightAttack2");
			_motion->start();
		}
		else if (direction == "left")
		{
			_motion = KEYANIMANAGER->findAnimation("baleogLeftAttack2");
			_motion->start();
		}
	}
}

void baleog::bowAttackMotionStart(string direction)
{
	if (direction == "right")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogRightBow");
		_motion->start();
	}
	else if (direction == "left")
	{
		_motion = KEYANIMANAGER->findAnimation("baleogLeftBow");
		_motion->start();
	}
}

void baleog::rightIdle(void* obj)
{
	baleog* Baleog = (baleog*)obj;

	if (Baleog->_status == P_R_SKILL_TWO)
	{
		Baleog->arrowFire();
	}


	Baleog->setCharacterStatus(P_R_IDLE);
	Baleog->setCharacterMotion(KEYANIMANAGER->findAnimation("baleogRightIdle"));
	Baleog->getCharacterMotion()->start();
}

void baleog::leftIdle(void* obj)
{
	baleog* Baleog = (baleog*)obj;


	if (Baleog->_status == P_L_SKILL_TWO)
	{
		Baleog->arrowFire();
	}

	Baleog->setCharacterStatus(P_L_IDLE);
	Baleog->setCharacterMotion(KEYANIMANAGER->findAnimation("baleogLeftIdle"));
	Baleog->getCharacterMotion()->start();
}

void baleog::hitDead(void * obj)
{
	baleog* Baleog = (baleog*)obj;

	Baleog->_isAlive = false;
	Baleog->_hp = 0;
}
