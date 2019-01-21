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

	_pm = new playerMgr;
	_pm->init();

	playerSelect = 0;

	//	재만 추가
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
	// 재만 추가: invenMode on/Off : '~'
	if (KEYMANAGER->isOnceKeyDown(VK_OEM_3))
	{
		if (_isInvenMode)		_isInvenMode = false;
		else if (!_isInvenMode)	_isInvenMode = true;
	}


	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(false);
		//와일문 지움
		playerSelect++;

		if(playerSelect == P_BALEOG)
		//발록 나오고 아래 이프문으로 사용할것
		//if (playerSelect == OUT_OF_RANGE)
		{
			playerSelect = P_ERIC;
		}

		if (playerSelect == P_ERIC)
		{
			_camera->ChangeCharFunc(true, true, _pm->getVCharInfo()[P_ERIC]->getPos().x, _pm->getVCharInfo()[P_ERIC]->getPos().y, 0);
		}
		//엘스이프 수정 + 내용추가 181533 김도형
		else if (playerSelect == P_OLAF)
		{
			_camera->ChangeCharFunc(true, true, _pm->getVCharInfo()[P_OLAF]->getPos().x, _pm->getVCharInfo()[P_OLAF]->getPos().y, 0);
		}
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(true);

		//	재만추가 : inven한테 현재 charIdx알려줌 , 그에 따른 얼굴 출력
		_invenUI->setSelectCharIdx(playerSelect);
		_invenUI->FaceSelectFunc();


		//엘스이프 수정 + 내용추가 181533 김도형
////////////////////////////////////////////////////////////////////////////////////		else if (playerSelect == P_BALEOG)
////////////////////////////////////////////////////////////////////////////////////		{
////////////////////////////////////////////////////////////////////////////////////			//_camera->ChangeCharFunc(true, true, _baleog->getPos().x, _baleog->getPos().y, 0);
////////////////////////////////////////////////////////////////////////////////////		}
	}
	//2019.01.17 오후11시추가 ===================
	//_eric->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
	//2019.01.17 오후11시추가 ===================
	//_eric->update();
	

	//	재만추가 : 인벤모드가 아니면, 카메라업뎃/ 적용
	if (!_isInvenMode)
	{
		if (playerSelect == P_ERIC)
		{
			//2019.01.17 오후11시추가 ===================
			//_camera->UpdatePlayerPos(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
			//_camera->update();
			//2019.01.17 오후11시추가 ===================
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
