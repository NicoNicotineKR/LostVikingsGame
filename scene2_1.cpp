#include "stdafx.h"
#include "scene2_1.h"


scene2_1::scene2_1()
{
}


scene2_1::~scene2_1()
{
}

HRESULT scene2_1::init()
{
	IMAGEMANAGER->addImage("��������", "images/maps/stage1.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImg = IMAGEMANAGER->findImage("��������");

	//===========�ȼ��浹�����============
	IMAGEMANAGER->addImage("��2_1�ȼ�", "images/maps/stage1pixel.bmp", 3904, 1456, true, RGB(255, 0, 255));
	_mapImgPixel = IMAGEMANAGER->findImage("��2_1�ȼ�");
	//===========�ȼ��浹�����============

	_pm = new playerMgr;
	_pm->init();
	
	playerSelect = 0;

	//	�縸 �߰�
	{
		_invenUI = new invenUI;
		_invenUI->init();
		_isInvenMode = false;	
		

		_itemMgr = new itemMgr;
		_itemMgr->init();
		_itemMgr->getAddressLinkToCamera(_camera);
		_itemMgr->getAddressLinkToInvenUI(_invenUI);
		_itemMgr->getAddressLinkToPlayerMgr(_pm);

	}
	
	//_ladderRc = RectMake(900, 120, 100, 315);

	//20190122�����߰�
	_objectMgr = new objectMgr;
	_objectMgr->init();

	//�������� - ������
	_endrc = RectMake(5, 750, 140, 70);
	_endPlayer = RectMake(5, 750, 150, 200);
	_endImg = IMAGEMANAGER->addImage("���̹���", "images/maps/endimg.bmp", 140, 70, false, RGB(255, 0, 255));

	//	���� ��ũ �߰�
	{
		_invenUI->AddressLinkToObjectMgr(_objectMgr);
		_invenUI->AddressLinkToPlayerManager(_pm);
	}

	return S_OK;
}

void scene2_1::release()
{

}

void scene2_1::update()
{
	// �縸 �߰�: invenMode on/Off : '~'
	if (KEYMANAGER->isOnceKeyDown(VK_OEM_3))
	{
		if (_isInvenMode)
		{
			_isInvenMode = false;
			_invenUI->setIsSelectItem(false);
		}
		else if (!_isInvenMode)	_isInvenMode = true;
	}
	for (int i = 0; i < _pm->getVCharInfo().size(); ++i)
	{
		if (!_pm->getVCharInfo()[i]->getPlayerIsAlive())
		{
			_invenUI->MakeDead(i);
		}
		_invenUI->setCharHp(i, _pm->getVCharInfo()[i]->getPlayerHp());
	}
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(false);
		//���Ϲ� ����
		playerSelect++;

		//if(playerSelect == P_BALEOG)
		//�߷� ������ �Ʒ� ���������� ����Ұ�
		if (playerSelect == OUT_OF_RANGE)
		{
			playerSelect = P_ERIC;
		}
		
		_pm->getVCharInfo()[playerSelect]->setIsPlaying(true);

		for (int i = 0; i < _pm->getVCharInfo().size();++i)
		{

			if (!_pm->getVCharInfo()[i]->getIsPlaying() || !_pm->getVCharInfo()[i]->getPlayerIsAlive()) continue;

			if (_pm->getVCharInfo()[i]->getPlayerIsAlive())
			{
				int num = RND->getInt(2);

				switch (i)
				{
				case P_ERIC:

					switch (num)
					{
					case 0:
						SOUNDMANAGER->play("����1", 1.0f);
						break;
					case 1:
						SOUNDMANAGER->play("����2", 1.0f);
						break;
					case 2:
						SOUNDMANAGER->play("����3", 1.0f);
						break;
					case 3:
						SOUNDMANAGER->play("����4", 1.0f);
						break;
					case 4:
						SOUNDMANAGER->play("����5", 1.0f);
						break;
					}
				break;
				case P_BALEOG:

					switch (num)
					{
					case 0:
						SOUNDMANAGER->play("���α�1", 1.0f);
						break;
					case 1:
						SOUNDMANAGER->play("���α�2", 1.0f);
						break;
					case 2:
						SOUNDMANAGER->play("���α�3", 1.0f);
						break;
					case 3:
						SOUNDMANAGER->play("���α�4", 1.0f);
						break;
					case 4:
						SOUNDMANAGER->play("���α�5", 1.0f);
						break;
					}
				break;
				case P_OLAF:

					switch (num)
					{
					case 0:
						SOUNDMANAGER->play("�ö���1", 1.0f);
						break;
					case 1:
						SOUNDMANAGER->play("�ö���2", 1.0f);
						break;
					case 2:
						SOUNDMANAGER->play("�ö���3", 1.0f);
						break;
					case 3:
						SOUNDMANAGER->play("�ö���4", 1.0f);
						break;
					case 4:
						SOUNDMANAGER->play("�ö���5", 1.0f);
						break;
					}
				break;
				}
			}
		}

	

		//	�縸�߰� : inven���� ���� charIdx�˷��� , �׿� ���� �� ���
		_invenUI->setSelectCharIdx(playerSelect);
		_invenUI->FaceSelectFunc();


		//�������� ���� + �����߰� 181533 �赵��
////////////////////////////////////////////////////////////////////////////////////		else if (playerSelect == P_BALEOG)
////////////////////////////////////////////////////////////////////////////////////		{
////////////////////////////////////////////////////////////////////////////////////			//_camera->ChangeCharFunc(true, true, _baleog->getPos().x, _baleog->getPos().y, 0);
////////////////////////////////////////////////////////////////////////////////////		}
	}
	//2019.01.17 ����11���߰� ===================
	//_eric->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
	//2019.01.17 ����11���߰� ===================
	//_eric->update();
	

	//	�縸�߰� : �κ���尡 �ƴϸ�, ī�޶����/ ����
	if (!_isInvenMode)
	{
		//	�縸�߰� : c������ ���� ���õ� ĳ���� Ŀ���� �κ������� ���
		if (KEYMANAGER->isOnceKeyDown('C'))
		{
			_invenUI->UsingItem(playerSelect);
		}



		_itemMgr->update();			//	�����۸Ŵ��� ���� �߰�

		if (playerSelect == P_ERIC)
		{
			//2019.01.17 ����11���߰� ===================
			//_camera->UpdatePlayerPos(_eric->getPos().x, _eric->getPos().y, 5, _mapImg);
			//_camera->update();
			//2019.01.17 ����11���߰� ===================
			_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_ERIC]->getPos().x, _pm->getVCharInfo()[P_ERIC]->getPos().y, 20, _mapImg);
		}
		else if (playerSelect == P_BALEOG)
		{
			_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_BALEOG]->getPos().x, _pm->getVCharInfo()[P_BALEOG]->getPos().y, 20, _mapImg);
		}
		else if (playerSelect == P_OLAF)
		{
			_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_OLAF]->getPos().x, _pm->getVCharInfo()[P_OLAF]->getPos().y, 20, _mapImg);
		}
		/////////////////////////////////////////////////////////////////////////////////	else if (playerSelect == P_BALEOG)
		/////////////////////////////////////////////////////////////////////////////////	{
		/////////////////////////////////////////////////////////////////////////////////		_camera->UpdatePlayerPos(_pm->getVCharInfo()[P_BALEOG]->getPos().x, _pm->getVCharInfo()[P_BALEOG]->getPos().y, 5, _mapImg);
		/////////////////////////////////////////////////////////////////////////////////	}

		_camera->update();
	}
	else if (_isInvenMode)
	{
		_invenUI->update();
	}

	

	for (int i = 0; i < _pm->getVCharInfo().size(); i++)
	{
		_pm->getVCharInfo()[i]->UpdateCameraPos(_camera->Getmapx(), _camera->Getmapy());
	}
	_pm->update();

	//20190122�����߰�
	_objectMgr->update();

	//20190122�����߰�
	{
		vector<objects*>					_vObjects = _objectMgr->getVObjects();
		vector<objects*>::iterator			_viObjects = _objectMgr->getVIObjects();

		for (_viObjects = _vObjects.begin(); _viObjects != _vObjects.end(); _viObjects++)
		{
			(*_viObjects)->setCameraX(_camera->Getmapx());
			(*_viObjects)->setCameraY(_camera->Getmapy());
		}
	}

	//20190122�����߰�
	//�������� ����
	WorkObject1();
	//�����¹��� ���� 
	WorkObject2();
	//�������� �����ٸ��� ��ư
	WorkObject3();
	//��ٸ�
	WorkObject4();

	//�������� - ������
	ending();
}

