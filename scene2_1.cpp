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
	IMAGEMANAGER->addImage("스테이지", "images/maps/stage1.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImg = IMAGEMANAGER->findImage("스테이지");

	//===========픽셀충돌실험용============
	IMAGEMANAGER->addImage("씬2_1픽셀", "images/maps/stage1pixel.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImgPixel = IMAGEMANAGER->findImage("씬2_1픽셀");
	//===========픽셀충돌실험용============

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
			_camera->ChangeCharFunc(true, true, _eric->getPos().x, _eric->getPos().y, 0);
		}
		if (playerSelect == 2)
		{
		}
	}

	//2019.01.17 오후11시추가 ===================
	_eric->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
	//2019.01.17 오후11시추가 ===================
	_eric->update();

	if (playerSelect == 1)
	{
		//2019.01.17 오후11시추가 ===================
		_camera->UpdatePlayerPos(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
		_camera->update();
		//2019.01.17 오후11시추가 ===================
	}
	if (playerSelect == 2)
	{
	}
}

void scene2_1::render()
{
	_mapImg->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_mapImgPixel->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_eric->render();
}
