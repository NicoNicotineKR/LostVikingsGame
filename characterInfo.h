#pragma once
#include "gameNode.h"

class characterInfo : public gameNode
{
protected:
	image* _img;				// ĳ���� �̹���
	RECT _rc;					// ĳ���� ��Ʈ
	POINTFLOAT _pos;			// ĳ���� ��ǥ
	tagVector2D _vec;			// ĳ���� �̵��Ұ�
	float _gravity;				// ĳ���� �߷�
	float _speed;				// ĳ���� �ӵ�
	int _hp;					// ĳ���� ü��
	string _itemSlot[4];		// ĳ���� ������ĭ
	bool _isPlaying;			// ĳ���� �÷��������� ����
	bool _isAlive;				// ĳ���� ����ִ��� ����
	E_PLAYER_STATUS _status;	// ĳ���� ����
	int _motion_Count;			// ĳ���� ���������� ��Ƕ��°�
	bool _isFlying;				// ĳ���� ���߿� ���ִ���
	animation* _motion;			// ĳ���� ���
	bool _isMotionPlay;				// ĳ���� ����� �ѹ��� �����ض�

	float _cameraX;				// �� ī�޶� ���� ���� x
	float _cameraY;				// �� ī�޶� ���� ���� y

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update(int characterSelect, float cameraX, float cameraY);
	virtual void render();

	virtual void move();


	POINTFLOAT getPos() { return _pos; }

	//�÷��̾� ���� ������, ������
	E_PLAYER_STATUS getCharacterStatus() { return _status; }
	void setCharacterStatus(E_PLAYER_STATUS status) { _status = status; }
	//�÷��̾� �ִϸ��̼� ������, ������
	animation* getCharacterMotion() { return _motion; }
	void setCharacterMotion(animation* motion) { _motion = motion; }
};

