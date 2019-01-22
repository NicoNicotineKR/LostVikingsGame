#pragma once
#include "gameNode.h"

struct tagObjects
{
	image* _image;	//기본이미지
	image* _image2;	//실행될이미지

	RECT _rc;
	RECT _rc2;//오브젝트3에서만 판정용렉트
	float _x, _y;
	float _sizeX;
	float _sizeY;

	bool _start;
	int _startCount;
	
	//성질 부여용
	int _property;

	//실험용
	int _imageIndex;
};

class objects : public gameNode
{
//자식들에게 줄거니 protected
protected:

	//오브젝트들이 가지고있는 기본속성

	//백터로 여러개찍어낼거임
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
	
	//접근자
	vector<tagObjects>				getvObjects(){return _vObjects;}
	vector<tagObjects>::iterator	getviObjects(){return _viObjects;}
	//설정자
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

