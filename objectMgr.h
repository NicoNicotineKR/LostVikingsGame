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
	//�����⶧���� ����������?
	vector<objects*>				_vObjects;
	vector<objects*>::iterator		_viObjects;

	//�Ʒ� 6���� ��ƺ���

	//9���ڻ쳪�°�
	object1* _object1;
	//�ڹ���� �����°�
	object2* _object2;
	//ȭ����? ��ٸ� �׷����°�
	object3* _object3;
	//��ٸ�(����ɾ���)
	object4* _object4;
	//������Ʈ2�� ��ȣ�ۿ��� ���豸��?
	object5* _object5;
	//������Ʈ3�� ��ȣ�ۿ��� ��ư
	object6* _object6;

	char str[128];


public:
	objectMgr();
	~objectMgr();

	HRESULT init();
	void update();
	void release();
	void render();

	//�� �ڷ��� objects�� ���� ���� �����̳ʸ� ������ �����Ҽ��հ� ������.
	vector<objects*>				getVObjects() {return _vObjects;}
	vector<objects*>::iterator		getVIObjects() {return _viObjects;}

	//���� ������ �����÷��� , ��������ߵǳ�?
	//���� ���͹������� �����ü�����������?
	object1* getObject1() { return _object1; }
	object2* getObject2() { return _object2; }
	object3* getObject3() { return _object3; }
	object4* getObject4() { return _object4; }
	object5* getObject5() { return _object5; }
	object6* getObject6() { return _object6; }
};

