#pragma once
#include "characterInfo.h"

class olaf : public characterInfo
{
private:

	bool _isShiledUp;
public:
	olaf();
	~olaf();

	HRESULT init();
	void release();
	void update(int characterSelect, float cameraX, float cameraY);
	void render();

	void move();
};

