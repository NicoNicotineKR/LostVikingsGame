#include "stdafx.h"
#include "itemMgr.h"


itemMgr::itemMgr()
{

}


itemMgr::~itemMgr()
{
}

HRESULT itemMgr::init()
{
	_vItemMgr.clear();

	_vItemMgr.push_back(new itemBomb);
	_vItemMgr.push_back(new itemKeyRed);
	_vItemMgr.push_back(new itemKeyYellow);
	_vItemMgr.push_back(new itemMeat);

	for (int i = 0; i < _vItemMgr.size(); i++)
		_vItemMgr[i]->init();




	return S_OK;
}

void itemMgr::release()
{
}

void itemMgr::update()
{

}

void itemMgr::render()
{
	for (int i = 0; i < _vItemMgr.size(); i++)
	{
		_vItemMgr[i]->getImg()->frameRender(getMemDC(),
			_vItemMgr[i]->getRc().left - _camera->Getmapx() + WINSIZEX / 2,
			_vItemMgr[i]->getRc().top - _camera->Getmapy() + WINSIZEY / 2,
			0, 0);
	}


}

void itemMgr::EraseVecIdx(int idx)
{
	_vItemMgr.erase(_vItemMgr.begin() + idx);
}
