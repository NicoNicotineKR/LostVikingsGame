#include "stdafx.h"
#include "object6.h"


object6::object6()
{
}


object6::~object6()
{
}

HRESULT object6::init()
{
	IMAGEMANAGER->addImage("오브젝트6", "images/object/object6.bmp", 50, 50, true, RGB(255, 0, 255));

	//첫번째열쇠구멍
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 50;
	object1._sizeY = 50;
	object1._x = 900;
	object1._y = 980 - 124;
	object1._property = 1;
	object1._image = IMAGEMANAGER->findImage("오브젝트6");
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);


	object1._x = 500;
	object1._y = 980 - 124;
	object1._property = 2;
	object1._image = IMAGEMANAGER->findImage("오브젝트6");
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);
	return S_OK;
}

void object6::release()
{
}

void object6::update()
{
}

void object6::render()
{
	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		if (KEYMANAGER->isToggleKey(VK_F12))
		{
			Rectangle(getMemDC(),
				_viObjects->_rc.left - _cameraX + WINSIZEX / 2,
				_viObjects->_rc.top - _cameraY + WINSIZEY / 2,
				_viObjects->_rc.right - _cameraX + WINSIZEX / 2,
				_viObjects->_rc.bottom - _cameraY + WINSIZEY / 2);
		}

		_viObjects->_image->render(getMemDC()
			, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
			, _viObjects->_rc.top - _cameraY + WINSIZEY / 2);
	}
}
