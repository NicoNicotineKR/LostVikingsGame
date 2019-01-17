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
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownIdle", "olaf_Sprite", rightShiledDownIdle, 1, 6, true);

	int leftShiledDownIdle[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownIdle", "olaf_Sprite", leftShiledDownIdle, 1, 6, true);

	int rightShiledUpIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledUpIdle", "olaf_Sprite", rightShiledUpIdle, 1, 6, true);

	int leftShiledUpIdle[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledUpIdle", "olaf_Sprite", leftShiledUpIdle, 1, 6, true);

	int rightMove[] = { 8,9,10,11,12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("olafRightShiledDownMove", "olaf_Sprite", rightMove, 8, 10, true);

	int leftMove[] = { 16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("olafLeftShiledDownMove", "olaf_Sprite", leftMove, 8, 10, true);

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
	//characterInfo::update();

	//울라프 오른쪽 idle
	if (KEYMANAGER->isOnceKeyDown('D') || KEYMANAGER->isOnceKeyDown('F'))
	{
		if (_isShiledUp) _isShiledUp = false;
		else _isShiledUp = true;
	}
	if (_isShiledUp)
	{
		if (_status == P_R_IDLE)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpIdle");
			_motion->start();
		}
		else if (_status == P_R_MOVE)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpIdle");
			_motion->start();
		}
	}

	if (_status == P_R_IDLE)
	{
		if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownIdle");
			_motion->start();
		}
		else
		{
			_motion = KEYANIMANAGER->findAnimation("olafRightShiledUpIdle");
			_motion->start();
		}
	}
	//울라프 왼쪽 idle
	if (_status == P_L_IDLE)
	{
		if (!_isShiledUp)
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownIdle");
			_motion->start();
		}
		else
		{
			_motion = KEYANIMANAGER->findAnimation("olafLeftShiledUpIdle");
			_motion->start();
		}
	}
	//if (_isMotionPlay)															
	//{
		if (_status == P_R_MOVE)
		{
			if (!_isShiledUp)
			{
				_motion = KEYANIMANAGER->findAnimation("olafRightShiledDownMove");
				_motion->start();
			}
		}
		if (_status == P_L_MOVE)
		{
			if (!_isShiledUp)
			{
				_motion = KEYANIMANAGER->findAnimation("olafLeftShiledDownMove");
				_motion->start();
			}
		}


		//_isMotionPlay = false;
	//}
}

void olaf::render()
{
	_img->aniRender(getMemDC(), _pos.x, _pos.y, _motion);

	char str[128];
	sprintf_s(str, "%d", _status, strlen(str));
	TextOut(getMemDC(), 100, 100, str, strlen(str));

}

void olaf::move()
{
}
