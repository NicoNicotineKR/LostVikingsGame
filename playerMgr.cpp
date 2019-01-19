#include "stdafx.h"
#include "playerMgr.h"


playerMgr::playerMgr()
{
}


playerMgr::~playerMgr()
{
}

HRESULT playerMgr::init()
{
	characterInfo* _eric = new eric;
	_vChar.push_back(_eric);

	characterInfo * _olaf = new olaf;
	_vChar.push_back(_olaf);


	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]->init();
	}

	//첫번째놈인 에릭한만 isPlaying 트루로만듬
	_vChar[P_ERIC]->setIsPlaying(true);
	return S_OK;
}

void playerMgr::release()
{
}

void playerMgr::update()
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]->update();
	}
}

void playerMgr::render()
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]->render();
	}
}
