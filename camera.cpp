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
	//ī�޶��߽�
	_camerax = WINSIZEX/2;
	_cameray = WINSIZEY/2;

	//ó���� �÷��̾ �ٲ�������
	playerChange = false;

	//�����ð��ڿ� �÷��̾���� (Ȥ�ø� ������)
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

	// Tap������ ������ �ٲ� - �ٲ޸��
	//�ٲ޸���϶�
	if (playerChange == true)
	{
		PlayerChangeMode();
	}

	// ī�޶� �÷��̾� ���� - �߰ݸ��
	//ī�޶� �÷��̾� �߰����϶�
	if (playerChange == false)
	{
		PlayerChaseMode();
	}
}

void camera::render()
{
	sprintf_s(str, "ī�޶�x : %f, ī�޶�y : %f , ������x : %f, ������y : %f , �÷��̾�� : %d ,�����ī��Ʈ : %d", _camerax, _cameray,_posX,_posY, playerChange, countFix);
	TextOut(getMemDC(), 30, 140, str, strlen(str));
}

// Tap������ ������ �ٲ� - �ٲ޸��
void camera::PlayerChangeMode()
{
	if (posInit == true)
	{
		PosInitFuc();
	}

	// ī�޶� �������̵� �����°Ź���
	CameraMoveFunc();
	//�����ð��ڿ� �÷��̾���� (Ȥ�ø� ������)
	CameraFix();
}
//_posX,_posY�ѹ�������
void camera::PosInitFuc()
{
	//������ǥ�� ī�޶� �ڸ��� ������ ������ ���� (����ó��)
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
//ī�޶� �������̵� �����°Ź���
void camera::CameraMoveFunc()
{
	//ī�޶�� ������� �ӵ���ŭ ��������,
	if (_camerax < _posX)
	{
		_camerax += _cameraSpeed;

		//�����̵����� �÷��̾�ǵ庸�� ���� �Ѿ�°� ���� (����ó��)
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

	//�÷��̾ ���ϴ� �������� ����������
	if ((_camerax == _posX) && (_cameray == _posY))
	{
		//�ٲ޸�� ����
		playerChange = false;
	}
}
//�����ð��ڿ� �÷��̾���� (Ȥ�ø� ������)
void camera::CameraFix()
{
	countFix++;

	//1000������ �̻��϶� �׳ɰ��� ����
	if (countFix > COUNT)
	{
		_camerax = _posX;
		_cameray = _posY;
	}
}

//�÷��̾� ����������
void camera::ChangeCharFunc(bool isPlayerChange, bool isPosInit, float posX, float posY, int CountFix)
{
	this->SetPlayerChange(isPlayerChange);
	this->SetPosInit(isPosInit);
	this->SetPosX(posX);
	this->SetPosY(posY);
	this->SetCountFix(CountFix);
}


// ī�޶� �÷��̾� ���� - �߰ݸ��
void camera::PlayerChaseMode()
{
	_camerax = _playerx;
	_cameray = _playery;

	DontGoOutMapFuc();
}
// �÷��̾ ī�޶��ڸ��� ������������ �Ѿ�� �ش���ġ�� �߰��������� (����ó��)
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


