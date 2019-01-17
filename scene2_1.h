#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "player2.h"

class scene2_1 : public gameNode
{
private:
	camera* _camera;
	
	player* _player;
	player2* _player2;

	int playerSelect;
	image* _mapImg;
public:
	scene2_1();
	~scene2_1();

	HRESULT init();
	void release();
	void update();
	void render();

	image* GetImage(){return _mapImg;}
	
	//5. 상위클래스만들어진 카메라 정보를 받음
	void SetLinkToCamera(camera* v){ _camera = v;}
};

