//	sceneVer. 19.01.21.01

#pragma once
#include "gameNode.h"
#include "camera.h"
#include "playerMgr.h"
#include "invenUI.h"
#include "itemMgr.h"

//20190122형우추가
#include "objectMgr.h"

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
	
	itemMgr* _itemMgr;

	//20190122형우추가
	objectMgr* _objectMgr;

	//RECT _ladderRc;

	//엔딩관련 - 유형우
	RECT _endrc;
	RECT _endPlayer;
	image* _endImg;

	//사운드관련 - 김도형
	char _soundName[128];

	float _volume;

	//용암폭포 관련 - 유형우
	RECT _lavaRc;
	image* _lavaimg;
	int _lavaIndex;


public:
	scene2_1();
	~scene2_1();

	HRESULT init();
	void release();
	void update();
	void render();

	//20190122형우추가
	void WorkObject1();
	void WorkObject2();
	void WorkObject3();
	void WorkObject4();

	//엔딩관련 - 유형우
	void ending();

	//용암폭포 관련 - 유형우
	void lavafall();

	image* GetImage() { return _mapImg; }

	//5. 상위클래스만들어진 카메라 정보를 받음
	void SetLinkToCamera(camera* v) { _camera = v; }

	void RefreshPlayerIdx();

	void setVolume(float volume) { _volume = volume; }

	bool getIsInvenMode() { return _isInvenMode; }

};

