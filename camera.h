#pragma once
#include "gameNode.h"

class camera : public gameNode
{
private:
	//카메라
	image* _NowMap;
	float _camerax;
	float _cameray;

	//플레이어체인지상태
	bool playerChange;

	//체인지상태일때 다음녀석의 위치와 카메라속도
	float _posX;
	float _posY;
	float _cameraSpeed;

	//정보담기용
	float _playerx;
	float _playery;
	
	//_posX,_posY한번만실행
	bool posInit;

	//확인용
	char str[600];

	//일정시간뒤에 플레이어고정 (혹시모를 수리용)
	int countFix;
	const int COUNT = 1000;

public:
	camera();
	~camera();

	HRESULT init();
	void release();
	void update(float playerx,float playery,float speed, image* map);
	void render();

	float Getmapx(){return _camerax;}
	float Getmapy(){return _cameray;}

	void SetPlayerChange(bool v){ playerChange = v;}

	void SetPosX(float v){ _posX = v;}
	void SetPosY(float v){ _posY = v;}

	// Tap누를시 영웅을 바꿈 - 바꿈모드
	void PlayerChangeMode();
	//_posX,_posY한번만실행
	void PosInitFuc();
	//카메라 마지막이동 뻑나는거방지
	void CameraMoveFunc();
	//일정시간뒤에 플레이어고정 (혹시모를 수리용)
	void CameraFix();
	//씬에서 정보가져옴 !!
	void ChangeCharFunc(bool isPlayerChange, bool isPosInit, float posX, float posY, int CountFix);
	// 카메라가 플레이어 추적 - 추격모드
	void PlayerChaseMode();
	// 가지마라
	void DontGoOutMapFuc();

	void SetPosInit(bool v){ posInit = v;}
	void SetCountFix(int v){ countFix = v;}
};

