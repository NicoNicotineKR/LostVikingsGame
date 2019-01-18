#pragma once
#include "gameNode.h"
#include "camera.h"
#include "eric.h"

class scene2_1 : public gameNode
{
private:
	camera* _camera;
	eric* _eric;

	int playerSelect;
	image* _mapImg;
	//===========�ȼ��浹�����============
	image* _mapImgPixel;
	//===========�ȼ��浹�����============
public:
	scene2_1();
	~scene2_1();

	HRESULT init();
	void release();
	void update();
	void render();

	image* GetImage() { return _mapImg; }

	//5. ����Ŭ����������� ī�޶� ������ ����
	void SetLinkToCamera(camera* v) { _camera = v; }
};

