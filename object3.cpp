#include "stdafx.h"
#include "object3.h"


object3::object3()
{
}


object3::~object3()
{
}

HRESULT object3::init()
{
	IMAGEMANAGER->addImage("오브젝트3", "images/object/object3.bmp", 1408, 352, true, RGB(255, 0, 255));

	//두번째다리
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 352;
	object1._sizeY = 352;
	object1._x = 160;
	object1._y = 790 - 124;
	object1._imageIndex = 0;
	object1._property = 2;
	object1._image = IMAGEMANAGER->findImage("오브젝트3");

	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	object1._rc2 = RectMake(object1._x, object1._y, 70, object1._sizeY);
	_vObjects.push_back(object1);

	//첫번째다리
	object1._x = 560;
	object1._property = 1;
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	object1._rc2 = RectMake(object1._x, object1._y, 70, object1._sizeY);
	_vObjects.push_back(object1);

	return S_OK;
}

void object3::update()
{
	//if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD3))
	//{
	//	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	//	{
	//		if (_viObjects->_start == false)
	//		{
	//			_viObjects->_start = true;
	//			_viObjects->_rc2 = RectMake(_viObjects->_rc.left, _viObjects->_rc.bottom-70, 352, 70);
	//			break;
	//		}
	//	}
	//}

	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		if (_viObjects->_start == true)
		{
			if (_viObjects->_imageIndex < 352*3)
			{
				_viObjects->_startCount++;
				if (_viObjects->_startCount % 30 == 0)
				{
					_viObjects->_imageIndex += 352;
				}
			}
		}
	}
	
	//판정용렉트
}

void object3::release()
{
}

void object3::render()
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

			Rectangle(getMemDC(),
				_viObjects->_rc2.left - _cameraX + WINSIZEX / 2,
				_viObjects->_rc2.top - _cameraY + WINSIZEY / 2,
				_viObjects->_rc2.right - _cameraX + WINSIZEX / 2,
				_viObjects->_rc2.bottom - _cameraY + WINSIZEY / 2);
		}

		_viObjects->_image->render(getMemDC()
			, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
			, _viObjects->_rc.top - _cameraY + WINSIZEY / 2, _viObjects->_imageIndex, 0, 352, 352);

	}
}
