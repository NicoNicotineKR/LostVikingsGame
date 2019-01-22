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
	IMAGEMANAGER->addFrameImage("icon_items", "images/UI/invenUI/icon_items.bmp", 38 * 5, 38, 5, 1, false, 0x000000);



	//	인벤UI이미지 추가 시작
	{
		IMAGEMANAGER->addFrameImage("invenCursor", "images/UI/invenUI/invenCursor.bmp", 52, 52, 1, 1, true, 0xFF00FF);
		IMAGEMANAGER->addFrameImage("invenFrame", "images/UI/invenUI/invenFrame.bmp", 1024, 199, 1, 1, false, 0x000000);
		IMAGEMANAGER->addFrameImage("charfaces", "images/UI/invenUI/charFaces.bmp", 297, 219, 3, 3, false, 0x000000);		//캐릭터 초상화 이미지 99*73
		IMAGEMANAGER->addFrameImage("hpIcon", "images/UI/invenUI/icon_hp.bmp", 20, 25, 1, 1, false, 0x000000);
	}	//	인벤UI이미지 추가 끝

	//	invenUI 변수 기본세팅 시작
	{
		_invenFrame.img = IMAGEMANAGER->findImage("invenFrame");
		_invenFrame.pos.x = 512;
		_invenFrame.pos.y = WINSIZEY - 100;
		_invenFrame.rc = RectMakeCenter(_invenFrame.pos.x, _invenFrame.pos.y, 1024, 199);

		_curCharIdx = 0;		//	커서 나머지는 밑에이씀

		//밑에는 hp아이콘 시작!
		for (int i = 0; i < 3; i++) 
		{
			POINT tmpPos;
			tmpPos.x = 154 + i*230;	//	허드 왼쪽, i x 초상화당
			tmpPos.y = WINSIZEY - 70 + 16;		//	맨밑부터 허드 일부뻄(시작위치) + 허드일부
			for (int j = 0; j < 3; j++)
			{	
				_hp[i * 3 + j].img = IMAGEMANAGER->findImage("hpIcon");
				_hp[i * 3 + j].pos.x = tmpPos.x + j * 26;
				_hp[i * 3 + j].pos.y = tmpPos.y;
				_hp[i * 3 + j].rc = RectMakeCenter(_hp[i * 3 + j].pos.x, _hp[i * 3 + j].pos.y, 20, 25);
			}
		}

		_isInvenMode = false;
		_isSelectItem = false;


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
					_inven[i][j][k].E_ITEM = E_EMPTY;
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

			_charInfo[i].hp = 3;				//	캐릭별로 hp 설정	----------------
			
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
	}	//	커서정보 초기화 끝





	////	테스트용 아이템
	//{
	//	_inven[0][0][0].E_ITEM = E_BOMB;
	//	_inven[0][0][0].name = "bomb";
	//
	//	_inven[1][0][0].E_ITEM = E_KEY_RED;
	//	_inven[1][0][0].name = "key_red";
	//
	//}
	//
	////	테스트용 죽음
	//{
	//	_charInfo[0].isDead = true;
	//}




	return S_OK;
}

void invenUI::release()
{
}

