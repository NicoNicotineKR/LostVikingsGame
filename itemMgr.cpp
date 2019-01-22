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
	GetPlayerInfo();
	GetItemFunc();
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

void itemMgr::GetItemFunc()
{
	for (int i = 0; i < _vItemMgr.size();)
	{
		RECT tmpRc;
		if (IntersectRect(&tmpRc, &_playerRc, &_vItemMgr[i]->getRc()))
		{
			//	인벤UI에 넣어주고,
			_inven->AddItem(_playerIdx, _vItemMgr[i]->getKindof());
			//	지운다.
			_vItemMgr.erase(_vItemMgr.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

void itemMgr::GetPlayerInfo()
{
	for (int i = 0; i < _pm->getVCharInfo().size(); i++)
	{
		if (_pm->getVCharInfo()[i]->getIsPlaying())
		{
			_playerIdx = i;
			_playerRc = _pm->getVCharInfo()[i]->getPlayerRc();
		}
			
	}
}

void itemMgr::EraseVecIdx(int idx)
{
	_vItemMgr.erase(_vItemMgr.begin() + idx);
}
