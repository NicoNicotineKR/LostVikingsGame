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
	//	�����۽��� �̹��� �߰� ����
	IMAGEMANAGER->addFrameImage("icon_items", "images/UI/invenUI/icon_items.bmp", 38 * 5, 38, 5, 1, false, 0x000000);



	//	�κ�UI�̹��� �߰� ����
	{
		IMAGEMANAGER->addFrameImage("invenCursor", "images/UI/invenUI/invenCursor.bmp", 52, 52, 1, 1, true, 0xFF00FF);
		IMAGEMANAGER->addFrameImage("invenFrame", "images/UI/invenUI/invenFrame.bmp", 1024, 199, 1, 1, false, 0x000000);
		IMAGEMANAGER->addFrameImage("charfaces", "images/UI/invenUI/charFaces.bmp", 297, 219, 3, 3, false, 0x000000);		//ĳ���� �ʻ�ȭ �̹��� 99*73
		IMAGEMANAGER->addFrameImage("hpIcon", "images/UI/invenUI/icon_hp.bmp", 20, 25, 1, 1, false, 0x000000);
	}	//	�κ�UI�̹��� �߰� ��

	//	invenUI ���� �⺻���� ����
	{
		_invenFrame.img = IMAGEMANAGER->findImage("invenFrame");
		_invenFrame.pos.x = 512;
		_invenFrame.pos.y = WINSIZEY - 100;
		_invenFrame.rc = RectMakeCenter(_invenFrame.pos.x, _invenFrame.pos.y, 1024, 199);

		_curCharIdx = 0;		//	Ŀ�� �������� �ؿ��̾�

		//�ؿ��� hp������ ����!
		for (int i = 0; i < 3; i++) 
		{
			POINT tmpPos;
			tmpPos.x = 154 + i*230;	//	��� ����, i x �ʻ�ȭ��
			tmpPos.y = WINSIZEY - 70 + 16;		//	�ǹغ��� ��� �ϺΖM(������ġ) + ����Ϻ�
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


	}	//	invenUI ���� �⺻���� ��


	//	�κ����� �ʱ�ȭ ����
	{
		POINT tmpPos;
		for (int i = 0; i < 3; i++)
		{
			tmpPos.x = 255 + 25 + (i * 230); // ������ġ + i*�ʻ�ȭ����
			tmpPos.y = WINSIZEY - _invenFrame.img->getFrameHeight() + 58 + 20;	// �ǹؿ��� -> ��常ŭ ���οö󰬴ٰ�-> ���β���ŭ �������� -> ������â���ι� ������
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
					tmpPos.x += 50;	//	������â �Ѱ� ����
				}

				tmpPos.y += 50;		//	������â �Ѱ� ����
				tmpPos.x = 255 + 25 + (i * 230); // ������ġ + i*�ʻ�ȭ����
			}
		}

	}	//	�κ����� �ʱ�ȭ ��


	//	ĳ���� ���� �ʱ�ȭ ����
	{
		POINT tmpPos;
		
		for (int i = 0; i < 3; i++)
		{
			tmpPos.x = 146 + 106 / 2 + (i * 230);							// �����ʰ���146 ĳ����â����106 + (����)
			tmpPos.y = WINSIZEY - 64 - (82 / 2);				//	���� ����64 ĳ����â ���� 82

			_charInfo[i].faceImgInfo.img = IMAGEMANAGER->findImage("charfaces");
			_charInfo[i].faceImgInfo.pos.x = tmpPos.x;
			_charInfo[i].faceImgInfo.pos.y = tmpPos.y;
			_charInfo[i].faceImgInfo.rc = RectMakeCenter(tmpPos.x, tmpPos.y, 99, 73);		//	�ʻ�ȭ ���μ���


			_charInfo[i].curInvenX = 0;
			_charInfo[i].curInvenY = 0;
			_charInfo[i].faceFrameX = 1;
			_charInfo[i].faceFrameY = i;		//	ĳ���ͺ� �̹����������̴ϱ�

			_charInfo[i].hp = 3;				//	ĳ������ hp ����	----------------
			
			//	hp�̹��� �޺� �ʱ�ȭ
			
			_charInfo[i].isDead = false;

		}
		_charInfo[0].faceFrameX = 0;
	}	//	ĳ���� ���� �ʱ�ȭ ��


	//	Ŀ������ �ʱ�ȭ ����
	{
		_cursor.img = IMAGEMANAGER->findImage("invenCursor");
		_cursorAlpha = 0;
		_isCursorAlphaRise = false;
		MakeCursorPos(_curCharIdx);		//	_curCharIdx ���� �ʱ�ȭ �ص� : 0
	}	//	Ŀ������ �ʱ�ȭ ��





	////	�׽�Ʈ�� ������
	//{
	//	_inven[0][0][0].E_ITEM = E_BOMB;
	//	_inven[0][0][0].name = "bomb";
	//
	//	_inven[1][0][0].E_ITEM = E_KEY_RED;
	//	_inven[1][0][0].name = "key_red";
	//
	//}
	//
	////	�׽�Ʈ�� ����
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

	//	������ �������̾ƴҶ�,
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

	//	������ �������̶��,
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

			//	ã�����߰ų�, �������� �������� �ƴ϶�� ��� ã�ƶ�
			while (_receiveIdx < 3)
			{
				if (_charInfo[_receiveIdx].isDead)		// �׾����� ��ŵ. ���� üũ ���� ����
				{
					_receiveIdx++;
					RefreshRecieveIdx();
				}
				if (_receiveIdx == 3)	break;		//	�������϶� ��

				if (_receiveIdx > 3) _receiveIdx = 0;
				//	�޴� �ε������� ��ó�� ��ĭ�� ã�´�.  recievePos �������ش�.
				isFound = FindEmptyInven();

				if (isFound)	break;
				_receiveIdx++;
				RefreshRecieveIdx();


				

				
			}
		}

		// ������
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

			//	ã�����߰ų�, �������� �������� �ƴ϶�� ��� ã�ƶ�
			while (-1 < _receiveIdx && _receiveIdx < 3)
			{
				if (_charInfo[_receiveIdx].isDead)		// �׾����� ��ŵ. üũ ���� ����
				{
					_receiveIdx--;
					RefreshRecieveIdx();
				} 
				if (_receiveIdx == 3)	break;

				if (_receiveIdx < 0) _receiveIdx = 3;
				//	�޴� �ε������� ��ó�� ��ĭ�� ã�´�.  recievePos �������ش�.
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
	_invenFrame.img->render(getMemDC(), _invenFrame.rc.left, _invenFrame.rc.top);	//	������ ���� ��Ƶ־���(���)
	
	//	hp �˱׶�� �׷����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < _charInfo[i].hp; j++)
		{
			_hp[i * 3 + j].img->render(getMemDC(), _hp[i * 3 + j].rc.left, _hp[i * 3 + j].rc.top);
		}
	}


	//	�κ� �� �����۾����� ���
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



	//	������ �ű������ �ƴϸ�,
	if (!_isSelectItem)
	{
		//_cursor.img->alphaRender(getMemDC(), _cursor.rc.left, _cursor.rc.top, _cursorAlpha);	//	��� ������ ��ƾ���
		for (int i = 0; i < 3; i++)
		{
			_cursor.img->render(getMemDC(),
				_inven[i][_charInfo[i].curInvenY][_charInfo[i].curInvenX].imgInfo.pos.x - _cursor.img->getFrameWidth() / 2,
				_inven[i][_charInfo[i].curInvenY][_charInfo[i].curInvenX].imgInfo.pos.y - _cursor.img->getFrameHeight() / 2);
			
		}
		
	}
		

	//	������ �ű�����̸�,
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

	//	�ؿ��� �׽�Ʈ�� =============


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

	}	//	����� ��



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
	_cursor.pos.x = _inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].imgInfo.pos.x;		//	�κ�[���缱����ĳ����][���缱����ĳ������ �κ�y][���缱����ĳ������ �κ�x] �� ��ǥ
	_cursor.pos.y = _inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].imgInfo.pos.y;		//	�κ�[���缱����ĳ����][���缱����ĳ������ �κ�y][���缱����ĳ������ �κ�x] �� ��ǥ
	_cursor.rc = RectMakeCenter(_cursor.pos.x, _cursor.pos.y, 52, 52);
}

