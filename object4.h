#pragma once
#include "objects.h"
class object4 : public objects
{
private:


public:
	object4();
	~object4();

	HRESULT init();
	void update();
	void release();
	void render();
};

