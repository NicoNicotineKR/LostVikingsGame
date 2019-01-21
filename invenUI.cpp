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
	IMAGEMANAGER->addFrameImage("icon_items", "images/UI/invenUI/icon_items.bmp", 38, 38, 1, 1, false, 0x000000);



	//	�κ�UI�̹��� �߰� ����
	{
		IMAGEMANAGER->addFrameImage("invenCursor", "images/UI/invenUI/invenCursor.bmp", 52, 52, 1, 1, true, 0xFF00FF);
		IMAGEMANAGER->addFrameImage("invenFrame", "images/UI/invenUI/invenFrame.bmp", 1024, 199, 1, 1, false, 0x000000);
		IMAGEMANAGER->addFrameImage("charfaces", "images/UI/invenUI/charFaces.bmp", 297, 219, 3, 3, false, 0x000000);		//ĳ���� �ʻ�ȭ �̹��� 99*73

	}	//	�κ�UI�̹��� �߰� ��

	//	invenUI ���� �⺻���� ����
	{
		_invenFrame.img = IMAGEMANAGER->findImage("invenFrame");
		_invenFrame.pos.x = 512;
		_invenFrame.pos.y = WINSIZEY - 100;
		_invenFrame.rc = RectMakeCenter(_invenFrame.pos.x, _invenFrame.pos.y, 1024, 199);

		_curCharIdx = 0;

		_isInvenMode = false;
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

			_charInfo[i].hp = i + 1;				//	ĳ������ hp ����	----------------
			
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
	}
	

	//	Ŀ������ �ʱ�ȭ ��



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
	_invenFrame.img->render(getMemDC(), _invenFrame.rc.left, _invenFrame.rc.top);	//	������ ���� ��Ƶ־���(���)
	_cursor.img->alphaRender(getMemDC(), _cursor.rc.left, _cursor.rc.top, _cursorAlpha);	//	��� ������ ��ƾ���


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

