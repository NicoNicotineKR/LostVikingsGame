#pragma once
#include "gameNode.h"
#include "mainmenuUI.h"
#include "invenUI.h"

//	UI들을 관할합니다.

class UIs : public gameNode
{
private:

	enum E_CUR_UI
	{
		E_NONE,
		E_MAINMENU,
		E_INVEN,

		E_UI_SORT_END,
	};


	mainmenuUI* _mainmenu;		//	메인메뉴 씬에서만 사용합니다. 사용할떄마다 이닛-릴리즈
	invenUI*	_inven;

	int				_curScene;				//	현재 씬 정보 -> 선택적으로 UI들 출력해dream
	E_PLAYER_INDEX _selectCharIdx;			//	현재 선택된 캐릭터 인덱스 이너어어엄

	


public:
	UIs();
	~UIs();


	HRESULT init();
	void release();
	void update();
	void render();

	void ChooseUIbyScene();		//	씬별로 실행UI 결정쓰
	

	//	UI들 이닛 - 릴리즈
	void initMainmenu();		
	void initInven();
	void releaseMainmenu();
	void releaseInven();


	//	개새들 모음
	E_PLAYER_INDEX getSelectChar() { return _selectCharIdx; }
	void setSelectChar(E_PLAYER_INDEX idx) { _selectCharIdx = idx; }

	int getCurScene() { return _curScene; }
	void setCurScene(int idx) { _curScene = idx; }		//	씬도 



};

