#pragma once
#include "gameNode.h"
#include "mainmenuUI.h"
#include "invenUI.h"

//	UI���� �����մϴ�.

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


	mainmenuUI* _mainmenu;		//	���θ޴� �������� ����մϴ�. ����ҋ����� �̴�-������
	invenUI*	_inven;

	int				_curScene;				//	���� �� ���� -> ���������� UI�� �����dream
	E_PLAYER_INDEX _selectCharIdx;			//	���� ���õ� ĳ���� �ε��� �̳ʾ���

	


public:
	UIs();
	~UIs();


	HRESULT init();
	void release();
	void update();
	void render();

	void ChooseUIbyScene();		//	������ ����UI ������
	

	//	UI�� �̴� - ������
	void initMainmenu();		
	void initInven();
	void releaseMainmenu();
	void releaseInven();


	//	������ ����
	E_PLAYER_INDEX getSelectChar() { return _selectCharIdx; }
	void setSelectChar(E_PLAYER_INDEX idx) { _selectCharIdx = idx; }

	int getCurScene() { return _curScene; }
	void setCurScene(int idx) { _curScene = idx; }		//	���� 



};

