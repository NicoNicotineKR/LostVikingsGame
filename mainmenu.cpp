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
	_bg = IMAGEMANAGER->findImage("mainmenu");
	_isSceneEnd = false;

	_menuUI = new mainmenuUI;
	_menuUI->init();


	return S_OK;
}

void mainmenu::release()
{
}

void mainmenu::update()
{
	_menuUI->update();

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

}

void mainmenu::SelectSceneFunc()
{
	switch (_menuUI->getCursorIdx())
	{
	case 0:
		_isSceneEnd = true;
		break;
		// 다른케이스에선, 옵션이나 뭐 이런 씬으로 넘기겠져?
	}
}
