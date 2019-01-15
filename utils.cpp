#include "stdafx.h"
#include "utils.h"


namespace BRAVO_UTIL
{
	//	픽셀충돌계산 - 
	//	( 방향, 검색시작좌표, 검사할 이미지, 이미지 있는dc, 검사거리, 충돌하지 않는 색(0x000000)이런식으로 )
	//	0 : 밑으로 / 1 : 위로 / 2 : 오른쪽 / 3 : 왼쪽
	//	리턴 = 충돌한 좌표값. (위아래면 y, 좌우면 x리턴) , 충돌안하면 원래값, 에러시 0리턴
	float PixelColFunc(int dir, float x, float y, int searchRange, image* img, HDC dc, COLORREF rgb) {

		float defaultY = y;
		float defaultX = x;
		int maxPos;

		switch (dir)
		{
			//아래검색
		case 0:
			maxPos = y + searchRange;
			for (; y < maxPos; y++) {
				COLORREF color = GetPixel(dc, x, y);
				if (!(color == rgb)) {
					return y;
				}
			}
			return defaultY;
			break;
			//위검색
		case 1:
			maxPos = y - searchRange;
			for (; y > maxPos; y--) {
				COLORREF color = GetPixel(dc, x, y);
				if (!(color == rgb)) {
					return y;
				}
			}
			return defaultY;
			break;
			//오른쪽검색
		case 2:
			maxPos = x + searchRange;
			for (; x < maxPos; x++) {
				COLORREF color = GetPixel(dc, x, y);
				if (!(color == rgb)) {
					return x;
				}
			}
			return defaultX;
			break;
			//왼쪽검색
		case 3:
			maxPos = x - searchRange;
			for (; x > maxPos; x--) {
				COLORREF color = GetPixel(dc, x, y);
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



	//angle을 0~2PI 사이로 만들어줌(주소 넣으면 직접바꿔줌)
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


	//거리의 제곱이 튀어나옴(double)
	double getDistanceSqr(double x1, double y1, double x2, double y2)
	{
		double wid = x2 - x1;
		double hei = y2 - y1;

		return ((wid * wid) + (hei * hei));
	}

	//거리의 제곱이 튀어나옴(float)
	float getDistanceSqr(float x1, float y1, float x2, float y2) 
	{
		float wid = x2 - x1;
		float hei = y2 - y1;

		return ((wid * wid) + (hei * hei));
	}


	//거리 구하는 함수
	float getDistance(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		return sqrtf(x * x + y * y);
	}


	// 1에서 시작하여 2를 향하는 방향 (컴퓨터앵글)
	float getAngle(float x1, float y1, float x2, float y2)
	{

		float x = x2 - x1;
		float y = y2 - y1;

		//아탄투
		float angle = atan2f(y, x);

		if (angle < 0)		angle += PI2;
		if (angle > PI2)	angle -= PI2;


		return angle;
	}

}