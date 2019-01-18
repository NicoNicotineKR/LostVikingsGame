#pragma once
#include "gameNode.h"

class camera : public gameNode
{
private:
	//ī�޶�
	image* _NowMap;
	float _camerax;
	float _cameray;

	//�÷��̾�ü��������
	bool playerChange;

	//ü���������϶� �����༮�� ��ġ�� ī�޶�ӵ�
	float _posX;
	float _posY;
	float _cameraSpeed;

	//��������
	float _playerx;
	float _playery;

	//_posX,_posY�ѹ�������
	bool posInit;

	//Ȯ�ο�
	char str[600];

	//�����ð��ڿ� �÷��̾���� (Ȥ�ø� ������)
	int countFix;
	const int COUNT = 1000;

public:
	camera();
	~camera();

	HRESULT init();
	void release();
	void update();
	void render();

	float Getmapx() { return _camerax; }
	float Getmapy() { return _cameray; }

	void SetPlayerChange(bool v) { playerChange = v; }

	void SetPosX(float v) { _posX = v; }
	void SetPosY(float v) { _posY = v; }

	// Tap������ ������ �ٲ� - �ٲ޸��
	void PlayerChangeMode();
	//_posX,_posY�ѹ�������
	void PosInitFuc();
	//ī�޶� �������̵� �����°Ź���
	void CameraMoveFunc();
	//�����ð��ڿ� �÷��̾���� (Ȥ�ø� ������)
	void CameraFix();
	//������ ���������� !!
	void ChangeCharFunc(bool isPlayerChange, bool isPosInit, float posX, float posY, int CountFix);
	// ī�޶� �÷��̾� ���� - �߰ݸ��
	void PlayerChaseMode();
	// ��������
	void DontGoOutMapFuc();

	void SetPosInit(bool v) { posInit = v; }
	void SetCountFix(int v) { countFix = v; }

	//2019.01.17 ����11���߰� ===================
	//��������������
	void SetPlayerX(float v) { _playerx = v; }
	void SetPlayerY(float v) { _playery = v; }
	void SetCameraSpeed(float v) { _cameraSpeed = v; }
	void SetNowMap(image* v) { _NowMap = v; }

	//�������� �������°� ����

	//ī�޶� ������ ��ǥ������ �����ͼ���
	//UpdateEricPos
	//SettingPlayerPos();
	//UpdatePlayerPos or cameraChangespeedsetting or 
	//UpdatePlayerPos,
	//camera->BringEricPos();
	void UpdatePlayerPos(float _playerx, float _playery, float _cameraSpeed, image* _NowMap);
	//2019.01.17 ����11���߰� ===================
};

