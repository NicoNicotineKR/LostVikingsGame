#pragma once
#include "characterInfo.h"
class olaf :
	public characterInfo
{
public:
	olaf();
	~olaf();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
};

