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
void characterInfo::ericRightStun()
{
	//��������
}
void characterInfo::ericLeftStun()
{
	//������
}
//2019.01.17 ����11���߰� ===================
