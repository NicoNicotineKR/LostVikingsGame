#include "stdafx.h"
#include "object1.h"

object1::object1()
{
}
object1::~object1()
{
}

HRESULT object1::init()
{
	objects::init();

	IMAGEMANAGER->addImage("오브젝트1", "images/object/object1.bmp", 252, 177, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("오브젝트1실행", "images/object/object1break.bmp", 189, 59, true, RGB(255, 0, 255));
	
	//1번째줄
	for (int j = 0; j < 3; j++)
	{
		tagObjects object1;
		ZeroMemory(&object1, sizeof(object1));
		object1._sizeX = 63;
		object1._sizeY = 59;
		object1._x = LOCATION_X;
		object1._y = LOCATION_Y - j * object1._sizeY;
		object1._image = IMAGEMANAGER->findImage("오브젝트1");
		object1._image2 = IMAGEMANAGER->findImage("오브젝트1실행");

		object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);

		_vObjects.push_back(object1);
	}
	//2번째줄
	for (int j = 0; j < 3; j++)
	{
		tagObjects object1;
		ZeroMemory(&object1, sizeof(object1));
		object1._sizeX = 63;
		object1._sizeY = 59;
		object1._x = LOCATION_X + object1._sizeX;
		object1._y = LOCATION_Y + j * object1._sizeY - object1._sizeY * 2;
		object1._image = IMAGEMANAGER->findImage("오브젝트1");
		object1._image2 = IMAGEMANAGER->findImage("오브젝트1실행");

		object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);

		_vObjects.push_back(object1);
	}
	//3번째줄
	for (int j = 0; j < 3; j++)
	{
		tagObjects object1;
		ZeroMemory(&object1, sizeof(object1));
		object1._sizeX = 63;
		object1._sizeY = 59;
		object1._x = LOCATION_X + object1._sizeX * 2;
		object1._y = LOCATION_Y - j * object1._sizeY;
		object1._image = IMAGEMANAGER->findImage("오브젝트1");
		object1._image2 = IMAGEMANAGER->findImage("오브젝트1실행");

		object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);

		_vObjects.push_back(object1);
	}
	//2번째줄
	for (int j = 0; j < 3; j++)
	{
		tagObjects object1;
		ZeroMemory(&object1, sizeof(object1));
		object1._sizeX = 63;
		object1._sizeY = 59;
		object1._x = LOCATION_X + object1._sizeX * 3;
		object1._y = LOCATION_Y + j * object1._sizeY - object1._sizeY * 2;
		object1._image = IMAGEMANAGER->findImage("오브젝트1");
		object1._image2 = IMAGEMANAGER->findImage("오브젝트1실행");

		object1._rc = RectMake(object1._x, object1._y, object1._sizeX, object1._sizeY);

		_vObjects.push_back(object1);
	}

	return S_OK;
}
void object1::update()
{
	objects::update();

	//백터에 들어간 순서대로 실행됨
	if (activate == true)
	{
		for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
		{
			if (_viObjects->_start == false)
			{
				_viObjects->_start = true;
				activate = false;
				break;
			}
		}
	}

	//다음거 파괴되는 속도
	if (mainActivate == true)
	{
		if (activate == false)
		{
			if (activateCount < 50)
			{
				activateCount++;
			}
			if (activateCount >= 50)
			{
				activate = true;
				activateCount = 0;
			}
		}
	}

	//실행된애가있으면 프레임을 늘림.
	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		if (_viObjects->_start == true)
		{
			if (_viObjects->_startCount < 200)
			{
				_viObjects->_startCount++;//메모리누수방지용?
			}

			if (_viObjects->_startCount % 20 == 0)
			{
				if (_viObjects->_imageIndex < 252)
				{
					_viObjects->_imageIndex += 63;

					if (_viObjects->_imageIndex == 252)
					{
						_viObjects->_x +=1000;
						_viObjects->_rc = RectMake(_viObjects->_x,_viObjects->_y,63,59);
					}
				}
			}
		}
	}
}

void object1::release()
{
}

void object1::render()
{
	objects::render();

	Num = 0;

	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		//오브젝트파괴되기전 랜더링 자르기위치
		if (_viObjects->_start == false)
		{
			if (Num < 3)
			{
				_viObjects->_image->render(getMemDC()
					, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
					, _viObjects->_rc.top - _cameraY + WINSIZEY / 2
					, 63 * 0, 0 + ((2 - Num) * 59), 63, 59);
			}
			if (Num >= 3 && Num < 6)
			{
				_viObjects->_image->render(getMemDC()
					, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
					, _viObjects->_rc.top - _cameraY + WINSIZEY / 2
					, 63 * 1, 0 + ((Num - 3) * 59), 63, 59);
			}
			if (Num >= 6 && Num < 9)
			{
				_viObjects->_image->render(getMemDC()
					, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
					, _viObjects->_rc.top - _cameraY + WINSIZEY / 2
					, 63 * 2, 0 + ((8 - Num) * 59), 63, 59);
			}
			if (Num >= 9 && Num < 12)
			{
				_viObjects->_image->render(getMemDC()
					, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
					, _viObjects->_rc.top - _cameraY + WINSIZEY / 2
					, 63 * 3, 0 + ((Num - 9) * 59), 63, 59);
			}
		}
		Num++;

		//오브젝트 파괴된 아이들 랜더링
		if (_viObjects->_start == true)
		{
			_viObjects->_image2->render(getMemDC()
				, _viObjects->_rc.left - _cameraX + WINSIZEX / 2
				, _viObjects->_rc.top - _cameraY + WINSIZEY / 2, _viObjects->_imageIndex,0,63,59);
		}

		//Rectangle(getMemDC(),
		//	_viObjects->_rc.left - _cameraX + WINSIZEX / 2,
		//	_viObjects->_rc.top - _cameraY + WINSIZEY / 2,
		//	_viObjects->_rc.right - _cameraX + WINSIZEX / 2,
		//	_viObjects->_rc.bottom - _cameraY + WINSIZEY / 2);

		//char str1[128];
		//sprintf_s(str1, "%d  %f", _viObjects->_imageIndex, _viObjects->_x);
		//TextOut(getMemDC(), 150, 100+Num*20, str1, strlen(str1));
	}

}
