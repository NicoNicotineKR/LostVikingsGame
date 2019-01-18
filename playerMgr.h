#pragma once
#include "gameNode.h"
#include "eric.h"
#include "olaf.h"


class playerMgr : public gameNode
{
private:
	typedef vector<characterInfo*> vCharInfo;
	typedef vector<characterInfo*> vICharInfo;

private:
	vCharInfo _vChar;
	vICharInfo _vIChar;




public:
	playerMgr();
	~playerMgr();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	//접근,설정자들~~~~
	
	//벡터로 만들 플레이어들의 접근자
	vCharInfo getVCharInfo() { return _vChar; }

};