void invenUI::CursorBlinkFunc()
{
	//	���� ����
	if (_cursorAlpha >= 255)		_isCursorAlphaRise = false;
	else if (_cursorAlpha <= 0)		_isCursorAlphaRise = true;

	//	���İ� ����
	if (_isCursorAlphaRise)			_cursorAlpha += CURSOR_BLINKSPD;
	else if (!_isCursorAlphaRise)	_cursorAlpha -= CURSOR_BLINKSPD;

	//	Ȥ�� ��ĥ��� �־��.
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
		_charInfo[i].faceFrameX = 1;		//��������. ����Ʈ�� 1

		if (i == _curCharIdx)
			_charInfo[i].faceFrameX = 0;	//��������. ���õȳ� 0
		if (_charInfo[i].isDead)
			_charInfo[i].faceFrameX = 2;	//��������. �������� 2	//	���DeadFunc()�����س��������� Ȥ�ø��� ����;

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
		//	���� ���µ�~ ���� ���µ�~ ����
		break;

	case E_BOMB:
		//	��ź �Լ� ����
		//	��������� ����
		_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		break;

	case E_KEY_YELLOW:
		
		//	�� ��������
		if(YellowKeyFunc())
			_inven[charIdx][_charInfo[charIdx].curInvenY][_charInfo[charIdx].curInvenX].E_ITEM = E_EMPTY;
		break;

	case E_KEY_RED:
		//	�� ��������
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
	//	�� ����ϸ� true ����.
	RECT tmpRc;
	RECT TMP_YELLOW_KEYLOCK;
	TMP_YELLOW_KEYLOCK = _objMgr->getObject5()->getvObjects()[1]._rc;

	if (IntersectRect(&tmpRc, &(_pm->getVCharInfo()[_curCharIdx]->getPlayerRc()), &TMP_YELLOW_KEYLOCK))
	{
		//	������Ʈ���� ����ߴٴ� ��ȣ�ְ�
		_objMgr->getObject2()->setStart(true, 1);
		_objMgr->getObject5()->setStart(true, 1);

		return true;
		
	}

	return false;
	
}

bool invenUI::RedKeyFunc()
{
	//	�� ����ϸ� true ����.
	RECT tmpRc;
	RECT TMP_RED_KEYLOCK;
	TMP_RED_KEYLOCK = _objMgr->getObject5()->getvObjects()[0]._rc;

	if (IntersectRect(&tmpRc, &(_pm->getVCharInfo()[_curCharIdx]->getPlayerRc()), &TMP_RED_KEYLOCK))
	{
		//	������Ʈ���� ����ߴٴ� ��ȣ�ְ�

		_objMgr->getObject2()->setStart(true, 0);
		_objMgr->getObject5()->setStart(true, 0);
		return true;

	}
	return false;
}

