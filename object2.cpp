#include "stdafx.h"
#include "object2.h"


object2::object2()
{
}


object2::~object2()
{
}

HRESULT object2::init()
{
	objects::init();

	IMAGEMANAGER->addImage("오브젝트2", "images/object/object22.bmp", 390, 195, false, RGB(255, 0, 255));

	//첫번째문
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 260;
	object1._sizeY = 195;
	object1._x = 2945;
	object1._y = 884-128;
	object1._imageIndex = 260;
	object1._property = 1;
	object1._image = IMAGEMANAGER->findImage("오브젝트2");

	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);

	//두번째문
	object1._x = 1342;
	object1._y = 1010-144;
	object1._property = 2;
	
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	_vObjects.push_back(object1);
	

	return S_OK;
}

void object2::update()
{
	objects::update();

	//if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))
	//{
	//	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	//	{
	//		if (_viObjects->_start == false)
	//		{
	//			_viObjects->_start = true;
	//			break;
	//		}
	//	}
	//}
	
	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		if (_viObjects->_start == true)
		{
			if (_viObjects->_imageIndex > 0)
			{
				_viObjects->_startCount++;
				if (_viObjects->_startCount % 30 == 0)
				{
					_viObjects->_imageIndex -= 130;
				}
			}
		}
	}


}

void object2::release()
{
}

void object2::render()
{
	objects::render();

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
				, _viObjects->_rc.top - _cameraY + WINSIZEY / 2, _viObjects->_imageIndex,0,130,195);

	}
}

void object2::setStart(bool startValue, int index)
{
	_vObjects[index]._start = startValue;
}
