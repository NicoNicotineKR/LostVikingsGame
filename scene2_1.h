//	sceneVer. 19.01.21.01

#pragma once
#include "gameNode.h"
#include "camera.h"
#include "playerMgr.h"
#include "invenUI.h"

class scene2_1 : public gameNode
{
private:
	camera* _camera;
	playerMgr* _pm;

	int playerSelect;
	image* _mapImg;
	//===========픽셀충돌실험용============
	image* _mapImgPixel;
	//===========픽셀충돌실험용============

	invenUI* _invenUI;		//	재만추가
	bool _isInvenMode;


public:
	scene2_1();
	~scene2_1();

	HRESULT init();
	void release();
	void update();
	void render();

	image* GetImage() { return _mapImg; }

	//5. 상위클래스만들어진 카메라 정보를 받음
	void SetLinkToCamera(camera* v) { _camera = v; }
};

