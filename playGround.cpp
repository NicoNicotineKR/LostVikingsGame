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

	

	_scene2_1 = new scene2_1;

	//2. 씬2클래스에서 에서 camera정보를 세팅함
	_scene2_1->SetLinkToCamera(_camera);
	_scene2_1->init();

	


	return S_OK;
}


void playGround::release()	
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	
	_scene2_1->update();

}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//===========================================================

	_scene2_1->render();
	_camera->render();

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

