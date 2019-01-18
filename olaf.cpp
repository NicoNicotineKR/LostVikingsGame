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

	_img = IMAGEMANAGER->addFrameImage("olaf_Sprite", "images/character/olaf_Sprite.bmp", 0, 0, 1024, 1664, 8, 13, true, RGB(255, 0, 255));			//플레이어 이미지 초기화

	_rc = RectMake(WINSIZEX / 2, WINSIZEY / 2, 128, 128);																						//플레이어 rect 위치 초기화

	int rightShiledDownIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownIdle", "olaf_Sprite", rightShiledDownIdle, 1, 6, true);							 //오른쪽 방패내린 idle

	int leftShiledDownIdle[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownIdle", "olaf_Sprite", leftShiledDownIdle, 1, 6, true);								 //왼쪽   방패내린 idle

	int rightShiledUpIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpIdle", "olaf_Sprite", rightShiledUpIdle, 1, 6, true);								 //오른쪽 방패올린 idle

	int leftShiledUpIdle[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpIdle", "olaf_Sprite", leftShiledUpIdle, 1, 6, true);									 //왼쪽   방패올린 idle

	int rightShiledDownMove[] = { 8,9,10,11,12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownMove", "olaf_Sprite", rightShiledDownMove, 8, 10, true);							 //오른쪽 방패내린 move

	int leftShiledDownMove[] = { 23,22,21,20,19,18,17,16 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownMove", "olaf_Sprite", leftShiledDownMove, 8, 10, true);							 //왼쪽   방패내린 move

	int rightShiledUpMove[] = { 24,25,26,27,28,29,30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpMove", "olaf_Sprite", rightShiledUpMove, 8, 10, true);								 //오른쪽 방패올린 move

	int leftShiledUpMove[] = { 39,38,37,36,35,34,33,32 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpMove", "olaf_Sprite", leftShiledUpMove, 8, 10, true);								 //왼쪽   방패올린 move

	int rightPushWall[] = { 64,65,66,67 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightPushWall", "olaf_Sprite", rightPushWall, 4, 10, true);										 //오른쪽 벽밀기

	int leftPushWall[] = { 71,70,69,68 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftPushWall", "olaf_Sprite", leftPushWall, 4, 10, true);					   				     //왼쪽  벽밀기

	int rightShiledUpFall[] = { 56,57 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpfFall", "olaf_Sprite", rightShiledUpFall, 2, 5, true);								 //오른쪽 방패올린 fall

	int leftShiledUpFall[] = { 61,60 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFall", "olaf_Sprite", leftShiledUpFall, 2, 5, true);									 //왼쪽  방패올린 fall

	int rightShiledUpFallMove[] = { 58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpFallMove", "olaf_Sprite", rightShiledUpFallMove, 2, 5, true);						 //오른쪽 방패올린 fall Move

	int leftShiledUpFallMove[] = { 62,61 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpFallMove", "olaf_Sprite", leftShiledUpFallMove, 2, 5, true);							 //왼쪽   방패올린 fall Move

	int rightShiledDownFall[] = { 4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownFall", "olaf_Sprite", rightShiledDownFall, 2, 5, true);							 //오른쪽 방패내린 fall

	int leftShiledDownFall[] = { 7,6 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownFall", "olaf_Sprite", leftShiledDownFall, 2, 5, true);								 //왼쪽   방패내린 fall



	_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY / 2;

	_isPlaying = true;
	_isShiledUp = false;

	return S_OK;
}

void olaf::release()
{
}

void olaf::update(int characterSelect, float cameraX, float cameraY)
{
	characterInfo::update(characterSelect, cameraX, cameraY);

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

}

void olaf::render()
{
	_img->aniRender(getMemDC(), _pos.x, _pos.y, _motion);


	//olaf _status 확인용
	char str[128];
	sprintf_s(str, "%d", _status, strlen(str));
	TextOut(getMemDC(), 100, 100, str, strlen(str));

}

void olaf::move()
{
}
