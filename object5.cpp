#include "stdafx.h"
#include "object5.h"


object5::object5()
{
}


object5::~object5()
{
}

HRESULT object5::init()
{
	IMAGEMANAGER->addImage("오브젝트51", "images/object/object51.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("오브젝트52", "images/object/object52.bmp", 50, 50, true, RGB(255, 0, 255));

	//첫번째열쇠구멍
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 50;
	object1._sizeY = 50;
	object1._x = 3100;
	object1._y = 950 - 128;
	object1._property = 1;
	object1._image = IMAGEMANAGER->findImage("오브젝트51");
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);

	//두번째열쇠구멍
	object1._x = 1500;
	object1._y = 1080 - 144;
	object1._property = 2;
	object1._image = IMAGEMANAGER->findImage("오브젝트52");
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);

	return S_OK;
}

void object5::release()
{
}

void object5::update()
{
}

void object5::render()
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
