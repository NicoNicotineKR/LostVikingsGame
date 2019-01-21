#pragma once
#include "objects.h"
class object6 : public objects
{
private:

public:
	object6();
	~object6();

	HRESULT init();
	void release();
	void update();
	void render();
};

