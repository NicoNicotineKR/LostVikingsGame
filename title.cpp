#include "stdafx.h"
#include "title.h"


title::title()
{
}


title::~title()
{
}

HRESULT title::init()
{
	IMAGEMANAGER->addImage("mainTitle", "images/UI/mainmenuUI/mainTitle.bmp", 1024, 768, false, 0x000000);
	IMAGEMANAGER->addImage("mainmenu", "images/UI/mainmenuUI/Menu.bmp", 1024, 768, false, 0x000000);
	

	_titleImg = IMAGEMANAGER->findImage("mainTitle");
	_mainmenuImg = IMAGEMANAGER->findImage("mainmenu");
	

	_titleAlphaValue = 255;
	_mainmenuAlphaValue = 0;

	_isFadeStart = false;
	_isSceneEnd = false;

	_showFrameCount = 0;


	return S_OK;
}

void title::release()
{
}

void title::update()
{
	if (!_isSceneEnd)
	{
		_showFrameCount++;

		if (TITLE_SHOW_FRAME < _showFrameCount)	_isFadeStart = true;


		if (_isFadeStart)
		{
			FadeFunc();

			if (_titleAlphaValue <= 0 && _mainmenuAlphaValue >= 255)
			{
				_isSceneEnd = true;
			}
		}
	}
	
}

void title::render()
{
	
	_titleImg->alphaRender(getMemDC(), 0, 0, _titleAlphaValue);
	_mainmenuImg->alphaRender(getMemDC(), 0, 0, _mainmenuAlphaValue);
}

void title::FadeFunc()
{
	_titleAlphaValue -= ALPHA_VALUE_SPD;
	_mainmenuAlphaValue += ALPHA_VALUE_SPD;

	if (_titleAlphaValue < 0)		_titleAlphaValue = 0;
	if (_mainmenuAlphaValue > 255)	_mainmenuAlphaValue = 255;

}
