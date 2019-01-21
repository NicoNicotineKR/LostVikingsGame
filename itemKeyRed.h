#pragma once
#include "item.h"
class itemKeyRed : public item
{
public:
	itemKeyRed();
	~itemKeyRed();

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void UsingFunc() override;

};

