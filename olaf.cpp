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
	IMAGEMANAGER->addFrameImage("pixxelMap", "images/maps/stage1pixel.bmp", 0, 0, 3904, 1456, true, RGB(255, 0, 255));
	map = IMAGEMANAGER->findImage("pixxelMap");
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
																																				 
	int rightPushWall[] = { 64,65,66,67 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightPushWall", "olaf_Sprite", rightPushWall, 4, 10, true);											 //오른쪽 벽밀기
																																				 
	int leftPushWall[] = { 71,70,69,68 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftPushWall", "olaf_Sprite", leftPushWall, 4, 10, true);					   						 //왼쪽  벽밀기
																																				 
	int rightShiledUpFall[] = { 56,57 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpfFall", "olaf_Sprite", rightShiledUpFall, 2, 10, true);									 //오른쪽 방패올린 fall
																																				 
	int leftShiledUpFall[] = { 61,60 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFall", "olaf_Sprite", leftShiledUpFall, 2, 10, true);									 //왼쪽  방패올린 fall
																																				 
	int rightShiledUpFallMove[] = { 58,59 };																									 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpFallMove", "olaf_Sprite", rightShiledUpFallMove, 2, 10, true);							 //오른쪽 방패올린 fall Move
																																				 
	int leftShiledUpFallMove[] = { 62,61 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFallMove", "olaf_Sprite", leftShiledUpFallMove, 2, 10, true);							 //왼쪽   방패올린 fall Move
																																				 
	int rightShiledDownFall[] = { 4,5 };																										 
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownFall", "olaf_Sprite", rightShiledDownFall, 2, 10, true);								 //오른쪽 방패내린 fall
																																				 
	int leftShiledDownFall[] = { 7,6 };																											 
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownFall", "olaf_Sprite", leftShiledDownFall, 2, 10, true);								 //왼쪽   방패내린 fall

	int rightFallDown[] = { 72,73,74,75,76 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightFallDown", "olaf_Sprite", rightFallDown, 5, 10, true);											//오른쪽 추락 (damage)

	int leftFallDown[] = { 84, 83, 82, 81, 80 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftFallDown", "olaf_Sprite", leftFallDown, 5, 10, true);											//왼쪽  추락(damage)

	int rightFallDownDead[] = { 77,78,79 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightFallDownDead", "olaf_Sprite", rightFallDownDead, 3, 10, false);									//오른쪽 추락사

	int leftFallDownDead[] = { 87,86,85 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftFallDownDead", "olaf_Sprite", leftFallDownDead, 3, 10, false);									//왼쪽   추락사

	int onLadder[] = { 48,49,50,51 };
	KEYANIMANAGER->addArrayFrameAnimation("olafOnLadder", "olaf_Sprite", onLadder, 4, 10, true);													//사다리에 올라탐

	int onLadderEnd[] = { 52,53 };
	KEYANIMANAGER->addArrayFrameAnimation("olafOnLadder", "olaf_Sprite", onLadderEnd, 2, 10, true);													//사다리 끝자락 도착

	int rightHit[] = { 54 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightHit", "olaf_Sprite", rightHit, 1, 15, false);													//오른쪽 적에게 맞음

	int leftHit[] = { 55 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftHit", "olaf_Sprite", leftHit, 1, 15, false);														//왼쪽   적에게 맞음

	int rightHitDead[] = { 88,89,90,91,92,93,94 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightHitDead", "olaf_Sprite", rightHitDead, 7, 10, false);											//오른쪽 맞아 죽음

	int leftHitDead[] = { 102,101,100,99,98,97,96 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftHitDead", "olaf_Sprite", leftHitDead, 5, 10, false);												//왼쪽   맞아 죽음

	int rightWaterDead[] = { 104,105,106,107 };	
	KEYANIMANAGER->addArrayFrameAnimation("olafRightWaterDead", "olaf_Sprite", rightWaterDead, 4, 10, false);										//오른쪽 물에 빠져 죽음

	int leftWaterDead[] = { 111,110,109,108 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftWaterDead", "olaf_Sprite", leftWaterDead, 4, 10, false);											//왼쪽 물에 빠져 죽음

	_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
	_pos.x = 100;
	_pos.y = 120;
	_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);																							//플레이어 rect 위치 초기화
	_isPlaying = true;
	_isShiledUp =false;
	_isGround = false;
	_isWall = false;
	return S_OK;
}

void olaf::release()
{
}

void olaf::update()
{
	characterInfo::update();
	_vec.y = 0;
	_vec.x = 0;
	//울라프 오른쪽 idle
	if (KEYMANAGER->isOnceKeyDown('D') || KEYMANAGER->isOnceKeyDown('F'))
	{
		if (_isShiledUp) _isShiledUp = false;
		else _isShiledUp = true;
		_isMotionPlay = true;
	}

	if (_isShiledUp)
	{
		if (_isMotionPlay)
		{
			if (_status == P_R_IDLE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpIdle");
				_motion->start();
			
			}
			else if (_status == P_R_MOVE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpMove");
				_motion->start();

				if (_isWall)
				{
					_status == P_R_WALL_PUSH;
				}
			}

			if (_status == P_L_IDLE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpIdle");
				_motion->start();
			}
			else if (_status == P_L_MOVE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpMove");
				_motion->start();
			}
			_isMotionPlay = false;
		}
	}
	else if (!_isShiledUp)
	{
		if (_isMotionPlay)
		{
			if (_status == P_R_IDLE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
				_motion->start();
			}
			else if (_status == P_R_MOVE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownMove");
				_motion->start();
			}

			if (_status == P_L_IDLE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownIdle");
				_motion->start();
			}
			else if (_status == P_L_MOVE)
			{
				_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownMove");
				_motion->start();
			}
			_isMotionPlay = false;
		}
	}
	if (_status == P_L_MOVE)
	{
		 _vec.x = PixelColFunction(2, _pos.x, _rc.bottom - ((_rc.bottom - _rc.top) / 2), 20, map, map->getMemDC(), RGB(255, 255, 0), &_isWall);
		if (_isWall)
		{
			_status == P_L_WALL_PUSH;
			_pos.x = _vec.x + _img->getFrameHeight() / 2;
		}
		if (!_isWall)
		{
			_pos.x += _vec.x;
		}
	}
	//if (_status == P_L_WALL_PUSH && _isWall)
	//{
	//	_motion = KEYANIMANAGER->findAnimation("olafLeftPushWall");
	//	_motion->start();
	//}
	move();

	_vec.y = PixelColFunction(0, _rc.left + ((_rc.right - _rc.left)/2), _rc.bottom-10,20, map, map->getMemDC(), RGB(255, 0, 0),&_isGround);
	
	if (!_isGround)
	{
		_vec.y = 3.0f;
		_pos.y += _vec.y;
	}
	else
	{
		_pos.y = _vec.y - _img->getFrameHeight()/2;
	}


	_rc = RectMakeCenter(_pos.x, _pos.y, 128, 128);
}

void olaf::render()
{
	Rectangle(getMemDC(), _rc);
	_img->aniRender(getMemDC(), _pos.x-_img->getFrameWidth()/2, _pos.y-_img->getFrameHeight()/2, _motion);

	//olaf _status 확인용
	char str[128];
	sprintf_s(str, "%d", _status, strlen(str));
	TextOut(getMemDC(), 100, 100, str, strlen(str));	

}

void olaf::move()
{
	if (_status == P_R_MOVE)
	{
		_vec.x += 5 ;
	}
	if (_status == P_L_MOVE)
	{
		_vec.x -= 5;
	}
}
