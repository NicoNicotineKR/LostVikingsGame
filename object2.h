#pragma once
#include "objects.h"

class object2 : public objects
{
private:
	int Num;

public:
	object2();
	~object2();

	HRESULT init();
	void update();
	void release();
	void render();
};

