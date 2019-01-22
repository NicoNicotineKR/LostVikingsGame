#pragma once
#include "gameNode.h"
#include "itemBomb.h"
#include "itemKeyRed.h"
#include "itemKeyYellow.h"
#include "itemMeat.h"
#include "camera.h"
#include "invenUI.h"
#include "playerMgr.h"

class itemMgr : public gameNode
{
private:

	vector<item*> _vItemMgr;
	camera* _camera;
	invenUI* _inven;
	playerMgr* _pm;

	RECT _playerRc;
	int _playerIdx;


public:
	itemMgr();
	~itemMgr();

	HRESULT init();
	void release();
	void update();
	void render();

	void GetItemFunc();
	void GetPlayerInfo();






	void EraseVecIdx(int idx);
	void getAddressLinkToCamera(camera* camera) { _camera = camera; }
	void getAddressLinkToInvenUI(invenUI* inven) { _inven = inven; }
	void getAddressLinkToPlayerMgr(playerMgr* pm) { _pm = pm; }
	void setPlayerRc(RECT rc) { _playerRc = rc; }


};