void invenUI::update()
{
	FaceSelectFunc();

	//	아이템 선택중이아닐때,
	if (!_isSelectItem)
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_isSelectItem = true;

			_sendInven = _inven[_curCharIdx][_charInfo[_curCharIdx].curInvenY][_charInfo[_curCharIdx].curInvenX];
			_sendPos.x = _receivePos.x = _charInfo[_curCharIdx].curInvenX;
			_sendPos.y = _receivePos.y = _charInfo[_curCharIdx].curInvenY;
			_sendIdx = _receiveIdx = _curCharIdx;

		}
		else
		{
			MoveCursorFunc();
			CursorBlinkFunc();
		}
	}

	//	아이템 선택중이라면,
	else if (_isSelectItem)
	{
		CursorBlinkFunc();
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_isSelectItem = false;
			SwapItem();

		}

		else if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			_receiveIdx++;
		RefreshRecieveIdx();


		if (_receiveIdx < 3)
		{
			bool isFound = false;

			//	찾지못했거나, 다음것이 휴지통이 아니라면 계쏙 찾아라
			while (_receiveIdx < 3)
			{
				if (_charInfo[_receiveIdx].isDead)		// 죽었을떄 스킵. 위에 체크 순서 조심
				{
					_receiveIdx++;
					RefreshRecieveIdx();
				}
				if (_receiveIdx == 3)	break;		//	휴지통일때 뷁

				if (_receiveIdx > 3) _receiveIdx = 0;
				//	받는 인덱스에서 맨처음 빈칸을 찾는다.  recievePos 갱신해준다.
				isFound = FindEmptyInven();

				if (isFound)	break;
				_receiveIdx++;
				RefreshRecieveIdx();


				

				
			}
		}

		// 휴지통
		//else if (_recieveIdx == 3)
		//{
		//	_cursor.pos.x = TRASHCAN_X;
		//	_cursor.pos.y = TRASHCAN_Y;
		//}



	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_receiveIdx--;
		RefreshRecieveIdx();

		if (_receiveIdx > -1)
		{
			bool isFound = false;

			//	찾지못했거나, 다음것이 휴지통이 아니라면 계쏙 찾아라
			while (-1 < _receiveIdx && _receiveIdx < 3)
			{
				if (_charInfo[_receiveIdx].isDead)		// 죽었을떄 스킵. 체크 순서 조심
				{
					_receiveIdx--;
					RefreshRecieveIdx();
				} 
				if (_receiveIdx == 3)	break;

				if (_receiveIdx < 0) _receiveIdx = 3;
				//	받는 인덱스에서 맨처음 빈칸을 찾는다.  recievePos 갱신해준다.
				isFound = FindEmptyInven();

				if (isFound)	break;
				_receiveIdx--;
				RefreshRecieveIdx();
				

				

			}
			

		}
		//else if (_recieveIdx == 3)
		//{
		//	_cursor.pos.x = TRASHCAN_X;
		//	_cursor.pos.y = TRASHCAN_Y;
		//}



	}
}


void invenUI::render()
{
	_invenFrame.img->render(getMemDC(), _invenFrame.rc.left, _invenFrame.rc.top);	//	맨위에 먼저 깔아둬야함(허드)
	
	//	hp 똥그라미 그려어어
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < _charInfo[i].hp; j++)
		{
			_hp[i * 3 + j].img->render(getMemDC(), _hp[i * 3 + j].rc.left, _hp[i * 3 + j].rc.top);
		}
	}


	//	인벤 내 아이템아이콘 출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				_inven[i][j][k].imgInfo.img->frameRender(getMemDC(),
					_inven[i][j][k].imgInfo.rc.left,
					_inven[i][j][k].imgInfo.rc.top,
					_inven[i][j][k].E_ITEM, 0);
			}
		}
	}



	//	아이템 옮기는중이 아니면,
	if (!_isSelectItem)
	{
		//_cursor.img->alphaRender(getMemDC(), _cursor.rc.left, _cursor.rc.top, _cursorAlpha);	//	허드 다음에 깔아야함
		for (int i = 0; i < 3; i++)
		{
			_cursor.img->render(getMemDC(),
				_inven[i][_charInfo[i].curInvenY][_charInfo[i].curInvenX].imgInfo.pos.x - _cursor.img->getFrameWidth() / 2,
				_inven[i][_charInfo[i].curInvenY][_charInfo[i].curInvenX].imgInfo.pos.y - _cursor.img->getFrameHeight() / 2);
			
		}
		
	}
		

	//	아이템 옮기는중이면,
	else if (_isSelectItem)
	{
		if (_receiveIdx != 3) 
		{
			_cursor.img->render(getMemDC(),
				_inven[_sendIdx][_sendPos.y][_sendPos.x].imgInfo.rc.left - 7,
				_inven[_sendIdx][_sendPos.y][_sendPos.x].imgInfo.rc.top - 7
			);


			_cursor.img->alphaRender(getMemDC(),
				_inven[_receiveIdx][_receivePos.y][_receivePos.x].imgInfo.rc.left - 7,
				_inven[_receiveIdx][_receivePos.y][_receivePos.x].imgInfo.rc.top - 7,
				_cursorAlpha);
		}
		else
		{
			_cursor.img->render(getMemDC(),
				_inven[_sendIdx][_sendPos.y][_sendPos.x].imgInfo.rc.left - 7,
				_inven[_sendIdx][_sendPos.y][_sendPos.x].imgInfo.rc.top - 7
			);
			_cursor.img->alphaRender(getMemDC(), TRASHCAN_X, TRASHCAN_Y, _cursorAlpha);
		}


	}


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



	sprintf_s(str, "%d", _objMgr->getObject2()->getvObjects()[0]._start);
	TextOut(getMemDC(), 100, 300, str, strlen(str));
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

