#pragma once
#include "objects.h"

enum stateObject
{
	LOCATION_X = 3392,
	LOCATION_Y = 444,
};

class object1 : public objects // 엄마정보가져옴
{
private:
	//그림변환용
	int Num;
	
	//메인실행
	bool mainActivate;

	//연쇄용
	bool activate;
	int activateCount;

public:
	object1();
	~object1();

	HRESULT init();
	void update();
	void release();
	void render();

	//실행용
	void setMainActivate(bool v){ mainActivate = v ;}
	//이건엄마꺼가아닌데?
};

