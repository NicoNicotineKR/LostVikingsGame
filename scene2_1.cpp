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

	IMAGEMANAGER->addImage("��������", "images/maps/stage1.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImg = IMAGEMANAGER->findImage("��������");


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
			//1.ī�޶�ü�������true,2.pos�ʱ�ȭ���on,_�÷��̾�x��ǥ,_�÷��̾�y��ǥ, count0 �������� �ʱ�ȭ�غκ�
		//	_camera->ChangeCharFunc(true, true, _player2->Getplayerx(), _player2->Getplayery(), 0);
			_camera->ChangeCharFunc(true, true, _eric->getPos().x, _eric->getPos().y, 0);
		}
		if (playerSelect == 2)
		{
			//1.ī�޶�ü�������true,2.pos�ʱ�ȭ���on,_�÷��̾�x��ǥ,_�÷��̾�y��ǥ, count0 �������� �ʱ�ȭ�غκ�
		//	_camera->ChangeCharFunc(true, true, _player->Getplayerx(), _player->Getplayery(), 0);
		}
	}

	//_player->update(playerSelect, _camera->Getmapx(), _camera->Getmapy());
	//_player2->update(playerSelect, _camera->Getmapx(), _camera->Getmapy());
	_eric->update(true, _camera->Getmapx(), _camera->Getmapy());

	if (playerSelect == 1)
	{
		//ī�޶󿡰� �������� = 1ĳ���ͼ��ý� 1.�÷��̾� x��ǥ,�÷��̾�y��ǥ,ī�޶�ȯ�ӵ�,���̹���
	//	_camera->update(_player->Getplayerx(), _player->Getplayery(), 5, _mapImg);
		_camera->update(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
	}
	if (playerSelect == 2)
	{
		//ī�޶󿡰� �������� = 2ĳ���ͼ��ý� 1.�÷��̾� x��ǥ,�÷��̾�y��ǥ,ī�޶�ȯ�ӵ�,���̹���
	//	_camera->update(_player2->Getplayerx(), _player2->Getplayery(), 5, _mapImg);
	}
}

void scene2_1::render()
{
	IMAGEMANAGER->render("��������", getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_eric->render();

	//_player->render();
	//_player2->render();
}
