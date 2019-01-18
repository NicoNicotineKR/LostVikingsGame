#include "stdafx.h"
#include "characterInfo.h"


characterInfo::characterInfo()
{
}


characterInfo::~characterInfo()
{
}

HRESULT characterInfo::init()
{
	_status = P_R_IDLE;

	_speed = 5.0f;

	return S_OK;
}

void characterInfo::release()
{
}

void characterInfo::update()
{
	if (_isPlaying && !_isFlying) 
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_status = P_R_MOVE;
			_isMotionPlay = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_status = P_L_MOVE;
			_isMotionPlay = true;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_motion_Count = 0;
			_status = P_R_IDLE;
			_isMotionPlay = true;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_motion_Count = 0;
			_status = P_L_IDLE;
			_isMotionPlay = true;
		}
	}
	
	// �÷������� �ƴϰ� ���°� �����̴°ſ����� idle��
	if (!_isPlaying && _status == P_R_MOVE)
	{
		_motion_Count = 0;
		_isMotionPlay = true;
		_status = P_R_IDLE;
	}
	else if (!_isPlaying && _status == P_L_MOVE)
	{
		_motion_Count = 0;
		_isMotionPlay = true;
		_status = P_L_IDLE;
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
				_isMotionPlay = true;
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
				_isMotionPlay = true;
			case 0:
				_status = P_L_MOTION_ONE;
				break;

			case 1:
				_status = P_L_MOTION_TWO;
				break;
			}
		}
	}

	//===========�������߰�===============
	//===========�ȼ��浹�����============
	PixelCrash();
	//===========�ȼ��浹�����============
	
}

void characterInfo::render()
{
}

void characterInfo::move()
{
}

//===========�ȼ��浹�����============
void characterInfo::PixelCrash()
{
	//Ž������� ���� �̹����� �ִ���ġ�� ���ٴ�
	_probeY = _rc.bottom;

	for (int i = _probeY - 10; i < _probeY + 10; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("��2_1�ȼ�")->getMemDC(), _pos.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		_r = r;
		_g = g;
		_b = b;

		if ((_r == 100 && _g == 0 && _b == 0))
		{
			_pos.y = i - (_rc.bottom - _rc.top);
			break;
		}
	}
}
//===========�ȼ��浹�����============

//2019.01.17 ����11���߰� ===================
void characterInfo::UpdateCameraPos(float _cameraX, float _cameraY)
{
	this->setCameraX(_cameraX);
	this->setCameraY(_cameraY);
}
//2019.01.17 ����11���߰� ===================
