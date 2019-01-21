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
	IMAGEMANAGER->addImage("��������", "images/maps/stage1.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImg = IMAGEMANAGER->findImage("��������");

	//===========�ȼ��浹�����============
	IMAGEMANAGER->addImage("��2_1�ȼ�", "images/maps/stage1pixel.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImgPixel = IMAGEMANAGER->findImage("��2_1�ȼ�");
	//===========�ȼ��浹�����============

	_pm = new playerMgr;
	_pm->init();

	playerSelect = 0;

	//	�縸 �߰�
	{
		_invenUI = new invenUI;
		_invenUI->init();
		_isInvenMode = false;	
	}
	


	return S_OK;
}

void scene2_1::release()
{
}

void scene2_1::update()
{
	// �縸 �߰�: invenMode on/Off : '~'
	if (KEYMANAGER->isOnceKeyDown(VK_OEM_3))
	{
		if (_isInvenMode)		_isInvenMode = false;
		else if (!_isInvenMode)	_isInvenMode = true;
	}


	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(false);
		//���Ϲ� ����
		playerSelect++;

		if(playerSelect == P_BALEOG)
		//�߷� ������ �Ʒ� ���������� ����Ұ�
		//if (playerSelect == OUT_OF_RANGE)
		{
			playerSelect = P_ERIC;
		}

		if (playerSelect == P_ERIC)
		{
			_camera->ChangeCharFunc(true, true, _pm->getVCharInfo()[P_ERIC]->getPos().x, _pm->getVCharInfo()[P_ERIC]->getPos().y, 0);
		}
		//�������� ���� + �����߰� 181533 �赵��
		else if (playerSelect == P_OLAF)
		{
			_camera->ChangeCharFunc(true, true, _pm->getVCharInfo()[P_OLAF]->getPos().x, _pm->getVCharInfo()[P_OLAF]->getPos().y, 0);
		}
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(true);

		//	�縸�߰� : inven���� ���� charIdx�˷��� , �׿� ���� �� ���
		_invenUI->setSelectCharIdx(playerSelect);
		_invenUI->FaceSelectFunc();


		//�������� ���� + �����߰� 181533 �赵��
////////////////////////////////////////////////////////////////////////////////////		else if (playerSelect == P_BALEOG)
////////////////////////////////////////////////////////////////////////////////////		{
////////////////////////////////////////////////////////////////////////////////////			//_camera->ChangeCharFunc(true, true, _baleog->getPos().x, _baleog->getPos().y, 0);
////////////////////////////////////////////////////////////////////////////////////		}
	}
	//2019.01.17 ����11���߰� ===================
	//_eric->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
	//2019.01.17 ����11���߰� ===================
	//_eric->update();
	

	//	�縸�߰� : �κ���尡 �ƴϸ�, ī�޶����/ ����
	if (!_isInvenMode)
	{
		if (playerSelect == P_ERIC)
		{
			//2019.01.17 ����11���߰� ===================
			//_camera->UpdatePlayerPos(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
			//_camera->update();
			//2019.01.17 ����11���߰� ===================
			_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_ERIC]->getPos().x, _pm->getVCharInfo()[P_ERIC]->getPos().y, 5, _mapImg);
		}
		else if (playerSelect == P_OLAF)
		{
			_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_OLAF]->getPos().x, _pm->getVCharInfo()[P_OLAF]->getPos().y, 5, _mapImg);
		}
		/////////////////////////////////////////////////////////////////////////////////	else if (playerSelect == P_BALEOG)
		/////////////////////////////////////////////////////////////////////////////////	{
		/////////////////////////////////////////////////////////////////////////////////		_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_BALEOG]->getPos().x, _pm->getVCharInfo()[P_BALEOG]->getPos().y, 5, _mapImg);
		/////////////////////////////////////////////////////////////////////////////////	}

		_camera->update();
	}
	else if (_isInvenMode)
	{
		_invenUI->update();
	}

	

	for (int i = 0; i < _pm->getVCharInfo().size(); i++)
	{
		_pm->getVCharInfo()[i]->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
		_pm->getVCharInfo()[i]->update();
	}
}

void scene2_1::render()
{
	_mapImg->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_mapImgPixel->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_pm->render();

	_invenUI->render();
}
