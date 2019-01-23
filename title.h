#pragma once
#include "gameNode.h"
#include <vector>
class title : public gameNode
{
	

	image* _titleImg;		//	Ÿ��Ʋ
	image* _mainmenuImg;
	image* _redcrossImg;
	
	image* _vugKingImg;

	int _titleAlphaValue;
	int _mainmenuAlphaValue;

	bool _isFadeStart;
	bool _isTitleEnd;
	bool _isRedCrossStart;
	bool _isVugStart;
	
	
	
	
	bool _isSceneEnd;
	

	int _showFrameCount;
	int _titleEndCount;		//	Ÿ��Ʋ ������ ī��Ʈ ����
	int _redcrossCount;		//	x�� �׷������� ī��Ʈ ����
	
	int _waitingCount;		//	Ʈ���� ������ ��ñ�ٸ�
	
	

	const int ALPHA_VALUE_SPD = 25;			//	���̵� �ϴ� �ӵ�, Ŭ���� Ÿ��Ʋ->�޴�������� ������ȯ��
	const int TITLE_SHOW_FRAME = 60;		//	60~120  / ������ ����, ���̵��۾� ��ŸƮ
	const int REDCROSS_START_FRAME = 60;	//	60~120 / ���̵���, ����ũ�ν� ��������� ��ٸ��� ������
	const int VUG_START_FRAME = 120;		//	60~120	//	x�� ��, Vug�� �ٲ����� ��ٸ��� ������, (vug����Ǹ� x�� �����)
	const int WAITING_FRAME = 60;			//	60~120	/ vug���� �ϰ�, ���θ޴�UI�� ȣ��ɶ����� ��ٸ��� �ð�
	
	


public:
	title();
	~title();

	HRESULT init();
	void release();
	void update();
	void render();

	void TitleFade();
	void FadeFunc();




	bool getIsSceneEnd() { return _isSceneEnd; }


};

