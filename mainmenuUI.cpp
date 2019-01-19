#include "stdafx.h"
#include "mainmenuUI.h"


mainmenuUI::mainmenuUI()
{
}


mainmenuUI::~mainmenuUI()
{
}

HRESULT mainmenuUI::init()
{
	
	IMAGEMANAGER->addImage("menuCursor", "images/UI/mainmenuUI/icon_cursor.bmp", 40, 40, false, 0x000000);
	IMAGEMANAGER->addImage("button_STARTGAME", "images/UI/mainmenuUI/button_STARTGAME.bmp", 364, 40, false, 0x000000);


	_vButton.clear();
	//	버튼 추가 시이자악
	AddNewButton("STARTGAME", "button_STARTGAME", WINSIZEX / 2, WINSIZEY / 2);			//	첫놈만 중앙에서 시작

	AddNewButton("STARTGAME", "button_STARTGAME", WINSIZEX / 2, 
		_vButton[0].rc.bottom + BUTTON_GAP_HEIGTH + IMAGEMANAGER->findImage("button_STARTGAME")->getFrameHeight() / 2);

	AddNewButton("STARTGAME", "button_STARTGAME", WINSIZEX / 2, 
		_vButton[1].rc.bottom + BUTTON_GAP_HEIGTH + IMAGEMANAGER->findImage("button_STARTGAME")->getFrameHeight() / 2);


	//	버튼 추가 끝
	


	//	커서 시작
	_cursorImg = IMAGEMANAGER->findImage("menuCursor");
	_curCursorIdx = 0;
	MakeCursorPos(_curCursorIdx);
	//	커서 끝


	_isPressEnter = false;


	return S_OK;
}

void mainmenuUI::release()
{
}

void mainmenuUI::update()
{
	//	커서 인덱스 증감하고,
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))		_curCursorIdx++;
	if (KEYMANAGER->isOnceKeyDown(VK_UP))		_curCursorIdx--;

	RefreshCursorIdx();					//	인덱스 범위 벗어나면 인덱스 다시 잡아주고
	MakeCursorPos(_curCursorIdx);		//	커서 좌표 및 렉트 설정

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))	_isPressEnter = true;


}

void mainmenuUI::render()
{
	_cursorImg->render(getMemDC(), _cursorRc.left, _cursorRc.top);

	for (int i = 0; i < _vButton.size(); i++)
	{
		_vButton[i].img->render(getMemDC(),
			_vButton[i].rc.left,
			_vButton[i].rc.top);
	}

	//	테스트용 코드
	//char str[128];
	//sprintf_s(str, "_cursorIdx : %d", _curCursorIdx);
	//TextOut(getMemDC(), 100, 100, str, strlen(str));

}

void mainmenuUI::AddNewButton(string name, string imgKeyName, int x, int y)
{
	tagButton tmpButton;

	tmpButton.name = name;
	tmpButton.img = IMAGEMANAGER->findImage(imgKeyName);
	tmpButton.pos = { x, y };
	tmpButton.rc = RectMakeCenter(x, y, tmpButton.img->GetWidth(), tmpButton.img->GetHeight());
	_vButton.push_back(tmpButton);
}

void mainmenuUI::MakeCursorPos(int idx)
{
	_cursorPos.x = _vButton[idx].rc.left - CURSOR_GAP_WIDTH - _cursorImg->GetWidth() / 2;
	_cursorPos.y = _vButton[idx].pos.y;
	_cursorRc = RectMakeCenter(_cursorPos.x, _cursorPos.y, _cursorImg->GetWidth(), _cursorImg->GetHeight());
}

void mainmenuUI::RefreshCursorIdx()
{
	if (_curCursorIdx < 0)
		_curCursorIdx = _vButton.size() - 1;

	if (_vButton.size() - 1 < _curCursorIdx)
		_curCursorIdx = 0;
	
}
