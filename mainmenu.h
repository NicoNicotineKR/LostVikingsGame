#pragma once
#include "gameNode.h"
#include "mainmenuUI.h"

struct tagImgCombo {
	image* img;
	RECT rc;
	POINT pos;
};

class mainmenu : public gameNode
{
private:

	//���θ޴� ���� ������
	image* _bg;
	bool _isSceneEnd;
	bool _isOptionMode;


	mainmenuUI* _menuUI;

	//========�ɼ��� ����� �ڰԵǳ�==============
	


	
	tagImgCombo _optionBG;
	tagImgCombo _soundTxt;
	tagImgCombo _soundBar[2][10];	//	[on/off][10��]
	bool		_isSoundBarOn[10];
	int			_curVol;			//	������Ʈ����idx

	

public:
	mainmenu();
	~mainmenu();

	HRESULT init();
	void release();
	void update();
	void render();


	void SelectSceneFunc();
	tagImgCombo ImgComboinit(string keyName, int x, int y);
	void OptionUIUpdate();
	void RefreshVol();



	bool getIsSceneEnd() { return _isSceneEnd; }
	bool setIsSceneEnd(bool value) { _isSceneEnd = value; }

	int getCurVol() { return _curVol; }	//	0~10;


};

