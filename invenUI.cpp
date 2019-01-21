#include "stdafx.h"
#include "invenUI.h"


invenUI::invenUI()
{
}


invenUI::~invenUI()
{
}

HRESULT invenUI::init()
{
	//	아이템슬롯 이미지 추가 시작
	IMAGEMANAGER->addFrameImage("icon_items", "images/UI/invenUI/icon_items.bmp", 38, 38, 1, 1, false, 0x000000);



	//	인벤UI이미지 추가 시작
	{
		IMAGEMANAGER->addFrameImage("invenCursor", "images/UI/invenUI/invenCursor.bmp", 52, 52, 1, 1, true, 0xFF00FF);
		IMAGEMANAGER->addFrameImage("invenFrame", "images/UI/invenUI/invenFrame.bmp", 1024, 199, 1, 1, false, 0x000000);
		IMAGEMANAGER->addFrameImage("charfaces", "images/UI/invenUI/charFaces.bmp", 297, 219, 3, 3, false, 0x000000);		//캐릭터 초상화 이미지 99*73

	}	//	인벤UI이미지 추가 끝

	//	invenUI 변수 기본세팅 시작
	{
		_invenFrame.img = IMAGEMANAGER->findImage("invenFrame");
		_invenFrame.pos.x = 512;
		_invenFrame.pos.y = WINSIZEY - 100;
		_invenFrame.rc = RectMakeCenter(_invenFrame.pos.x, _invenFrame.pos.y, 1024, 199);

		_curCharIdx = 0;

		_isInvenMode = false;
	}	//	invenUI 변수 기본세팅 끝


	//	인벤정보 초기화 시작
	{
		POINT tmpPos;
		for (int i = 0; i < 3; i++)
		{
			tmpPos.x = 255 + 25 + (i * 230); // 시작위치 + i*초상화가로
			tmpPos.y = WINSIZEY - _invenFrame.img->getFrameHeight() + 58 + 20;	// 맨밑에서 -> 허드만큼 위로올라갔다가-> 허드두꼐만큼 내려오고 -> 아이템창세로반 내려옴
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					_inven[i][j][k].name = "empty";
					_inven[i][j][k].imgInfo.img = IMAGEMANAGER->findImage("icon_items");
					_inven[i][j][k].imgInfo.pos.x = tmpPos.x;
					_inven[i][j][k].imgInfo.pos.y = tmpPos.y;
					_inven[i][j][k].imgInfo.rc = RectMakeCenter(tmpPos.x, tmpPos.y, 38, 38);
					tmpPos.x += 50;	//	아이템창 한개 가로
				}

				tmpPos.y += 50;		//	아이템창 한개 세로
				tmpPos.x = 255 + 25 + (i * 230); // 시작위치 + i*초상화가로
			}
		}

	}	//	인벤정보 초기화 끝


	//	캐릭터 정보 초기화 시작
	{
		POINT tmpPos;
		
		for (int i = 0; i < 3; i++)
		{
			tmpPos.x = 146 + 106 / 2 + (i * 230);							// 허드왼쪽가로146 캐릭터창가로106 + (한폭)
			tmpPos.y = WINSIZEY - 64 - (82 / 2);				//	허드밑 세로64 캐릭터창 세로 82

			_charInfo[i].faceImgInfo.img = IMAGEMANAGER->findImage("charfaces");
			_charInfo[i].faceImgInfo.pos.x = tmpPos.x;
			_charInfo[i].faceImgInfo.pos.y = tmpPos.y;
			_charInfo[i].faceImgInfo.rc = RectMakeCenter(tmpPos.x, tmpPos.y, 99, 73);		//	초상화 가로세로


			_charInfo[i].curInvenX = 0;
			_charInfo[i].curInvenY = 0;
			_charInfo[i].faceFrameX = 1;
			_charInfo[i].faceFrameY = i;		//	캐릭터별 이미지프레임이니까

			_charInfo[i].hp = i + 1;				//	캐릭별로 hp 설정	----------------
			
			//	hp이미지 콤보 초기화
			
			_charInfo[i].isDead = false;

		}
		_charInfo[0].faceFrameX = 0;
	}	//	캐릭터 정보 초기화 끝


	//	커서정보 초기화 시작
	{
		_cursor.img = IMAGEMANAGER->findImage("invenCursor");
		_cursorAlpha = 0;
		_isCursorAlphaRise = false;
		MakeCursorPos(_curCharIdx);		//	_curCharIdx 위에 초기화 해둠 : 0
	}
	

	//	커서정보 초기화 끝



	return S_OK;
}

void invenUI::release()
{
}

void invenUI::update()
{
	MoveCursorFunc();
	CursorBlinkFunc();
	FaceSelectFunc();
}

