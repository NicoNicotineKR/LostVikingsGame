#include "stdafx.h"
#include "playerMgr.h"
#include "scene2_1.h"

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
	num = 0;
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
	ladderFunc();
}

void playerMgr::render()
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]->render();
	}
	
	char str[128];
	sprintf_s(str, "%d", num, strlen(str));
	TextOut(getMemDC(), 50, 50, str, strlen(str));
}

void playerMgr::ladderFunc()
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		if (!_vChar[i]->getIsPlaying()) continue;
		RECT temp;
		if (IntersectRect(&temp, &_vChar[i]->getPlayerRc(), &_ladderRc))
		{
			if (_vChar[i]->getPlayerRc().top <= _ladderRc.bottom - 5)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{
					if (_vChar[i]->getStatus() == P_R_MOVE ||
						_vChar[i]->getStatus() == P_R_IDLE ||
						_vChar[i]->getStatus() == P_R_FLYING ||
						_vChar[i]->getStatus() == P_R_FALLING) _vChar[i]->setStatus(P_R_ON_LADDER);
					else if (_vChar[i]->getStatus() == P_L_MOVE ||
						_vChar[i]->getStatus() == P_L_IDLE ||
						_vChar[i]->getStatus() == P_L_FLYING ||
						_vChar[i]->getStatus() == P_L_FALLING) _vChar[i]->setStatus(P_L_ON_LADDER);

					_vChar[i]->setLadderStatus(P_LADDER_UP);
					_vChar[i]->setPostionX(_ladderRc.left - ((_ladderRc.left - _ladderRc.right) / 2));
					_vChar[i]->setIsLadderMotion(true);

				}
				else if (KEYMANAGER->isOnceKeyUp(VK_UP))
				{
					_vChar[i]->setLadderStatus(P_LADDER_PAUSE);
				}

				if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
				{

					if (_vChar[i]->getStatus() == P_R_MOVE ||
						_vChar[i]->getStatus() == P_R_IDLE ||
						_vChar[i]->getStatus() == P_R_FLYING ||
						_vChar[i]->getStatus() == P_R_FALLING) _vChar[i]->setStatus(P_R_ON_LADDER);
					else if (_vChar[i]->getStatus() == P_L_MOVE ||
						_vChar[i]->getStatus() == P_L_IDLE ||
						_vChar[i]->getStatus() == P_L_FLYING ||
						_vChar[i]->getStatus() == P_L_FALLING) _vChar[i]->setStatus(P_L_ON_LADDER);

					_vChar[i]->setLadderStatus(P_LADDER_UP);
					_vChar[i]->setPostionX(_ladderRc.left - ((_ladderRc.left - _ladderRc.right) / 2));
					_vChar[i]->setIsLadderMotion(true);
					_vChar[i]->setLadderStatus(P_LADDER_DOWN);
				}
				else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
				{
					_vChar[i]->setLadderStatus(P_LADDER_PAUSE);
				}
			}
		}
	}

}
