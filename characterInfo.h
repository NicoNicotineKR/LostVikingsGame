#pragma once
#include "gameNode.h"

class characterInfo : public gameNode
{
protected:
	image* _img;				// 캐릭터 이미지
	RECT _rc;					// 캐릭터 렉트
	POINTFLOAT _pos;			// 캐릭터 좌표
	tagVector2D _vec;			// 캐릭터 이동할값
	float _gravity;				// 캐릭터 중력
	float _speed;				// 캐릭터 속도
	int _hp;					// 캐릭터 체력
	string _itemSlot[4];		// 캐릭터 아이템칸
	bool _isPlaying;			// 캐릭터 플레이중인지 여부
	bool _isAlive;				// 캐릭터 살아있는지 여부
	E_PLAYER_STATUS _status;	// 캐릭터 상태
	int _motion_Count;			// 캐릭터 가만있으면 모션띄우는거
	bool _isFlying;				// 캐릭터 공중에 떠있는지
	animation* _motion;			// 캐릭터 모션
	bool _isMotionPlay;				// 캐릭터 모션을 한번만 실행해라

	float _cameraX;				// 맵 카메라 담을 공간 x
	float _cameraY;				// 맵 카메라 담을 공간 y

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update(int characterSelect, float cameraX, float cameraY);
	virtual void render();

	virtual void move();


	POINTFLOAT getPos() { return _pos; }

	//플레이어 상태 접근자, 설정자
	E_PLAYER_STATUS getCharacterStatus() { return _status; }
	void setCharacterStatus(E_PLAYER_STATUS status) { _status = status; }
	//플레이어 애니메이션 접근자, 설정자
	animation* getCharacterMotion() { return _motion; }
	void setCharacterMotion(animation* motion) { _motion = motion; }
};

