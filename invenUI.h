#pragma once
#include "gameNode.h"
#include "playerMgr.h"
#include "objectMgr.h"
//#include <map>

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
		E_ITEMICONS E_ITEM;

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
	struct tagItemInfo {
		string name;
		int curInvenX;
		int curInvenY;
	};

	//map<E_ITEMICONS, tagInvenInfo> _mItems;
	//map<E_ITEMICONS, tagInvenInfo> _miItems;

	tagInvenInfo _inven[3][2][2];
	tagCharInfo _charInfo[3];
	tagImgCombo _invenFrame;
	tagImgCombo _cursor;
	int _cursorAlpha;
	bool _isCursorAlphaRise;
	tagImgCombo _hp[9];

	int _curCharIdx;
	bool _isInvenMode;
	
	bool _isSelectItem;
	tagInvenInfo _sendInven;
	POINT _sendPos;
	POINT _receivePos;
	int _sendIdx;
	int _receiveIdx;

	playerMgr* _pm;
	objectMgr* _objMgr;


	const int CURSOR_BLINKSPD = 15;
	const int ITEM_ICON_WIDTH = 38;
	const int ITEM_ICON_HEIGTH = 38;

	const int TRASHCAN_X = 816;
	const int TRASHCAN_Y = WINSIZEY - 149;

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


	void SwapItem();

	bool FindEmptyInven();		//	curChar의 빈공간 찾으면, 커서 위치해줌
	void RefreshRecieveIdx();

	void FaceSelectFunc();

	void AddItem(int charIdx, E_ITEMICONS kindof);

	//	usingItem은 씬에서 keymanager->C 버튼으로 쓰인다.
	//	사용한 아이템에따라효과 적용해줌
	void UsingItem(int charIdx);
	bool YellowKeyFunc();
	bool RedKeyFunc();


	int getSelectCharIdx() { return _curCharIdx; }
	void setSelectCharIdx(int charIdx) { _curCharIdx = charIdx; }


	void setInvenMode(bool isInvenMode) { _isInvenMode = isInvenMode; }
	bool getInvenMode() { return _isInvenMode; }


	void setCursorAlpha(int alpha) { _cursorAlpha = alpha; }

	void setIsSelectItem(bool value) { _isSelectItem = value; }

	//	어떤 캐릭의, 현재hp
	void setCharHp(int charIdx, int curHp) { _charInfo[charIdx].hp = curHp; }

	void AddressLinkToPlayerManager(playerMgr* pm) { _pm = pm; }
	void AddressLinkToObjectMgr(objectMgr* objMgr) { _objMgr = objMgr; }

};

