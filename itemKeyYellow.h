#pragma once
#include "item.h"
class itemKeyYellow : public item
{
public:
	itemKeyYellow();
	~itemKeyYellow();

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void UsingFunc() override;
};

