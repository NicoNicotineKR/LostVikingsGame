//	sceneVer. 19.01.21.01

#pragma once
#include "gameNode.h"
#include "camera.h"
#include "playerMgr.h"
#include "invenUI.h"
#include "itemMgr.h"

//20190122�����߰�
#include "objectMgr.h"

class scene2_1 : public gameNode
{
private:
	camera* _camera;
	playerMgr* _pm;

	int playerSelect;
	image* _mapImg;
	//===========�ȼ��浹�����============
	image* _mapImgPixel;
	//===========�ȼ��浹�����============

	invenUI* _invenUI;		//	�縸�߰�
	bool _isInvenMode;
	
	itemMgr* _itemMgr;

	//20190122�����߰�
	objectMgr* _objectMgr;

	//RECT _ladderRc;

	//�������� - ������
	RECT _endrc;
	RECT _endPlayer;
	image* _endImg;

	//������� - �赵��
	char _soundName[128];

	float _volume;

	//������� ���� - ������
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

	//20190122�����߰�
	void WorkObject1();
	void WorkObject2();
	void WorkObject3();
	void WorkObject4();

	//�������� - ������
	void ending();

	//������� ���� - ������
	void lavafall();

	image* GetImage() { return _mapImg; }

	//5. ����Ŭ����������� ī�޶� ������ ����
	void SetLinkToCamera(camera* v) { _camera = v; }

	void RefreshPlayerIdx();

	void setVolume(float volume) { _volume = volume; }

	bool getIsInvenMode() { return _isInvenMode; }

};

