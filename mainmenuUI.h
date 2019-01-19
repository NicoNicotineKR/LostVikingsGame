#pragma once
#include "gameNode.h"
#include <vector>

class mainmenuUI : public gameNode
{
private:
	struct tagButton {
		string name;
		image* img;
		RECT rc;
		POINT pos;
	};

	vector<tagButton> _vButton;
	
	image* _cursorImg;
	RECT _cursorRc;
	POINT _cursorPos;
	int _curCursorIdx;

	bool _isPressEnter;

	const int BUTTON_GAP_HEIGTH = 100;		//	버튼간 세로 간격
	const int CURSOR_GAP_WIDTH = 20;		//	커서의 떨어짐 간격

	
public:
	mainmenuUI();
	~mainmenuUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void AddNewButton(string name, string imgKeyName, int x, int y);
	void MakeCursorPos(int idx);
	void RefreshCursorIdx();


	int getCursorIdx() { return _curCursorIdx; }
	void setCursorIdx(int idx) { _curCursorIdx = idx; }

	int getIsPressEnter() { return _isPressEnter; }
	void setIsPressEnter(bool value) { _isPressEnter = value; }

};

