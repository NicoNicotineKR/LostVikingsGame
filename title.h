#pragma once
#include "gameNode.h"
#include <vector>
class title : public gameNode
{
	

	image* _titleImg;		//	≈∏¿Ã∆≤
	image* _mainmenuImg;

	int _titleAlphaValue;
	int _mainmenuAlphaValue;

	bool _isFadeStart;
	bool _isSceneEnd;

	int _showFrameCount;
	
	const int ALPHA_VALUE_SPD = 100;
	const int TITLE_SHOW_FRAME = 10;



public:
	title();
	~title();

	HRESULT init();
	void release();
	void update();
	void render();

	void FadeFunc();



	bool getIsSceneEnd() { return _isSceneEnd; }


};

