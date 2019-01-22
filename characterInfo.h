#pragma once
#include "gameNode.h"

class scene2_1;

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
	E_PLAYER_STATUS _ladderStatus;	//사다리 타고있는 상태
	float _motion_Count;			// 캐릭터 가만있으면 모션띄우는거
	bool _isFlying;				// 캐릭터 공중에 떠있는지
	bool _isLadderMotion;		// 사다리 모션을 실행하는 불
	animation* _motion;			// 캐릭터 모션
	RECT _arrowRc;
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오브젝트 충돌하다 추가한것
	bool _isRushing;			//에릭전용
	bool _isWall;
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 오브젝트 충돌하다 추가한것

	//나중에 부모한테 옮길것
	bool _isWaterDead;
	bool _isDeadAni;

	float _cameraX;				// 맵 카메라 담을 공간 x
	float _cameraY;				// 맵 카메라 담을 공간 y

	//픽셀충돌
	//===========유형우추가============
	int _r, _g, _b;
	int _probeY;
	//===========유형우추가============

public:
	characterInfo();
	~characterInfo();
	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();

	//픽셀충돌
	//===========유형우추가============
	virtual void PixelCrash();
	//===========유형우추가============

	//2019.01.17 유형우 오후11시추가 ===================
	//카메라 정보가져옴
	void setCameraX(float v) { _cameraX = v; }
	void setCameraY(float v) { _cameraY = v; }

	//카메라 정보가져오는거 묶음
	void UpdateCameraPos(float _cameraX, float _cameraY);
	//2019.01.17 유형우 오후11시추가 ===================


	//접근자들(get,set)

	POINTFLOAT getPos() { return _pos; }

	//플레이어 상태 접근자, 설정자
	E_PLAYER_STATUS getCharacterStatus() { return _status; }
	void setCharacterStatus(E_PLAYER_STATUS status) { _status = status; }

	//플레이어 애니메이션 접근자, 설정자
	animation* getCharacterMotion() { return _motion; }
	void setCharacterMotion(animation* motion) { _motion = motion; }

	//현재 누구를 선택해서 플레이 하고 있는지 설정해주는 변수(_isPlaying)접근,설정자
	bool getIsPlaying() { return _isPlaying; }
	void setIsPlaying(bool isPlaying) { _isPlaying = isPlaying; }
	
	RECT getPlayerRc() { return _rc; }
	
	//status 겟셋(기)
	E_PLAYER_STATUS getStatus() { return _status; }
	void			setStatus(E_PLAYER_STATUS status) { _status = status; }

	//사다리 status 겟셋(기)
	E_PLAYER_STATUS getLadderStatus() { return _ladderStatus; }
	void			setLadderStatus(E_PLAYER_STATUS ladderStatus) { _ladderStatus = ladderStatus; }

	void			setPostionX(float posX) { _pos.x = posX; }

	void			setIsLadderMotion(bool isLadderMotion) { _isLadderMotion = isLadderMotion; }

	bool			getPlayerIsAlive() { return _isAlive;}

	int				getPlayerHp() { return _hp; }
	void			setPlayerHp(int hp) { _hp = hp; }



	//오브젝트 충돌하다 추가한것들
	bool getIsRushing() { return _isRushing; }
	void setIsRushing(bool value) { _isRushing = value; }

	virtual void setIsWall(bool value) { _isWall = value; }
	bool getIsWall() { return _isWall; }


	virtual void ericRightStun();
	virtual void ericLeftStun();


};