void invenUI::SwapItem()
{
	if (_receiveIdx == 3)
	{
		
		_inven[_sendIdx][_sendPos.y][_sendPos.x].E_ITEM = E_EMPTY;
		_inven[_sendIdx][_sendPos.y][_sendPos.x].name = "empty";
	}

	else
	{
		tagInvenInfo tmpInven;
		tmpInven = _inven[_sendIdx][_sendPos.y][_sendPos.x];
		_inven[_sendIdx][_sendPos.y][_sendPos.x].imgInfo.img = _inven[_receiveIdx][_receivePos.y][_receivePos.x].imgInfo.img;
		_inven[_sendIdx][_sendPos.y][_sendPos.x].E_ITEM = _inven[_receiveIdx][_receivePos.y][_receivePos.x].E_ITEM;
		_inven[_sendIdx][_sendPos.y][_sendPos.x].name = _inven[_receiveIdx][_receivePos.y][_receivePos.x].name;

		_inven[_receiveIdx][_receivePos.y][_receivePos.x].E_ITEM = tmpInven.E_ITEM;
		_inven[_receiveIdx][_receivePos.y][_receivePos.x].imgInfo.img = tmpInven.imgInfo.img;
		_inven[_receiveIdx][_receivePos.y][_receivePos.x].name = tmpInven.name;
	}

}

bool invenUI::FindEmptyInven()
{
	bool isFind = false;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_inven[_receiveIdx][i][j].E_ITEM == E_EMPTY)
			{
				isFind = true;
				_receivePos.y = i;
				_receivePos.x = j;
			
				return isFind;
			}
				
			
			if (isFind)		break;
		}
		if (isFind)	break;
	}

	return isFind;
	
	
}

void invenUI::RefreshRecieveIdx()
{
	if (_receiveIdx < 0) _receiveIdx = 3;
	if (_receiveIdx > 3) _receiveIdx = 0;
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

void invenUI::AddItem(int charIdx, E_ITEMICONS kindof)
{

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (_inven[charIdx][i][j].E_ITEM != E_EMPTY)
				continue;

			_inven[charIdx][i][j].E_ITEM = kindof;
			return;

		}
	}
}

void invenUI::UsingItem(int charIdx)
{
	//enum E_ITEMICONS {
	//	E_EMPTY = 0,
	//	E_BOMB,
	//	E_KEY_RED,
	//	E_KEY_YELLOW,
	//	E_MEAT,
	//};

	E_ITEMICONS itemKinds;

	itemKinds = _inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM;

	switch (itemKinds)
	{
	case E_EMPTY:
		//	나띵 해픈드~ 나띵 해픈드~ 댄유
		break;

	case E_BOMB:
		//	폭탄 함수 실행
		//	사용했으니 제거
		_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		break;

	case E_KEY_YELLOW:
		
		//	잘 사용됐으면
		if(YellowKeyFunc())
			_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		break;

	case E_KEY_RED:
		//	잘 사용됐으면
		if (RedKeyFunc())
			_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		break;

	case E_MEAT:
		if (_charInfo[charIdx].hp < 3)
		{
			_charInfo[charIdx].hp += 1;
			_pm->getVCharInfo()[charIdx]->setPlayerHp(_charInfo[charIdx].hp);
			_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		}


		break;
	}
	

}

bool invenUI::YellowKeyFunc()
{
	//	잘 사용하면 true 리턴.
	RECT tmpRc;
	RECT TMP_YELLOW_KEYLOCK;
	TMP_YELLOW_KEYLOCK = _objMgr->getObject5()->getvObjects()[1]._rc;

	if (IntersectRect(&tmpRc, &(_pm->getVCharInfo()[_curCharIdx]->getPlayerRc()), &TMP_YELLOW_KEYLOCK))
	{
		//	오브젝트한테 사용했다는 신호주고
		_objMgr->getObject2()->setStart(true, 1);
		_objMgr->getObject5()->setStart(true, 1);

		return true;
		
	}

	return false;
	
}

bool invenUI::RedKeyFunc()
{
	//	잘 사용하면 true 리턴.
	RECT tmpRc;
	RECT TMP_RED_KEYLOCK;
	TMP_RED_KEYLOCK = _objMgr->getObject5()->getvObjects()[0]._rc;

	if (IntersectRect(&tmpRc, &(_pm->getVCharInfo()[_curCharIdx]->getPlayerRc()), &TMP_RED_KEYLOCK))
	{
		//	오브젝트한테 사용했다는 신호주고

		_objMgr->getObject2()->setStart(true, 0);
		_objMgr->getObject5()->setStart(true, 0);
		return true;

	}
	return false;
}

