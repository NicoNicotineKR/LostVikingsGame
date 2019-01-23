#include "stdafx.h"
#include "mainmenu.h"


mainmenu::mainmenu()
{
}


mainmenu::~mainmenu()
{
}

HRESULT mainmenu::init()
{
	//IMAGEMANAGER->addImage("vugKings", "images/UI/mainmenuUI/vugKings.bmp", 1024, 768, false, 0x000000);
	_bg = IMAGEMANAGER->findImage("vugKings");
	_isSceneEnd = false;

	_menuUI = new mainmenuUI;
	_menuUI->init();

	//===========옵션을 여기다 박넹================
	IMAGEMANAGER->addFrameImage("optionBG", "images/UI/optionUI/optionBG.bmp", 600, 450, 1, 1, false, 0x000000);
	IMAGEMANAGER->addFrameImage("button_soundvol", "images/UI/optionUI/button_soundvol.bmp", 435, 40, 1, 1, false, 0x000000);
	IMAGEMANAGER->addFrameImage("volumeBarOn", "images/UI/optionUI/volumeBarOn.bmp", 40, 200, 1, 1, false, 0x000000);
	IMAGEMANAGER->addFrameImage("volumeBarOff", "images/UI/optionUI/volumeBarOff.bmp", 40, 200, 1, 1, false, 0x000000);

	_curVol = 3;	//	오프렉트시작idx
	_optionBG = ImgComboinit("optionBG", WINSIZEX / 2, WINSIZEY / 2);
	_soundTxt = ImgComboinit("button_soundvol", WINSIZEX / 2, WINSIZEY / 2 - 150);
	for (int i = 0; i < 10; i++)
	{
		_soundBar[0][i] = ImgComboinit("volumeBarOn", WINSIZEX / 2 - 217 + 20 + (i * 43), WINSIZEY / 2 + 48);
		_soundBar[1][i] = ImgComboinit("volumeBarOff", WINSIZEX / 2 - 217 + 20 + (i * 43), WINSIZEY / 2 + 48);
		if (i < _curVol)
		{
			_isSoundBarOn[i] = true;
		}
		else {
			_isSoundBarOn[i] = false;
		}
		
	}
	_isOptionMode = false;
	




	return S_OK;
}

void mainmenu::release()
{
}

void mainmenu::update()
{
	if (!_isOptionMode)
	{
		_menuUI->update();
	}
	else
	{
		OptionUIUpdate();
	}



	if (_menuUI->getIsPressEnter())
	{
		_menuUI->setIsPressEnter(false);
		SelectSceneFunc();
	}


	

}

void mainmenu::render()
{
	_bg->render(getMemDC(), 0, 0);

	_menuUI->render();

	if (_isOptionMode)
	{
		_optionBG.img->render(getMemDC(), _optionBG.rc.left, _optionBG.rc.top);
		_soundTxt.img->render(getMemDC(), _soundTxt.rc.left, _soundTxt.rc.top);
		for (int i = 0; i < 10; i++)
		{
			if (_isSoundBarOn[i])
			{
				//_soundBar[0][i].img->render(getMemDC(), _soundBar[0][i].rc.left, _soundBar[0][i].rc.top, 0, 0, 40, 20 * (i + 1));
				_soundBar[0][i].img->render(getMemDC(), _soundBar[0][i].rc.left, _soundBar[0][i].rc.bottom - 20 * (i + 1), 0, 0, 40, 20 * (i + 1));
			}
			else
			{
				_soundBar[1][i].img->render(getMemDC(), _soundBar[1][i].rc.left, _soundBar[0][i].rc.bottom - 20 * (i + 1), 0, 0, 40, 20 * (i + 1));
			}
		}


		char str[128];
		sprintf_s(str, "_curVol : %d", _curVol);
		TextOut(getMemDC(), 300, 300, str, strlen(str));
		
	}


}

void mainmenu::SelectSceneFunc()
{
	switch (_menuUI->getCursorIdx())
	{
	case 0:
		_isSceneEnd = true;
		break;
		// 다른케이스에선, 옵션이나 뭐 이런 씬으로 넘기겠져?
	case 1:
		_isOptionMode = true;
		break;
	case 2:
		PostQuitMessage(0);
		break;
	}
}

tagImgCombo mainmenu::ImgComboinit(string keyName, int x, int y)
{
	tagImgCombo tmpImg;
	tmpImg.img = IMAGEMANAGER->findImage(keyName);

	tmpImg.pos = { x, y };
	tmpImg.rc = RectMakeCenter(x, y, tmpImg.img->getFrameWidth(), tmpImg.img->getFrameHeight());

	return tmpImg;
}

void mainmenu::OptionUIUpdate()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_curVol++;
		_isSoundBarOn[_curVol - 1] = true;
		RefreshVol();
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_curVol == 0)	_curVol = 1;
		_isSoundBarOn[_curVol - 1] = false;
		_curVol--;
		RefreshVol();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isOptionMode = false;
	}
}

void mainmenu::RefreshVol()
{
	if (_curVol < 0)		_curVol = 0;
	if (_curVol > 10)		_curVol = 10;
}
