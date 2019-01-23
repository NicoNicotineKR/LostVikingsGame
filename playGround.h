#pragma once
#include "gameNode.h"
#include "scene2_1.h"
#include "title.h"
#include "mainmenu.h"
#include "gameover.h"


//�߰�
#include "camera.h"


class playGround : public gameNode
{
private:

	title* _title;
	mainmenu* _mainmenu;

	scene2_1* _scene2_1;
	//�߰�
	camera* _camera;
	gameover* _gameover;


	E_SCENE_INDEX _curSceneIdx;

	bool _isInvenMode;

	char str[128];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SelectSceneFunc();		// �� �����ٴ� ��ȣ �޾Ƽ�, ���������� �ѱ�



};

