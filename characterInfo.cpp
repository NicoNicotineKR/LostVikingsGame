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

	_motion_Count = 0;
	return S_OK;
}

void characterInfo::release()
{
}

void characterInfo::update()
{


	//===========유형우추가===============
	//===========픽셀충돌실험용============
	PixelCrash();
	//===========픽셀충돌실험용============
	
}

void characterInfo::render()
{
}

void characterInfo::move()
{
}

//===========픽셀충돌실험용============
void characterInfo::PixelCrash()
{
	//탐사범위는 현제 이미지가 있는위치의 땅바닥
	_probeY = _rc.bottom;

	for (int i = _probeY - 10; i < _probeY + 10; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("씬2_1픽셀")->getMemDC(), _pos.x, i);

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
//===========픽셀충돌실험용============

//2019.01.17 오후11시추가 ===================
void characterInfo::UpdateCameraPos(float _cameraX, float _cameraY)
{
	this->setCameraX(_cameraX);
	this->setCameraY(_cameraY);
}
void characterInfo::ericRightStun()
{
	//에릭전용
}
void characterInfo::ericLeftStun()
{
	//응없어
}
//2019.01.17 오후11시추가 ===================
