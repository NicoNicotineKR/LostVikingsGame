#pragma once

//	gameNode.h에 include 되어이씀.
//	gameNode안쓰는 애라면, 직접 include 할 것.

//	============ 공동으로 사용하는 설정값들을 넣는 곳 ============ 
//	============          아래는 예시임			   ============ 

//	enum E_PLAYER_STATUS {
//		E_PLAYER_IDLE_LEFT = 0,
//		E_PLAYER_IDLE_RIGHT,
//	
//	};
//	
//	const int DOUBLE_CLICK_FRAME = 15;

enum E_PLAYER_INDEX{
	P_ERIC = 0,
	P_OLAF,
	P_BALEOG,
	OUT_OF_RANGE
};

enum E_SCENE_INDEX {
	E_TITLE = 0,
	E_MAINMENU,
	E_SCENE2_1,



	E_SCENE_IDX_END,

};

enum E_PLAYER_STATUS {
	P_R_IDLE = 0,		//	player right stop
	P_L_IDLE,			//	player left  stop

	P_R_MOVE,			//	player right move
	P_L_MOVE,			//	player left  move

	P_R_ON_LADDER,		//	player right on ladder
	P_L_ON_LADDER,		//	player left	 on ladder

	P_R_HIT,			//	player right hit
	P_L_HIT,			//	player left	 hit

	P_R_WALL_PUSH,		//	player right wall push
	P_L_WALL_PUSH,		//	player left	 wall push

	P_R_HIT_DEATH,		//	player right hit death
	P_L_HIT_DEATH,		//	player left	 hit death

	P_R_WATER_DEATH,	//	player right water death
	P_L_WATER_DEATH,	//	player left  water death

	P_R_FALL_DEATH,		//	player right falldown death
	P_L_FALL_DEATH,		//	player left  falldown death

	P_R_FLYING,			//	player right flying - no damege
	P_L_FLYING,			//	player left  flying - no damege

	P_R_FALLING,		//	player right falling
	P_L_FALLING,		//	player left  falling

	P_R_STUN,			//	player right stun
	P_L_STUN,			//	player left  stun

	P_R_MOTION_ONE,		//	player right motion1 - over time to blink eye(eric, baleog) & nostril dig(olaf)
	P_L_MOTION_ONE,		//	player left  motion1 - over time to blink eye(eric, baleog) & nostril dig(olaf)

	P_R_MOTION_TWO,		//	player right motion2 - over time to motion start
	P_L_MOTION_TWO,		//	player left	 motion2 - over time to motion start

	P_R_SKILL_ONE,		//	right eric(jump), olaf(shiled switch), baleog(sword)
	P_L_SKILL_ONE,		//	left  eric(jump), olaf(shiled switch), baleog(sword)

	P_R_SKILL_TWO,		//	right eric(rush), olaf(shiled switch), baleog(Arrow)
	P_L_SKILL_TWO,		//	left eric(rush), olaf(shiled switch), baleog(Arrow)

	P_R_BREATH = 30,	//	에릭 전용 숨쉬는 모션 이넘값
	P_L_BREATH,

	P_LADDER_PAUSE = 32,    //32
	P_LADDER_UP,
	P_LADDER_DOWN,
	P_LADDER_NULL
};



//	============	알아서 추가하시오		============

struct tagVector2D {
	double x;
	double y;
};

struct tagVector3D {
	double x;
	double y;
	double z;
};


