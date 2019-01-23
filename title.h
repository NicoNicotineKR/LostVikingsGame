#pragma once
#include "gameNode.h"
#include <vector>
class title : public gameNode
{
	

	image* _titleImg;		//	타이틀
	image* _mainmenuImg;
	image* _redcrossImg;
	
	image* _vugKingImg;

	int _titleAlphaValue;
	int _mainmenuAlphaValue;

	bool _isFadeStart;
	bool _isTitleEnd;
	bool _isRedCrossStart;
	bool _isVugStart;
	
	
	
	
	bool _isSceneEnd;
	

	int _showFrameCount;
	int _titleEndCount;		//	타이틀 끝나고 카운트 시작
	int _redcrossCount;		//	x자 그려진다음 카운트 시작
	
	int _waitingCount;		//	트렘블 종료후 잠시기다림
	
	

	const int ALPHA_VALUE_SPD = 25;			//	페이드 하는 속도, 클수록 타이틀->메뉴장면으로 빨리전환됨
	const int TITLE_SHOW_FRAME = 60;		//	60~120  / 프레임 이후, 페이드작업 스타트
	const int REDCROSS_START_FRAME = 60;	//	60~120 / 페이드후, 레드크로스 나오기까지 기다리는 프레임
	const int VUG_START_FRAME = 120;		//	60~120	//	x자 후, Vug로 바뀌기까지 기다리는 프레임, (vug실행되면 x자 사라짐)
	const int WAITING_FRAME = 60;			//	60~120	/ vug까지 하고, 메인메뉴UI가 호출될때까지 기다리는 시간
	
	


public:
	title();
	~title();

	HRESULT init();
	void release();
	void update();
	void render();

	void TitleFade();
	void FadeFunc();




	bool getIsSceneEnd() { return _isSceneEnd; }


};

