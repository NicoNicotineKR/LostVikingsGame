#include "stdafx.h"
#include "utils.h"


namespace BRAVO_UTIL
{
	//	�ȼ��浹��� - 
//	( ����, �˻�������ǥ, �˻��� �̹���, �˻�Ÿ�, �浹��(0x000000)�̷������� )
//	0 : ������ / 1 : ���� / 2 : ������ / 3 : ����
//	���� = �浹�� ��ǥ��. (���Ʒ��� y, �¿�� x����) , �浹���ϸ� ������, ������ 0����
	float PixelColFunc(int dir, float x, float y, int searchRange, image* img, COLORREF rgb) {

		float defaultY = y;
		float defaultX = x;
		int maxPos;

		switch (dir)
		{
			//�Ʒ��˻�
		case 0:
			maxPos = y + searchRange;
			for (; y < maxPos; y++) {
				COLORREF color = GetPixel(img->getMemDC(), x, y);
				if ((color == rgb)) {
					return y;
				}
			}
			return defaultY;
			break;
			//���˻�
		case 1:
			maxPos = y - searchRange;
			for (; y > maxPos; y--) {
				COLORREF color = GetPixel(img->getMemDC(), x, y);
				if (!(color == rgb)) {
					return y;
				}
			}
			return defaultY;
			break;
			//�����ʰ˻�
		case 2:
			maxPos = x + searchRange;
			for (; x < maxPos; x++) {
				COLORREF color = GetPixel(img->getMemDC(), x, y);
				if ((color == rgb)) {
					return x;
				}
			}
			return defaultX;
			break;
			//���ʰ˻�
		case 3:
			maxPos = x - searchRange;
			for (; x > maxPos; x--) {
				COLORREF color = GetPixel(img->getMemDC(), x, y);
				if (!(color == rgb)) {
					return x;
				}
			}
			return defaultX;
			break;

		default:
			break;
		}
		return 0;
	}
	//�ȼ��浹 ���� ��� (�˻��� ����, �÷��̾� x, �÷��̾� y, �÷��̾� ��ǥ���� ��� ���� ã��������, ã�� ����, �ȼ��� img, �ȼ��� img->dc, ã�� rgb, �浹Ȯ�ο� bool) 
	float PixelColFunction(int dir, float x, float y,float probe, int searchRange, image* img, HDC dc, COLORREF rgb,bool* isCol) {

		float pixelProbe;
		float defaultY = y;
		float defaultX = x;
		int maxPos;

		switch (dir)
		{
			//�Ʒ��˻�
		case 0:
			pixelProbe = y + probe;
			maxPos = pixelProbe + searchRange;
			for (pixelProbe -= searchRange; pixelProbe < maxPos; pixelProbe++) {
				COLORREF color = GetPixel(dc, x, pixelProbe);
				if ((color == rgb)) {
					*isCol = true;
					return pixelProbe -probe;
				}
			}
			*isCol = false;
			return defaultY;
			break;
			//���˻�
		case 1:
			pixelProbe = y - probe;
			maxPos = pixelProbe - searchRange;
			for (pixelProbe += searchRange; pixelProbe > maxPos; pixelProbe--) {
				COLORREF color = GetPixel(dc, x, pixelProbe);
				if ((color == rgb)) {
					*isCol = true;
					return pixelProbe + probe;
				}
			}
			*isCol = false;
			return defaultY;
			break;
			//�����ʰ˻�
		case 2:
			pixelProbe = x + probe;
			maxPos = pixelProbe + searchRange;
			for (pixelProbe -= searchRange; pixelProbe < maxPos; pixelProbe++) {
				COLORREF color = GetPixel(dc, pixelProbe,y );
				if ((color == rgb)) {
					*isCol = true;
					return pixelProbe - probe;
				}
			}
			*isCol = false;
			return defaultX;
			break;
			//���ʰ˻�
		case 3:
			pixelProbe = x - probe;
			maxPos = pixelProbe - searchRange;
			for (pixelProbe += searchRange; pixelProbe > maxPos; pixelProbe--) {
				COLORREF color = GetPixel(dc, pixelProbe, y);
				if ((color == rgb)) {
					*isCol = true;
					return  pixelProbe + probe;
				}
			}
			*isCol = false;
			return defaultX;
			break;

		default:
			break;
		}
		return 0;
	}


	//angle�� 0~2PI ���̷� �������(�ּ� ������ �����ٲ���)
	void RefreshAngle(float* angle)
	{
		while (1) {
			if (*angle > PI2)		*angle -= PI2;
			else if (*angle < 0)		*angle += PI2;
			else
			{
				break;
			}
		}
	}


	//�Ÿ��� ������ Ƣ���(double)
	double getDistanceSqr(double x1, double y1, double x2, double y2)
	{
		double wid = x2 - x1;
		double hei = y2 - y1;

		return ((wid * wid) + (hei * hei));
	}

	//�Ÿ��� ������ Ƣ���(float)
	float getDistanceSqr(float x1, float y1, float x2, float y2) 
	{
		float wid = x2 - x1;
		float hei = y2 - y1;

		return ((wid * wid) + (hei * hei));
	}


	//�Ÿ� ���ϴ� �Լ�
	float getDistance(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		return sqrtf(x * x + y * y);
	}


	// 1���� �����Ͽ� 2�� ���ϴ� ���� (��ǻ�;ޱ�)
	float getAngle(float x1, float y1, float x2, float y2)
	{

		float x = x2 - x1;
		float y = y2 - y1;

		//��ź��
		float angle = atan2f(y, x);

		if (angle < 0)		angle += PI2;
		if (angle > PI2)	angle -= PI2;


		return angle;
	}

}