void scene2_1::render()
{
	_mapImg->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	//_mapImgPixel->render(getMemDC(), 0, 0, _camera->Getmapx() - WINSIZEX / 2, _camera->Getmapy() - WINSIZEY / 2, WINSIZEX, WINSIZEY);

	//Rectangle(getMemDC(), _ladderRc.left - _camera->Getmapx() + WINSIZEX / 2
	//	, _ladderRc.top - _camera->Getmapy() + WINSIZEY / 2
	//	, _ladderRc.right - _camera->Getmapx() + WINSIZEX / 2
	//	, _ladderRc.bottom - _camera->Getmapy() + WINSIZEY / 2);

	_pm->render();
	_itemMgr->render();

	//20190122�����߰�
	_objectMgr->render();
	_endImg->render(getMemDC(), _endrc.left - _camera->Getmapx() + WINSIZEX / 2, _endrc.top - _camera->Getmapy() + WINSIZEY / 2);
	//�������� - ������
	Rectangle(getMemDC(),
		_endPlayer.left - _camera->Getmapx() + WINSIZEX / 2,
		_endPlayer.top - _camera->Getmapy() + WINSIZEY / 2,
		_endPlayer.right - _camera->Getmapx() + WINSIZEX / 2,
		_endPlayer.bottom - _camera->Getmapy() + WINSIZEY / 2
	);


	_invenUI->render();

	

	
	
}

