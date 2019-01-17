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
	bool _isFlying				// 캐릭터 공중에 떠있는지


public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
};

