#pragma once

#define PI 3.141592f
#define PI2 2 * PI

//프레임 이미지 회전을 위한 각도값
#define PI8		float(PI / 8.0f)
#define PI16	float(PI / 16.0f)
#define PI32	float(PI / 32.0f)
#define PI64	float(PI / 64.0f)
#define PI128	float(PI / 128.0f)

namespace BRAVO_UTIL
{
	float PixelColFunc(int dir, float x, float y, int searchRange, image* img, HDC dc, COLORREF rgb);

	float PixelColFunction(int dir, float x, float y, float probe, int searchRange, image* img, HDC dc, COLORREF rgb, bool* isCol);

	void RefreshAngle(float* angle);

	double getDistanceSqr(double x1, double y1, double x2, double y2);
	float getDistanceSqr(float x1, float y1, float x2, float y2);


	float getDistance(float x1, float y1, float x2, float y2);

	float getAngle(float x1, float y1, float x2, float y2);
}