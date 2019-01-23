#include "stdafx.h"
#include "gameover.h"


gameover::gameover()
{
}


gameover::~gameover()
{
}

HRESULT gameover::init()
{
	IMAGEMANAGER->addImage("gameover", "images/Scene/ending.bmp", 1024, 768, false, 0x000000);

	_bg = IMAGEMANAGER->findImage("gameover");
	_alphaValue = 0;

	_isRestart = false;


	return S_OK;
}

void gameover::release()
{
	IMAGEMANAGER->deleteImage("gameover");

}

void gameover::update()
{
	if (_alphaValue <= 254)
	{
		_alphaValue += ALPHA_SPD;
	}
		
	else if (_alphaValue >= 255)
	{
		_alphaValue = 255;
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_isRestart = true;
		}
	}


}

void gameover::render()
{
	_bg->alphaRender(getMemDC(), _alphaValue);
}
