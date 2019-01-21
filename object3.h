#pragma once
#include "objects.h"
class object3 : public objects
{
private:


public:
	object3();
	~object3();

	HRESULT init();
	void update();
	void release();
	void render();
};

