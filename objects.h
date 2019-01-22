#pragma once
#include "gameNode.h"

struct tagObjects
{
	image* _image;	//�⺻�̹���
	image* _image2;	//������̹���

	RECT _rc;
	RECT _rc2;//������Ʈ3������ �����뷺Ʈ
	float _x, _y;
	float _sizeX;
	float _sizeY;

	bool _start;
	int _startCount;
	
	//���� �ο���
	int _property;

	//�����
	int _imageIndex;
};

class objects : public gameNode
{
//�ڽĵ鿡�� �ٰŴ� protected
protected:

	//������Ʈ���� �������ִ� �⺻�Ӽ�

	//���ͷ� ������������
	vector<tagObjects>				_vObjects;
	vector<tagObjects>::iterator	_viObjects;

	float _cameraX;
	float _cameraY;
public:
	objects();
	~objects();
	
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
	
	//������
	vector<tagObjects>				getvObjects(){return _vObjects;}
	vector<tagObjects>::iterator	getviObjects(){return _viObjects;}
	//������
	void setvObject(vector<tagObjects> v){ _vObjects = v;}

	void setCameraX(float setCameraX) { _cameraX = setCameraX; }
	void setCameraY(float setCameraY) { _cameraY = setCameraY; }

	virtual void setStart(bool startValue, int index);
	//==================

	//vector<tagObjects>				getvObjects() { return _vObjects; }
	//vector<tagObjects>::iterator	getviObjects() { return _viObjects; }
	//
	

	//tagObjects		getObject(int idx)	{ return _vObjects[idx]; }
	



};

