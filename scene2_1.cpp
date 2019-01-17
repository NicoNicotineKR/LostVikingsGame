#include "stdafx.h"
#include "scene2_1.h"


scene2_1::scene2_1()
{
}


scene2_1::~scene2_1()
{
}

HRESULT scene2_1::init()
{
	//_player = new player;
	//_player->init();
	//_player2 = new player2;
	//_player2->init();

	IMAGEMANAGER->addImage("스테이지", "images/maps/stage1.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImg = IMAGEMANAGER->findImage("스테이지");


	_eric = new eric;
	_eric->init();

	playerSelect = 1;

	return S_OK;
}

void scene2_1::release()
{
}

void scene2_1::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		while (1)
		{
			playerSelect++;
			if (playerSelect == 3)
			{
				playerSelect = 1;
			}
			break;
		}

		if (playerSelect == 1)
		{
			//1.카메라체인지모드true,2.pos초기화모드on,_플레이어x좌표,_플레이어y좌표, count0 연산으로 초기화해부분
		//	_camera->ChangeCharFunc(true, true, _player2->Getplayerx(), _player2->Getplayery(), 0);
			_camera->ChangeCharFunc(true, true, _eric->getPos().x, _eric->getPos().y, 0);
		}
		if (playerSelect == 2)
		{
			//1.카메라체인지모드true,2.pos초기화모드on,_플레이어x좌표,_플레이어y좌표, count0 연산으로 초기화해부분
		//	_camera->ChangeCharFunc(true, true, _player->Getplayerx(), _player->Getplayery(), 0);
		}
	}

	//_player->update(playerSelect, _camera->Getmapx(), _camera->Getmapy());
	//_player2->update(playerSelect, _camera->Getmapx(), _camera->Getmapy());
	_eric->update(true, _camera->Getmapx(), _camera->Getmapy());

	if (playerSelect == 1)
	{
		//카메라에게 정보를줌 = 1캐릭터선택시 1.플레이어 x좌표,플레이어y좌표,카메라변환속도,맵이미지
	//	_camera->update(_player->Getplayerx(), _player->Getplayery(), 5, _mapImg);
		_camera->update(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
	}
	if (playerSelect == 2)
	{
		//카메라에게 정보를줌 = 2캐릭터선택시 1.플레이어 x좌표,플레이어y좌표,카메라변환속도,맵이미지
	//	_camera->update(_player2->Getplayerx(), _player2->Getplayery(), 5, _mapImg);
	}
}

void scene2_1::render()
{
	IMAGEMANAGER->render("스테이지", getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_eric->render();

	//_player->render();
	//_player2->render();
}
