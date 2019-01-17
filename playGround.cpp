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

	

	_scene2_1 = new scene2_1;

	//2. ��2Ŭ�������� ���� camera������ ������
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

