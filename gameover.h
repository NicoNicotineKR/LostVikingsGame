#pragma once
#include "gameNode.h"
class gameover : public gameNode
{
private:
	image* _bg;
	int _alphaValue;

	bool _isRestart;

	const int ALPHA_SPD = 5;

public:
	gameover();
	~gameover();

	HRESULT init();
	void release();
	void update();
	void render();

	bool getIsRestart() { return _isRestart; }

};

