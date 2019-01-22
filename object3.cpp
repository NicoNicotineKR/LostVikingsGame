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
	IMAGEMANAGER->addImage("¿ÀºêÁ§Æ®3", "images/object/object3.bmp", 1408, 352, true, RGB(255, 0, 255));

	//µÎ¹øÂ°´Ù¸®
	tagObjects object1;
	ZeroMemory(&object1, sizeof(object1));
	object1._sizeX = 352;
	object1._sizeY = 352;
	object1._x = 160;
	object1._y = 790 - 124;
	object1._imageIndex = 0;
	object1._property = 2;
	object1._image = IMAGEMANAGER->findImage("¿ÀºêÁ§Æ®3");
	object1._start = false;
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	object1._rc2 = RectMake(250, 1010, 265, 60);
	_vObjects.push_back(object1);

	//Ã¹¹øÂ°´Ù¸®
	object1._x = 560;
	object1._property = 1;
	object1._start = false;
	object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);
	object1._rc2 = RectMake(640, 1010, 265, 60);
	_vObjects.push_back(object1);

	return S_OK;
}

void object3::update()
{

	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		if (!_viObjects->_start) continue;
	
		if (_viObjects->_start)
		{
			_viObjects->_rc2 = RectMake(_viObjects->_rc.left, _viObjects->_rc.bottom - 70, 352, 70);
		}
	}

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
	
	//ÆÇÁ¤¿ë·ºÆ®
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
			if (!_viObjects->_start)
			{
				Rectangle(getMemDC(),
					_viObjects->_rc2.left - _cameraX + WINSIZEX / 2,
					_viObjects->_rc2.top - _cameraY + WINSIZEY / 2,
					_viObjects->_rc2.right - _cameraX + WINSIZEX / 2,
					_viObjects->_rc2.bottom - _cameraY + WINSIZEY / 2);
			}
		
		}
		if (_viObjects->_start)
		{
			HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			HPEN oldPen = (HPEN)SelectObject(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(), pen);
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(), brush);
			Rectangle(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(),
				_viObjects->_rc2.left,
				_viObjects->_rc2.top,
				_viObjects->_rc2.right,
				_viObjects->_rc.bottom);
			SelectObject(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(), oldPen);
			SelectObject(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(), oldBrush);
			DeleteObject(pen);
			DeleteObject(oldPen);
			DeleteObject(brush);
			DeleteObject(oldBrush);
		}

		//Rectangle(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(),
		//	250,// -_cameraX + WINSIZEX / 2,
		//	1010,// -_cameraY + WINSIZEY / 2,
		//	(250 + 265),// -_cameraX + WINSIZEX / 2,
		//	950);// -_cameraY + WINSIZEY / 2);
		//Rectangle(IMAGEMANAGER->findImage("¾À2_1ÇÈ¼¿")->getMemDC(),
		//	640,// -_cameraX + WINSIZEX / 2,
		//	1010,// -_cameraY + WINSIZEY / 2,
		//	(640 + 260),// -_cameraX + WINSIZEX / 2,
		//	950);// -_cameraY + WINSIZEY / 2);


		_viObjects->_image->render(getMemDC()
			, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
			, _viObjects->_rc.top - _cameraY + WINSIZEY / 2, _viObjects->_imageIndex, 0, 352, 352);

	}
}
