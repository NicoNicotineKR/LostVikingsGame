#include "stdafx.h"
#include "camera.h"


camera::camera()
{
}


camera::~camera()
{
}

HRESULT camera::init()
{
	//카메라중심
	_camerax = WINSIZEX/2;
	_cameray = WINSIZEY/2;

	//처음엔 플레이어를 바꾸지않음
	playerChange = false;

	//일정시간뒤에 플레이어고정 (혹시모를 수리용)
	countFix = 0;

	return S_OK;
}

void camera::release()
{
}

void camera::update(float playerx, float playery,float speed, image* map)
{
	_cameraSpeed = speed;
	_playerx = playerx;
	_playery = playery;
	_NowMap = map;

	// Tap누를시 영웅을 바꿈 - 바꿈모드
	//바꿈모드일때
	if (playerChange == true)
	{
		PlayerChangeMode();
	}

	// 카메라가 플레이어 추적 - 추격모드
	//카메라가 플레이어 추격중일때
	if (playerChange == false)
	{
		PlayerChaseMode();
	}
}

void camera::render()
{
	sprintf_s(str, "카메라x : %f, 카메라y : %f , 목적지x : %f, 목적지y : %f , 플레이어선택 : %d ,예비용카운트 : %d", _camerax, _cameray,_posX,_posY, playerChange, countFix);
	TextOut(getMemDC(), 30, 140, str, strlen(str));
}

// Tap누를시 영웅을 바꿈 - 바꿈모드
void camera::PlayerChangeMode()
{
	if (posInit == true)
	{
		PosInitFuc();
	}

	// 카메라 마지막이동 뻑나는거방지
	CameraMoveFunc();
	//일정시간뒤에 플레이어고정 (혹시모를 수리용)
	CameraFix();
}
//_posX,_posY한번만실행
void camera::PosInitFuc()
{
	//다음좌표가 카메라 자르기 범위를 벗어날경우 방지 (예외처리)
	if (_posX < WINSIZEX / 2)
	{
		_posX = WINSIZEX / 2;
	}
	if (_posX > _NowMap->GetWidth() - WINSIZEX / 2)
	{
		_posX = _NowMap->GetWidth() - WINSIZEX / 2;
	}
	if (_posY < WINSIZEY / 2)
	{
		_posY = WINSIZEY / 2;
	}
	if (_posY > _NowMap->GetHeight() - WINSIZEY / 2)
	{
		_posY = _NowMap->GetHeight() - WINSIZEY / 2;
	}

	posInit = false;
}
//카메라 마지막이동 뻑나는거방지
void camera::CameraMoveFunc()
{
	//카메라는 가지고온 속도만큼 빼주지만,
	if (_camerax < _posX)
	{
		_camerax += _cameraSpeed;

		//다음이동값이 플레이어스피드보다 빨라서 넘어가는거 방지 (예외처리)
		if (_posX - _camerax < _cameraSpeed)
		{
			_camerax = _posX;
		}
	}
	if (_cameray < _posY)
	{
		_cameray += _cameraSpeed;
		if (_posY - _cameray < _cameraSpeed)
		{
			_cameray = _posY;
		}
	}
	if (_camerax > _posX)
	{
		_camerax -= _cameraSpeed;
		if (_camerax - _posX < _cameraSpeed)
		{
			_camerax = _posX;
		}
	}
	if (_cameray > _posY)
	{
		_cameray -= _cameraSpeed;
		if (_cameray - _posY < _cameraSpeed)
		{
			_cameray = _posY;
		}
	}

	//플레이어가 원하는 목적지를 도착했을시
	if ((_camerax == _posX) && (_cameray == _posY))
	{
		//바꿈모드 해제
		playerChange = false;
	}
}
//일정시간뒤에 플레이어고정 (혹시모를 수리용)
void camera::CameraFix()
{
	countFix++;

	//1000프레임 이상일때 그냥강제 수리
	if (countFix > COUNT)
	{
		_camerax = _posX;
		_cameray = _posY;
	}
}

//플레이어 정보가져옴
void camera::ChangeCharFunc(bool isPlayerChange, bool isPosInit, float posX, float posY, int CountFix)
{
	this->SetPlayerChange(isPlayerChange);
	this->SetPosInit(isPosInit);
	this->SetPosX(posX);
	this->SetPosY(posY);
	this->SetCountFix(CountFix);
}


// 카메라가 플레이어 추적 - 추격모드
void camera::PlayerChaseMode()
{
	_camerax = _playerx;
	_cameray = _playery;

	DontGoOutMapFuc();
}
// 플레이어가 카메라자르기 랜더범위값을 넘어가면 해당위치는 추격하지않음 (예외처리)
void camera::DontGoOutMapFuc()
{
	if (_camerax < WINSIZEX / 2)
	{
		_camerax = WINSIZEX / 2;
	}
	if (_cameray < WINSIZEY / 2)
	{
		_cameray = WINSIZEY / 2;
	}
	if (_camerax > _NowMap->GetWidth() - WINSIZEX / 2)
	{
		_camerax = _NowMap->GetWidth() - WINSIZEX / 2;
	}
	if (_cameray > _NowMap->GetHeight() - WINSIZEY / 2)
	{
		_cameray = _NowMap->GetHeight() - WINSIZEY / 2;
	}
}


