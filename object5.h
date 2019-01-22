#pragma once
#include "objects.h"
class object5 : public objects
{
private:

public:
	object5();
	~object5();

	HRESULT init();
	void release();
	void update();
	void render();

	virtual void setStart(bool startValue, int index) override;
};

