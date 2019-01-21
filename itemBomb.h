#pragma once
#include "item.h"

class itemBomb : public item
{
public:
	itemBomb();
	~itemBomb();


	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void UsingFunc() override;

};

