#pragma once
#include "item.h"

class itemMeat : public item
{
public:
	itemMeat();
	~itemMeat();

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void UsingFunc() override;
};

