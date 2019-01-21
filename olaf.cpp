#include "stdafx.h"
#include "olaf.h"


olaf::olaf()
{
}


olaf::~olaf()
{
}

HRESULT olaf::init()
{
	characterInfo::init();

	_img = IMAGEMANAGER->addFrameImage("olaf_Sprite", "images/character/olaf_Sprite.bmp", 0, 0, 1024, 1920, 8, 15, true, RGB(255, 0, 255));			//플레이어 이미지 초기화

	int rightShiledDownIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownIdle", "olaf_Sprite", rightShiledDownIdle, 1, 10, true);								 //오른쪽 방패내린 idle
																																				 
	int leftShiledDownIdle[] = { 3 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownIdle", "olaf_Sprite", leftShiledDownIdle, 1, 10, true);								 //왼쪽   방패내린 idle
	
	int rightShiledDownIdleMotion[] = { 112,113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownIdleMotion", "olaf_Sprite", rightShiledDownIdleMotion, 4, 10, false);					//오른쪽 방패내린 idle Motion

	int leftShiledDownIdleMotion[] = { 119,118,117,116 };	
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownIdleMotion", "olaf_Sprite", leftShiledDownIdleMotion, 4, 10, false);					//왼쪽 방패 내린 idle Motion

	int rightShiledUpIdle[] = { 1 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpIdle", "olaf_Sprite", rightShiledUpIdle, 1, 10, true);									 //오른쪽 방패올린 idle
																																				 
	int leftShiledUpIdle[] = { 2 };																												 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpIdle", "olaf_Sprite", leftShiledUpIdle, 1, 10, true);									 //왼쪽   방패올린 idle
	
	int rightShiledUpIdleMotion[] = { 120,121,122 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpIdleMotion", "olaf_Sprite", rightShiledUpIdleMotion, 3, 10, false);						//오른쪽 방패 올린 idle Motion

	int leftShiledUpIdleMotion[] = { 125,124,123 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpIdleMotion", "olaf_Sprite", leftShiledUpIdleMotion, 3, 10, false);						//왼쪽  방패 올린 idle Motion

	int rightShiledDownMove[] = { 8,9,10,11,12,13,14,15 };																						 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownMove", "olaf_Sprite", rightShiledDownMove, 8, 10, true);								 //오른쪽 방패내린 move
																																				 
	int leftShiledDownMove[] = { 23,22,21,20,19,18,17,16 };																						 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownMove", "olaf_Sprite", leftShiledDownMove, 8, 10, true);								 //왼쪽   방패내린 move
																																				 
	int rightShiledUpMove[] = { 24,25,26,27,28,29,30,31 };																						 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpMove", "olaf_Sprite", rightShiledUpMove, 8, 10, true);									 //오른쪽 방패올린 move
																																				 
	int leftShiledUpMove[] = { 39,38,37,36,35,34,33,32 };																						 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpMove", "olaf_Sprite", leftShiledUpMove, 8, 10, true);									 //왼쪽   방패올린 move
																																				 
	int rightPushWall[] = { 56,57,58,59 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightPushWall", "olaf_Sprite", rightPushWall, 4, 10, true);											 //오른쪽 벽밀기
																																				 
	int leftPushWall[] = { 63,62,61,60 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftPushWall", "olaf_Sprite", leftPushWall, 4, 10, true);					   						 //왼쪽  벽밀기
																																				 
	int rightShiledUpFall[] = { 48,49 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpFall", "olaf_Sprite", rightShiledUpFall, 2, 10, true);									 //오른쪽 방패올린 fall
																																				 
	int leftShiledUpFall[] = { 55,54 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFall", "olaf_Sprite", leftShiledUpFall, 2, 10, true);									 //왼쪽  방패올린 fall
																																				 
	int rightShiledUpFallMove[] = { 50,51 };																									 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpFallMove", "olaf_Sprite", rightShiledUpFallMove, 2, 10, true);							 //오른쪽 방패올린 fall Move
																																				 
	int leftShiledUpFallMove[] = { 53,52 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFallMove", "olaf_Sprite", leftShiledUpFallMove, 2, 10, true);							 //왼쪽   방패올린 fall Move
																																				 
	int rightShiledDownFall[] = { 4,5 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownFall", "olaf_Sprite", rightShiledDownFall, 2, 10, true);								 //오른쪽 방패내린 fall
																																				 
	int leftShiledDownFall[] = { 7,6 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownFall", "olaf_Sprite", leftShiledDownFall, 2, 10, true);								 //왼쪽   방패내린 fall

	int rightFallDown[] = { 64,65,66,67,68 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightFallDown", "olaf_Sprite", rightFallDown, 5, 3, false, rightIdle, this);							//오른쪽 추락 (damage)

	int leftFallDown[] = { 76, 75, 74, 73, 72 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftFallDown", "olaf_Sprite", leftFallDown, 5, 3, false, leftIdle,this);								//왼쪽  추락(damage)

	int rightFallDownDead[] = { 69,70,71 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightFallDownDead", "olaf_Sprite", rightFallDownDead, 3, 10, false);									//오른쪽 추락사

	int leftFallDownDead[] = { 79,78,77 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftFallDownDead", "olaf_Sprite", leftFallDownDead, 3, 10, false);									//왼쪽   추락사

	int onLadder[] = { 40,41,42,43 };
	KEYANIMANAGER->addArrayFrameAnimation("olafOnLadder", "olaf_Sprite", onLadder, 4, 10, true);													//사다리에 올라탐

	int onLadderEnd[] = { 44,45 };
	KEYANIMANAGER->addArrayFrameAnimation("olafOnLadder", "olaf_Sprite", onLadderEnd, 2, 10, true);													//사다리 끝자락 도착

	int rightHit[] = { 46 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightHit", "olaf_Sprite", rightHit, 1, 15, false);													//오른쪽 적에게 맞음

	int leftHit[] = { 47 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftHit", "olaf_Sprite", leftHit, 1, 15, false);														//왼쪽   적에게 맞음

	int rightHitDead[] = { 80,81,82,83,84,85,86 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightHitDead", "olaf_Sprite", rightHitDead, 7, 10, false);											//오른쪽 맞아 죽음

	int leftHitDead[] = { 94,93,92,91,90,89,88 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftHitDead", "olaf_Sprite", leftHitDead, 5, 10, false);												//왼쪽   맞아 죽음

	int rightWaterDead[] = { 96,97,98,99 };	
	KEYANIMANAGER->addArrayFrameAnimation("olafRightWaterDead", "olaf_Sprite", rightWaterDead, 4, 10, false);										//오른쪽 물에 빠져 죽음

	int leftWaterDead[] = { 103, 102, 101, 100 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftWaterDead", "olaf_Sprite", leftWaterDead, 4, 10, false);											//왼쪽 물에 빠져 죽음

	int rightNostrilDig[] = { 104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightNostrilDig", "olaf_Sprite", rightNostrilDig, 4, 10, false);

	int leftNostrilDig[] = { 111,110,109,108 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftNostrilDig", "olaf_Sprite", leftNostrilDig, 4, 10, false);

	int rightPantsTouch[] = { 112,113,114 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightPantsTouch", "olaf_Sprite", rightPantsTouch, 3, 10, false);

	int leftPantsTouch[] = { 117,116,115 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftPantsTouch", "olaf_Sprite", leftPantsTouch, 3, 10, false);


	_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
	_pos.x = 100;
	_pos.y = 120;
	_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);
	_shiledX = _rc.left;
	_shiledY = _rc.top;
	_shiledWidth = 128;
	_shiledHeight = 20;
	_shiled = RectMakeCenter(_shiledX, _shiledY, _shiledWidth, _shiledHeight);

	_fallStartPos.x = 0;
	_fallStartPos.y = 0;

	_speed = 0;
	_acceleration = 0;
	_isPlaying = false;
	_isShiledUp = false;
	_isGround = false;
	_isWall = false;

	return S_OK;
}

void olaf::release()
{
}

void olaf::update()
{
	olafKeyInput();
	characterInfo::update();
	_vec.y = 0;
	_vec.x = 0;
	RECT temp;
	//if (IntersectRect(&temp, &_sadari, &_rc))
	//{
	//	_status = P_L_FLYING;
	//}

	if (!_isWall)
	{
		move();
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
			_motion = KEYANIMANAGER->findAnimation("olafLeftPushWall");
			_motion->start();
			_isWall = false;
		}
		if (_status == P_R_WALL_PUSH)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightPushWall");
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
		if (!_isShiledUp)
		{
			if (_status == P_R_FALLING)
			{
				_status = P_R_STUN;
				_motion->resume();
			}
			else if (_status == P_L_FALLING)
			{
				_status = P_L_STUN;
				_motion->resume();
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


	if (!_isGround && _status != P_R_ON_LADDER)
	{
		if (_isShiledUp)
		{
			_vec.y = 3.0f;
		}
		else
		{
			_vec.y = 6.0f;
		}

		_pos.y += _vec.y;

		if (!_isFlying)
		{
			_fallStartPos.x = _pos.x;
			_fallStartPos.y = _pos.y;
		}
		_isFlying = true;
		
		if(_status == P_R_MOVE)
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
	if (_isFlying && !_isShiledUp)
	{
		if (getDistanceSqr(_pos.x, _pos.y, _fallStartPos.x, _fallStartPos.y) > 300*300)
		{
			if (_status == P_R_FLYING)
			{
				_status = P_R_FALLING;
				_motion = KEYANIMANAGER->findAnimation("olafRightFallDown");
				_motion->start();
				_motion->pause();
			}
			else if (_status == P_L_FLYING)
			{
				_status = P_L_FALLING;
				_motion = KEYANIMANAGER->findAnimation("olafLeftFallDown");
				_motion->start();
				_motion->pause();
			}
		}
	}
	else if (_isFlying && _isShiledUp)
	{
		_fallStartPos.x = _pos.x;
		_fallStartPos.y = _pos.y;
	}
	_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);
	if (_isShiledUp)
	{
		_shiledWidth = 128;
		_shiledHeight = 20;
		_shiledX = _rc.left;
		_shiledY = _rc.top;
	}
	else
	{
		if (_status == P_R_MOVE || _status == P_R_IDLE)
		{
			_shiledWidth = 20;
			_shiledHeight = 128;
			_shiledX = _rc.right - _shiledWidth;
			_shiledY = _rc.top;
		}
		else if( _status == P_L_MOVE || _status == P_L_IDLE)
		{
			_shiledWidth = 20;
			_shiledHeight = 128;
			_shiledX = _rc.left;
			_shiledY = _rc.top;
		}
	}


	_shiled = RectMake(_shiledX, _shiledY, _shiledWidth, _shiledHeight);
	//_shiled = RectMake(_shiled.left - _cameraX + WINSIZEX / 2, _shiled.top - _cameraY + WINSIZEY / 2, _shiled.right - _cameraX + WINSIZEX / 2, _shiled.bottom - _cameraY + WINSIZEY / 2);
}

void olaf::render()
{
	
	//Rectangle(getMemDC(), _rc.left - _cameraX + WINSIZEX / 2, _rc.top - _cameraY + WINSIZEY / 2, _rc.right - _cameraX + WINSIZEX / 2, _rc.bottom - _cameraY + WINSIZEY / 2);
	
	_img->aniRender(getMemDC(), (_pos.x -_img->getFrameWidth() / 2) - _cameraX + WINSIZEX / 2, 
		(_pos.y - _img->getFrameHeight() / 2) - _cameraY + WINSIZEY / 2, 
		_motion);
	//Rectangle(getMemDC(), _shiled.left - _cameraX + WINSIZEX / 2, _shiled.top - _cameraY + WINSIZEY / 2, _shiled.right - _cameraX + WINSIZEX / 2, _shiled.bottom - _cameraY + WINSIZEY / 2);

	//olaf _status 확인용
	char str[128];
	sprintf_s(str, "%d", _status, strlen(str));
	TextOut(getMemDC(), 100, 100, str, strlen(str));
}

void olaf::move()
{

	if (_status == P_R_MOVE)
	{
		_vec.x += 3.0f;
	}
	else if (_status == P_L_MOVE)
	{
		_vec.x -= 3.0f;
	}

	if (_rightMove)
	{
		_vec.x += 3.0f;
	}
	else if (_leftMove)
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

void olaf::olafKeyInput()
{
	//방패 업다운.
	if (_isPlaying)
	{
		if (_status != P_R_STUN && _status != P_L_STUN)
		{
			if (KEYMANAGER->isOnceKeyDown('Z') || KEYMANAGER->isOnceKeyDown('X'))
			{
				if (_isShiledUp)
				{
					_isShiledUp = false;
				}
				else
				{
					_isShiledUp = true;
					if (_status == P_L_FALLING)
					{
						_status = P_L_FLYING;
					}
				}
				if (_status == P_L_IDLE)
				{
					idleMotionStart("left");
				}
				else if (_status == P_R_IDLE)
				{
					idleMotionStart("right");
				}

				if (_status == P_L_MOVE)
				{
					moveMotionStart("left");
				}
				else if (_status == P_R_MOVE)
				{
					moveMotionStart("right");
				}

				if (_status == P_L_FLYING || _status == P_L_FALLING)
				{

					fallMotionStart("left");
				}
				else if (_status == P_R_FLYING || _status == P_R_FALLING)
				{
					fallMotionStart("right");
				}
			}


			if (!_isFlying)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					_status = P_R_MOVE;
					moveMotionStart("right");
				}
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					_status = P_L_MOVE;
					moveMotionStart("left");
				}
				if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
				{
					_motion_Count = 0;
					if (_status != P_R_STUN)
					{
						_status = P_R_IDLE;
						idleMotionStart("right");
					}
					_rightMove = false;
				}
				if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
				{
					_motion_Count = 0;
					_status = P_L_IDLE;
					idleMotionStart("left");
					_leftMove = false;
				}
			}
			else
			{
				if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
				{
					if (_status != P_R_STUN) _rightMove = true;

					if (_status == P_L_FLYING)
					{
						_status = P_R_FLYING;
						fallMotionStart("right");
					}

					if (_status == P_L_FALLING)
					{
						_status = P_R_FALLING;
						_motion = KEYANIMANAGER->findAnimation("olafRightFallDown");
						_motion->start();
						_motion->pause();
					}
				}
				if (KEYMANAGER->isStayKeyDown(VK_LEFT))
				{
					if (_status != P_L_STUN) _leftMove = true;

					if (_status == P_R_FLYING)
					{
						_status = P_L_FLYING;
						fallMotionStart("left");
					}

					if (_status == P_R_FALLING)
					{
						_status = P_L_FALLING;
						_motion = KEYANIMANAGER->findAnimation("olafLeftFallDown");
						_motion->start();
						_motion->pause();
					}
				}
				if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
				{
					_rightMove = false;
				}
				if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
				{
					_leftMove = false;
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

void olaf::idleMotionStart(string direction)
{
	if (direction == "right")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpIdle");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
			_motion->start();
		}
	}
	else if (direction == "left")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpIdle");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownIdle");
			_motion->start();
		}
	}
}

void olaf::moveMotionStart(string direction)
{
	if (direction == "right")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpMove");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownMove");
			_motion->start();
		}
	}
	else if (direction == "left")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpMove");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownMove");
			_motion->start();
		}
	}
}

void olaf::fallMotionStart(string direction)
{
	if (direction == "right")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpFall");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownFall");
			_motion->start();
		}
	}
	else if (direction == "left")
	{
		if (_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpFall");
			_motion->start();
		}
		else if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownFall");
			_motion->start();
		}
	}
}

void olaf::onLadderMotionStart()
{
	_motion = KEYANIMANAGER->findAnimation("olafOnLadder");
	_motion->start();
}

void olaf::rightIdle(void* obj)
{
	olaf* Olaf = (olaf*)obj;

	Olaf->setCharacterStatus(P_R_IDLE);
	Olaf->setCharacterMotion(KEYANIMANAGER->findAnimation("olafRightShiledDownIdle"));
	Olaf->getCharacterMotion()->start();
}

void olaf::leftIdle(void* obj)
{
	olaf* Olaf = (olaf*)obj;

	Olaf->setCharacterStatus(P_L_IDLE);
	Olaf->setCharacterMotion(KEYANIMANAGER->findAnimation("olafLeftShiledDownIdle"));
	Olaf->getCharacterMotion()->start();
}
