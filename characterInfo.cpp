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
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_status = P_L_MOVE;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_motion_Count = 0;
			_status = P_R_IDLE;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_motion_Count = 0;
			_status = P_L_IDLE;
		}
	}
	
	// 플레이중이 아니고 상태가 움직이는거였으면 idle로
	if (!_isPlaying && _status == P_R_MOVE)
	{
		_motion_Count = 0;
		_status = P_R_IDLE;
	}
	else if (!_isPlaying && _status == P_L_MOVE)
	{
		_motion_Count = 0;
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

void characterInfo::render()
{
}

void characterInfo::move()
{
}

