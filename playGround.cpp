#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//씬매니저
HRESULT playGround::init()
{
	gameNode::init(true);

	//1. 어디서든쓰기위해 카메라를 상위구조에서만듬
	//new뜻은 동적할당으로 힙메모리영역에 카메라클래스가 쓸만큼의 메모리공간을 잡고,그주소를 _camera에 포인터에넣어준다.
	_camera = new camera;


	//	타이틀 추가함 (시작 씬이라 여기서 new,이닛해줌, 나머지 씬들은 SceneSelectFunc() 에서 new, init, release 진행함 )
	_title = new title;
	SCENEMANAGER->addScene("title", _title);
	SCENEMANAGER->changeScene("title");			//타이틀 보려면 주석 해제


	//_scene2_1 = new scene2_1;					//씬들 이제 플그의 SceneSelectFunc() 에서 new, init, release 진행함 - 재만 (이제 피료업씀)

	//2. 씬2클래스에서 에서 camera정보를 세팅함
	//_scene2_1->SetLinkToCamera(_camera);		//씬들 이제 플그의 SceneSelectFunc() 에서 new, init, release 진행함 - 재만 (이제 피료업씀)
	//_scene2_1->init();						//씬들 이제 플그의 SceneSelectFunc() 에서 new, init, release 진행함 - 재만 (이제 피료업씀)

	//SCENEMANAGER->addScene("scene2_1", _scene2_1);	//씬들 이제 플그의 SceneSelectFunc() 에서 new, init, release 진행함 - 재만 (이제 피료업씀)
	//SCENEMANAGER->firstScene("scene2_1");				//씬들 이제 플그의 SceneSelectFunc() 에서 new, init, release 진행함 - 재만 (이제 피료업씀)


	//========== 플그 고유 변수들 설정 시작 ===============
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
	//_scene2_1->update();				// 이거 왜있는거야...???????씬매니저가 업데이트 해주고이써 - 재만

	

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
	//	씬인덱스들
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
			// 타이틀 씬 릴리즈 해야함 -----

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
			//	메인메뉴 릴리즈 해야함

		}
		break;




	}

}

