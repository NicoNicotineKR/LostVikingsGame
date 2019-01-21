#pragma once
#include "gameNode.h"
#include "eric.h"
#include "olaf.h"
#include "baleog.h"

//class scene2_1;

class playerMgr : public gameNode
{
private:
	typedef vector<characterInfo*> vCharInfo;
	typedef vector<characterInfo*> vICharInfo;

private:
	vCharInfo _vChar;
	vICharInfo _vIChar;

	//scene2_1* _scene2_1;
	RECT _ladderRc;
	int num;

public:
	playerMgr();
	~playerMgr();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void ladderFunc();
	//����,�����ڵ�~~~~
	
	//���ͷ� ���� �÷��̾���� ������
	vCharInfo getVCharInfo() { return _vChar; }

	//��ٸ� ����
	void setLadderRc(RECT rc) { _ladderRc = rc; }
};

