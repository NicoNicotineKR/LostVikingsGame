#pragma once
#include "gameNode.h"

class invenUI : public gameNode
{
private:
	struct tagImgCombo {
		image* img;
		RECT rc;
		POINT pos;
	};


	struct tagInvenInfo {
		tagImgCombo imgInfo;
		string name;

	};
	struct tagCharInfo {
		tagImgCombo faceImgInfo;

		int faceFrameX;
		int faceFrameY;
		int curInvenX;
		int curInvenY;

		int hp;
		tagImgCombo hpImgInfo[3];

		bool isDead;
	};

	tagInvenInfo _inven[3][2][2];
	tagCharInfo _charInfo[3];
	tagImgCombo _invenFrame;
	tagImgCombo _cursor;
	int _cursorAlpha;
	bool _isCursorAlphaRise;

	int _curCharIdx;
	bool _isInvenMode;
	

	const int CURSOR_BLINKSPD = 15;



public:
	invenUI();
	~invenUI();

	HRESULT init();
	void release();
	void update();
	void render();


	void MakeDead(int charIdx);

	void MakeCursorPos(int charIdx);
	void CursorBlinkFunc();
	void MoveCursorFunc();
	void ReposCursorFunc();		//	인벤밖으로 커서 나가는거 방지

	void FaceSelectFunc();



	int getSelectCharIdx() { return _curCharIdx; }
	void setSelectCharIdx(int charIdx) { _curCharIdx = charIdx; }


	void setInvenMode(bool isInvenMode) { _isInvenMode = isInvenMode; }
	bool getInvenMode() { return _isInvenMode; }


	void setCursorAlpha(int alpha) { _cursorAlpha = alpha; }

};

