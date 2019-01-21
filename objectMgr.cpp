#include "stdafx.h"
#include "objectMgr.h"


objectMgr::objectMgr()
{
}


objectMgr::~objectMgr()
{
}

HRESULT objectMgr::init()
{
	_object1 = new object1;
	_object1->init();
	_vObjects.push_back(_object1);

	_object2 = new object2;
	_object2->init();
	_vObjects.push_back(_object2);

	_object3 = new object3;
	_object3->init();
	_vObjects.push_back(_object3);

	_object4 = new object4;
	_object4->init();
	_vObjects.push_back(_object4);

	_object5 = new object5;
	_object5->init();
	_vObjects.push_back(_object5);

	_object6 = new object6;
	_object6->init();
	_vObjects.push_back(_object6);

	//´Ù´ã¾Æ~!

	return S_OK;
}

void objectMgr::update()
{
	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		(*_viObjects)->update();
	}

}

void objectMgr::release()
{
	
}

void objectMgr::render()
{
	for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
	{
		(*_viObjects)->render();
	}

	sprintf_s(str,"%d",_vObjects.size());
	TextOut(getMemDC(),150,150,str,strlen(str));
}
