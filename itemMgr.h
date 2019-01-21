#pragma once
#include "gameNode.h"
#include "itemBomb.h"
#include "itemKeyRed.h"
#include "itemKeyYellow.h"
#include "itemMeat.h"
#include "camera.h"

class itemMgr : public gameNode
{
private:

	vector<item*> _vItemMgr;
	camera* _camera;


public:
	itemMgr();
	~itemMgr();

	HRESULT init();
	void release();
	void update();
	void render();


	void EraseVecIdx(int idx);
	void getAddressLinkToCamera(camera* camera) { _camera = camera; }



};

