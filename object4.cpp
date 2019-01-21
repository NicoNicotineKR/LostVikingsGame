#include "stdafx.h"
#include "object4.h"


object4::object4()
{
}


object4::~object4()
{
}

HRESULT object4::init()
{
	return E_NOTIMPL;
}

void object4::update()
{
	//첫번째사다리
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 140;
	object1._sizeY = 490;
	object1._x = 890;
	object1._y = 125;

	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);

	//2번째사다리
	object1._sizeX = 140;
	object1._sizeY = 680;
	object1._x = 3710;
	object1._y = 440;
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);
}

void object4::release()
{
}

void object4::render()
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
	}
}
