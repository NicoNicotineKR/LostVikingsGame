#pragma once
#include "gameNode.h"
#include "mainmenuUI.h"
class mainmenu : public gameNode
{
private:

	//메인메뉴 변수 시이작
	image* _bg;
	bool _isSceneEnd;


	mainmenuUI* _menuUI;

public:
	mainmenu();
	~mainmenu();

	HRESULT init();
	void release();
	void update();
	void render();


	void SelectSceneFunc();


	bool getIsSceneEnd() { return _isSceneEnd; }
	bool setIsSceneEnd(bool value) { _isSceneEnd = value; }


};

