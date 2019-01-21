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

