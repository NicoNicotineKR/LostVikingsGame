#pragma once
#include "gameNode.h"

class scene2_1;

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
	E_PLAYER_STATUS _ladderStatus;	//��ٸ� Ÿ���ִ� ����
	float _motion_Count;			// ĳ���� ���������� ��Ƕ��°�
	bool _isFlying;				// ĳ���� ���߿� ���ִ���
	bool _isLadderMotion;		// ��ٸ� ����� �����ϴ� ��
	animation* _motion;			// ĳ���� ���
	RECT _arrowRc;
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ������Ʈ �浹�ϴ� �߰��Ѱ�
	bool _isRushing;			//��������
	bool _isWall;
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ������Ʈ �浹�ϴ� �߰��Ѱ�

	//���߿� �θ����� �ű��
	bool _isWaterDead;
	bool _isDeadAni;

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

	//2019.01.17 ������ ����11���߰� ===================
	//ī�޶� ����������
	void setCameraX(float v) { _cameraX = v; }
	void setCameraY(float v) { _cameraY = v; }

	//ī�޶� �����������°� ����
	void UpdateCameraPos(float _cameraX, float _cameraY);
	//2019.01.17 ������ ����11���߰� ===================


	//�����ڵ�(get,set)

	POINTFLOAT getPos() { return _pos; }

	//�÷��̾� ���� ������, ������
	E_PLAYER_STATUS getCharacterStatus() { return _status; }
	void setCharacterStatus(E_PLAYER_STATUS status) { _status = status; }

	//�÷��̾� �ִϸ��̼� ������, ������
	animation* getCharacterMotion() { return _motion; }
	void setCharacterMotion(animation* motion) { _motion = motion; }

	//���� ������ �����ؼ� �÷��� �ϰ� �ִ��� �������ִ� ����(_isPlaying)����,������
	bool getIsPlaying() { return _isPlaying; }
	void setIsPlaying(bool isPlaying) { _isPlaying = isPlaying; }
	
	RECT getPlayerRc() { return _rc; }
	
	//status �ټ�(��)
	E_PLAYER_STATUS getStatus() { return _status; }
	void			setStatus(E_PLAYER_STATUS status) { _status = status; }

	//��ٸ� status �ټ�(��)
	E_PLAYER_STATUS getLadderStatus() { return _ladderStatus; }
	void			setLadderStatus(E_PLAYER_STATUS ladderStatus) { _ladderStatus = ladderStatus; }

	void			setPostionX(float posX) { _pos.x = posX; }

	void			setIsLadderMotion(bool isLadderMotion) { _isLadderMotion = isLadderMotion; }

	bool			getPlayerIsAlive() { return _isAlive;}

	int				getPlayerHp() { return _hp; }
	void			setPlayerHp(int hp) { _hp = hp; }



	//������Ʈ �浹�ϴ� �߰��Ѱ͵�
	bool getIsRushing() { return _isRushing; }
	void setIsRushing(bool value) { _isRushing = value; }

	virtual void setIsWall(bool value) { _isWall = value; }
	bool getIsWall() { return _isWall; }


	virtual void ericRightStun();
	virtual void ericLeftStun();


};

