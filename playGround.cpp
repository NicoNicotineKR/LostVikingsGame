#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//���Ŵ���
HRESULT playGround::init()
{
	gameNode::init(true);

	//1. ��𼭵羲������ ī�޶� ����������������
	//new���� �����Ҵ����� ���޸𸮿����� ī�޶�Ŭ������ ����ŭ�� �޸𸮰����� ���,���ּҸ� _camera�� �����Ϳ��־��ش�.
	_camera = new camera;


	//	Ÿ��Ʋ �߰��� (���� ���̶� ���⼭ new,�̴�����, ������ ������ SceneSelectFunc() ���� new, init, release ������ )
	_title = new title;
	SCENEMANAGER->addScene("title", _title);
	SCENEMANAGER->changeScene("title");			//Ÿ��Ʋ ������ �ּ� ����


	//_scene2_1 = new scene2_1;					//���� ���� �ñ��� SceneSelectFunc() ���� new, init, release ������ - �縸 (���� �Ƿ����)

	//2. ��2Ŭ�������� ���� camera������ ������
	//_scene2_1->SetLinkToCamera(_camera);		//���� ���� �ñ��� SceneSelectFunc() ���� new, init, release ������ - �縸 (���� �Ƿ����)
	//_scene2_1->init();						//���� ���� �ñ��� SceneSelectFunc() ���� new, init, release ������ - �縸 (���� �Ƿ����)

	//SCENEMANAGER->addScene("scene2_1", _scene2_1);	//���� ���� �ñ��� SceneSelectFunc() ���� new, init, release ������ - �縸 (���� �Ƿ����)
	//SCENEMANAGER->firstScene("scene2_1");				//���� ���� �ñ��� SceneSelectFunc() ���� new, init, release ������ - �縸 (���� �Ƿ����)


	//========== �ñ� ���� ������ ���� ���� ===============
	_curSceneIdx = E_TITLE;
	_isInvenMode = false;




	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
	//_scene2_1->update();				// �̰� ���ִ°ž�...???????���Ŵ����� ������Ʈ ���ְ��̽� - �縸

	

	if (!_isInvenMode)
	{
		KEYANIMANAGER->update();
	}

	if (_curSceneIdx == E_SCENE2_1)
	{
		_isInvenMode = _scene2_1->getIsInvenMode();
	}
	
	

	SelectSceneFunc();

}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//===========================================================


	SCENEMANAGER->render();
	//	_camera->render();

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void playGround::SelectSceneFunc()
{
	//	���ε�����
	//enum E_SCENE_INDEX {
	//	E_TITLE = 0,
	//	E_MAINMENU,
	//	E_SCENE2_1,
	//	E_SCENE_IDX_END,
	//};

	switch (_curSceneIdx)
	{
	case E_TITLE:
		if (_title->getIsSceneEnd())
		{
			_curSceneIdx = E_MAINMENU;
			_mainmenu = new mainmenu;
			SCENEMANAGER->addScene("mainmenu", _mainmenu);
			SCENEMANAGER->changeScene("mainmenu");
			// Ÿ��Ʋ �� ������ �ؾ��� -----

		}
		break;

	case E_MAINMENU:
		if (_mainmenu->getIsSceneEnd())
		{
			_curSceneIdx = E_SCENE2_1;
			_scene2_1 = new scene2_1;
			SCENEMANAGER->addScene("scene2_1", _scene2_1);
			_scene2_1->SetLinkToCamera(_camera);
			SCENEMANAGER->changeScene("scene2_1");
			_scene2_1->setVolume((float)_mainmenu->getCurVol() / 50);
			//	���θ޴� ������ �ؾ���

		}
		break;




	}

}