void invenUI::render()
{
	_invenFrame.img->render(getMemDC(), _invenFrame.rc.left, _invenFrame.rc.top);	//	맨위에 먼저 깔아둬야함(허드)
	_cursor.img->alphaRender(getMemDC(), _cursor.rc.left, _cursor.rc.top, _cursorAlpha);	//	허드 다음에 깔아야함


	for (int i = 0; i < 3; i++)
	{
		_charInfo[i].faceImgInfo.img->frameRender(getMemDC(),
			_charInfo[i].faceImgInfo.rc.left, _charInfo[i].faceImgInfo.rc.top,
			_charInfo[i].faceFrameX, _charInfo[i].faceFrameY);
	}

	//	밑에는 테스트용 =============


	if (KEYMANAGER->isToggleKey(VK_NUMPAD0))
	{
		char tmpstr[128];
		sprintf_s(tmpstr, "_selectCharIdx : %d", _curCharIdx);
		TextOut(getMemDC(), 0, 300, tmpstr, strlen(tmpstr));
		sprintf_s(tmpstr, "curInvenX : %d", _charInfo[_curCharIdx].curInvenX);
		TextOut(getMemDC(), 0, 320, tmpstr, strlen(tmpstr));
		sprintf_s(tmpstr, "curInvenY : %d", _charInfo[_curCharIdx].curInvenY);
		TextOut(getMemDC(), 0, 340, tmpstr, strlen(tmpstr));
		sprintf_s(tmpstr, "_cursorPosX : %d", _cursor.pos.x);
		TextOut(getMemDC(), 0, 360, tmpstr, strlen(tmpstr));
		sprintf_s(tmpstr, "_cursorPosY : %d", _cursor.pos.y);
		TextOut(getMemDC(), 0, 380, tmpstr, strlen(tmpstr));

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					Rectangle(getMemDC(), _inven[i][j][k].imgInfo.rc);
				}
			}
			Rectangle(getMemDC(), _charInfo[i].faceImgInfo.rc);


		}

		Rectangle(getMemDC(), _cursor.rc);

	}	//	렉모드 끝
}



void invenUI::MakeDead(int charIdx)
{
	_charInfo[charIdx].isDead = true;
	_charInfo[charIdx].faceFrameX = 2;
}


void invenUI::MakeCursorPos(int charIdx)
{
	_cursor.pos.x = _inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].imgInfo.pos.x;		//	인벤[현재선택한캐릭터][현재선택한캐릭터의 인벤y][현재선택한캐릭터의 인벤x] 의 좌표
	_cursor.pos.y = _inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].imgInfo.pos.y;		//	인벤[현재선택한캐릭터][현재선택한캐릭터의 인벤y][현재선택한캐릭터의 인벤x] 의 좌표
	_cursor.rc = RectMakeCenter(_cursor.pos.x, _cursor.pos.y, 52, 52);
}

void invenUI::CursorBlinkFunc()
{
	//	증감 결정
	if (_cursorAlpha >= 255)		_isCursorAlphaRise = false;
	else if (_cursorAlpha <= 0)		_isCursorAlphaRise = true;

	//	알파값 조절
	if (_isCursorAlphaRise)			_cursorAlpha += CURSOR_BLINKSPD;
	else if (!_isCursorAlphaRise)	_cursorAlpha -= CURSOR_BLINKSPD;

	//	혹시 넘칠까봐 넣어둠.
	if (_cursorAlpha >= 255)		_cursorAlpha = 255;
	else if (_cursorAlpha <= 0)		_cursorAlpha = 0;
}

void invenUI::MoveCursorFunc()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_charInfo[_curCharIdx].curInvenX--;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_charInfo[_curCharIdx].curInvenX++;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_charInfo[_curCharIdx].curInvenY--;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_charInfo[_curCharIdx].curInvenY++;
	}

	ReposCursorFunc();
	MakeCursorPos(_curCharIdx);

}

void invenUI::ReposCursorFunc()
{
	if (_charInfo[_curCharIdx].curInvenX > 1)	_charInfo[_curCharIdx].curInvenX = 1;
	if (_charInfo[_curCharIdx].curInvenX < 0)	_charInfo[_curCharIdx].curInvenX = 0;
	if (_charInfo[_curCharIdx].curInvenY > 1)	_charInfo[_curCharIdx].curInvenY = 1;
	if (_charInfo[_curCharIdx].curInvenY < 0)	_charInfo[_curCharIdx].curInvenY = 0;
}

void invenUI::FaceSelectFunc()
{
	for (int i = 0; i < 3; i++) 
	{
		_charInfo[i].faceFrameX = 1;		//순서주의. 디폴트로 1

		if (i == _curCharIdx)
			_charInfo[i].faceFrameX = 0;	//순서주의. 선택된놈만 0
		if (_charInfo[i].isDead)
			_charInfo[i].faceFrameX = 2;	//순서주의. 죽은놈은 2	//	사실DeadFunc()에서해놨긴하지만 혹시몰라서 ㅇㅇ;

	}
}