void scene2_1::WorkObject1()
{
	//����ü�� ��� ���������̳�
	vector<tagObjects>				_vObject1 = _objectMgr->getObject1()->getvObjects();
	vector<tagObjects>::iterator	_viObject1 = _objectMgr->getObject1()->getviObjects();

	RECT temp;





	for (_viObject1 = _vObject1.begin(); _viObject1 != _vObject1.end(); _viObject1++)
	{
		if (IntersectRect(&temp, &_pm->getVCharInfo()[P_ERIC]->getPlayerRc(), &_viObject1->_rc) && _pm->getVCharInfo()[P_ERIC]->getIsRushing())
		{
			_pm->getVCharInfo()[P_ERIC]->setIsRushing(false);
			_pm->getVCharInfo()[P_ERIC]->ericRightStun();
			_objectMgr->getObject1()->setMainActivate(true);
		}

	}

	for (int i = 0; i < _pm->getVCharInfo().size(); i++)
	{
		for (int j = 0; j < _vObject1.size(); j++)
		{
			if (IntersectRect(&temp, &_pm->getVCharInfo()[i]->getPlayerRc(), &_vObject1[j]._rc))
			{
				if (_pm->getVCharInfo()[i]->getStatus() == P_R_MOVE || _pm->getVCharInfo()[i]->getStatus() == P_L_MOVE)
				{
					_pm->getVCharInfo()[i]->setStatus(P_R_WALL_PUSH);
					_pm->getVCharInfo()[i]->setIsWall(true);
				}
				_pm->getVCharInfo()[i]->setPostionX((float)_vObject1[j]._rc.left -64);
					// ��Ǫ�� ����
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))
	{
		//�̰Ǿ��������ƴѵ�? �����ε�?
		_objectMgr->getObject1()->setMainActivate(true);
	}

	//�÷��̾� �������� �����Ͻÿ�(�÷��̾� ��Ʈ�� ������)

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))
	{
		for (_viObject1 = _vObject1.begin(); _viObject1 != _vObject1.end(); _viObject1++)
		{
			_vObject1.erase(_viObject1);
			_objectMgr->getObject1()->setvObject(_vObject1);

			_viObject1->_rc;
			break;
		}
	}
}

