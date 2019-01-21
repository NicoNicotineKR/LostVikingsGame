#pragma once
#include "gameNode.h"
#include "object1.h"
#include "object2.h"
#include "object3.h"
#include "object4.h"
#include "object5.h"
#include "object6.h"


class objectMgr : public gameNode
{
private:
	//엄마기때문에 담을수있음?
	vector<objects*>				_vObjects;
	vector<objects*>::iterator		_viObjects;

	//아래 6개를 담아보자

	//9개박살나는거
	object1* _object1;
	//자물쇠로 문여는거
	object2* _object2;
	//화살쏘고? 사다리 네려오는거
	object3* _object3;
	//사다리(별기능없음)
	object4* _object4;
	//오브젝트2랑 상호작용할 열쇠구멍?
	object5* _object5;
	//오브젝트3랑 상호작용할 버튼
	object6* _object6;

	char str[128];


public:
	objectMgr();
	~objectMgr();

	HRESULT init();
	void update();
	void release();
	void render();

	//이 자료형 objects에 담은 백터 컨테이너를 씬에서 복사할수잇게 만들어둠.
	vector<objects*>				getVObjects() {return _vObjects;}
	vector<objects*>::iterator		getVIObjects() {return _viObjects;}

	//백터 범위값 가져올려면 , 직접해줘야되나?
	//위의 벡터범위에서 가져올수있진않을까?
	object1* getObject1() { return _object1; }
	object2* getObject2() { return _object2; }
	object3* getObject3() { return _object3; }
	object4* getObject4() { return _object4; }
	object5* getObject5() { return _object5; }
	object6* getObject6() { return _object6; }
};

