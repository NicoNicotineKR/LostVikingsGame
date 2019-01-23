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
	IMAGEMANAGER->addImage("redcross", "images/UI/mainmenuUI/redcross.bmp", 561, 261, true, 0xFF00FF);
	//IMAGEMANAGER->addImage("vug", "images/UI/mainmenuUI/Vug.bmp", 250, 162, true, 0xFF00FF);
	IMAGEMANAGER->addImage("vugKings", "images/UI/mainmenuUI/vugKings.bmp", 1024, 768, false, 0x000000);
	

	_titleImg = IMAGEMANAGER->findImage("mainTitle");
	_mainmenuImg = IMAGEMANAGER->findImage("mainmenu");
	_redcrossImg = IMAGEMANAGER->findImage("redcross");
	_vugKingImg = IMAGEMANAGER->findImage("vugKings");
	

	_titleAlphaValue = 255;
	_mainmenuAlphaValue = 0;

	_isFadeStart = false;
	_isTitleEnd = false;
	_isRedCrossStart = false;
	_isVugStart = false;
	_isSceneEnd = false;


	_showFrameCount = 0;
	_titleEndCount = 0;
	_redcrossCount = 0;
	


	return S_OK;
}

void title::release()
{
	IMAGEMANAGER->deleteImage("mainTitle");
	IMAGEMANAGER->deleteImage("mainmenu");
	IMAGEMANAGER->deleteImage("redcross");
	//IMAGEMANAGER->deleteImage("vugKings");
	//_titleImg = nullptr;
	//_mainmenuImg = nullptr;
	//_redcrossImg = nullptr;
	//_vugKingImg = nullptr;

}

void title::update()
{
	if (!_isSceneEnd)
	{
		if(_isFadeStart == false)				_showFrameCount++;
		if (TITLE_SHOW_FRAME < _showFrameCount)	_isFadeStart = true;

		if (_isFadeStart)
		{
			TitleFade();
		}
		if (_isTitleEnd)
		{
			if (!_isRedCrossStart)		_titleEndCount++;
			if (REDCROSS_START_FRAME < _titleEndCount)
			{
				_isRedCrossStart = true;
			}
			if (_isRedCrossStart)
			{
				if (!_isVugStart)						_redcrossCount++;
				if (VUG_START_FRAME < _redcrossCount)	_isVugStart = true;

			}
			if (_isVugStart)
			{
				if (!_isSceneEnd)	_waitingCount++;
				if (WAITING_FRAME < _waitingCount)
					_isSceneEnd = true;
			}

		}
	
	}
	
}

void title::render()
{
	int tmp;
	tmp = 0;
	_titleImg->alphaRender(getMemDC(), 0, 0, _titleAlphaValue);
	_mainmenuImg->alphaRender(getMemDC(), 0, 0, _mainmenuAlphaValue);

	if (_isVugStart)
	{
		_vugKingImg->render(getMemDC(), 0, 0);

		//if (_isVugTremble)
		//{
		//	_vugImg->render(getMemDC(), 63 + RND->getFromIntTo(-VUG_TREMBLE_VALUE, VUG_TREMBLE_VALUE), 118 + RND->getFromIntTo(-VUG_TREMBLE_VALUE, VUG_TREMBLE_VALUE));
		//}
		//else
		//{
		//	_vugImg->render(getMemDC(), 63, 118);
		//}
	}

	if (_isRedCrossStart && !_isVugStart)
	{
		_redcrossImg->render(getMemDC(), 59, 84);
	}
	


}

void title::TitleFade()
{
	if (_isFadeStart)
	{
		FadeFunc();

		if (_titleAlphaValue <= 0 && _mainmenuAlphaValue >= 255)
		{
			_isFadeStart = false;
			_isTitleEnd = true;
		}
	}
}

void title::FadeFunc()
{
	_titleAlphaValue -= ALPHA_VALUE_SPD;
	_mainmenuAlphaValue += ALPHA_VALUE_SPD;

	if (_titleAlphaValue < 0)		_titleAlphaValue = 0;
	if (_mainmenuAlphaValue > 255)	_mainmenuAlphaValue = 255;

}
