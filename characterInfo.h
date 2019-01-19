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

	float _cameraX;				// �� ī�޶� ���� ���� x
	float _cameraY;				// �� ī�޶� ���� ���� y


	//�ȼ��浹
	//===========�������߰�============
	int _r, _g, _b;
	int _probeY;
	//===========�������߰�============

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();

	//�ȼ��浹
	//===========�������߰�============
	virtual void PixelCrash();
	//===========�������߰�============



	//�����ڵ�(get,set)

	POINTFLOAT getPos() { return _pos; }

	//�÷��̾� ���� ������, ������
	E_PLAYER_STATUS getCharacterStatus() { return _status; }
	void setCharacterStatus(E_PLAYER_STATUS status) { _status = status; }

	//�÷��̾� �ִϸ��̼� ������, ������
	animation* getCharacterMotion() { return _motion; }
	void setCharacterMotion(animation* motion) { _motion = motion; }


	//2019.01.17 ������ ����11���߰� ===================
	//ī�޶� ����������
	void setCameraX(float v) { _cameraX = v; }
	void setCameraY(float v) { _cameraY = v; }

	//ī�޶� �����������°� ����
	void UpdateCameraPos(float _cameraX, float _cameraY);
	//2019.01.17 ������ ����11���߰� ===================
};