void scene2_1::WorkObject2()
{
	//������Ʈ2
	vector<tagObjects>				_vObject2 = _objectMgr->getObject2()->getvObjects();
	vector<tagObjects>::iterator	_viObject2 = _objectMgr->getObject2()->getviObjects();

	//������Ʈ5
	vector<tagObjects>				_vObject5 = _objectMgr->getObject5()->getvObjects();
	vector<tagObjects>::iterator	_viObject5 = _objectMgr->getObject5()->getviObjects();

	RECT temp;
	RECT tempPlayer;

	//ù��°��
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4))
	{
		for (_viObject2 = _vObject2.begin(); _viObject2 != _vObject2.end(); _viObject2++)
		{
			for (_viObject5 = _vObject5.begin(); _viObject5 != _vObject5.end();)
			{
				//���� 1�������
				if (_viObject5->_property == 1)
				{
					//���� ���� 1�����༮��
					if (_viObject2->_property == 1)
					{
						//2����������
						_viObject2->_start = true;

						//5�����踦 �����.
						_vObject5.erase(_viObject5);
						//�����
						_objectMgr->getObject2()->setvObject(_vObject2);
						_objectMgr->getObject5()->setvObject(_vObject5);
						break;
					}
				}
				_viObject5++;
			}
		}
	}

	//�ι�°��
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5))
	{
		for (_viObject2 = _vObject2.begin(); _viObject2 != _vObject2.end(); _viObject2++)
		{
			for (_viObject5 = _vObject5.begin(); _viObject5 != _vObject5.end();)
			{
				//���� 1�������
				if (_viObject2->_property == 2)
				{
					//���� ���� 1�����༮��
					if (_viObject5->_property == 2)
					{
						//2����������
						_viObject2->_start = true;

						//5�����踦 �����.
						_vObject5.erase(_viObject5);
						//�����
						_objectMgr->getObject2()->setvObject(_vObject2);
						_objectMgr->getObject5()->setvObject(_vObject5);
						break;
					}
				}
				_viObject5++;

			}
		}
	}

}

void scene2_1::WorkObject3()
{
	//������Ʈ3
	vector<tagObjects>				_vObject3 = _objectMgr->getObject3()->getvObjects();
	vector<tagObjects>::iterator	_viObject3 = _objectMgr->getObject3()->getviObjects();

	//������Ʈ6
	vector<tagObjects>				_vObject6 = _objectMgr->getObject6()->getvObjects();
	vector<tagObjects>::iterator	_viObject6 = _objectMgr->getObject6()->getviObjects();

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD7))
	{
		for (_viObject3 = _vObject3.begin(); _viObject3 != _vObject3.end(); _viObject3++)
		{
			for (_viObject6 = _vObject6.begin(); _viObject6 != _vObject6.end();)
			{
				//���� 1�������
				if (_viObject3->_property == 1)
				{
					//���� ���� 1�����༮��
					if (_viObject6->_property == 1)
					{
						//2����������
						_viObject3->_start = true;

						//5�����踦 �����.
						_vObject6.erase(_viObject6);
						//�����
						_objectMgr->getObject3()->setvObject(_vObject3);
						_objectMgr->getObject6()->setvObject(_vObject6);
						break;
					}
				}
				_viObject6++;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8))
	{
		for (_viObject3 = _vObject3.begin(); _viObject3 != _vObject3.end(); _viObject3++)
		{
			for (_viObject6 = _vObject6.begin(); _viObject6 != _vObject6.end();)
			{
				//���� 1�������
				if (_viObject3->_property == 2)
				{
					//���� ���� 1�����༮��
					if (_viObject6->_property == 2)
					{
						//2����������
						_viObject3->_start = true;

						//5�����踦 �����.
						_vObject6.erase(_viObject6);
						//�����
						_objectMgr->getObject3()->setvObject(_vObject3);
						_objectMgr->getObject6()->setvObject(_vObject6);
						break;
					}
				}
				_viObject6++;
			}
		}
	}

}

void scene2_1::WorkObject4()
{
	//������Ʈ4
	vector<tagObjects>				_vObject4 = _objectMgr->getObject4()->getvObjects();

	_pm->setLadderRc(_vObject4[0]._rc);
	_pm->setLadderRc2(_vObject4[1]._rc);
}
//�������� - ������
void scene2_1::ending()
{
}
