#pragma once
#include "singletonBase.h"
#include <map>
#include <vector>

class image;
class animation;

class keyAniManager : public singletonBase<keyAniManager>
{
private:
	
	typedef vector<animation*>					vAnimation;
	typedef vector<animation*>::iterator		viAnimation;

	typedef map<string, vAnimation*>			arrAnimation;
	typedef map<string, vAnimation*>::iterator	iterAnimation;

private:

//	vAnimation*		_vAniamtion;
	arrAnimation	_mTotalAnimation;

	int _vAniIdx;

public:
	keyAniManager();
	~keyAniManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션
	void addDefaultFrameAnimation(string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);
	
	//배열 애니메이션
	void addArrayFrameAnimation(string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);
	
	//구간 애니메이션
	void addCoordinateFrameAnimation(string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction);
	void addCoordinateFrameAnimation(string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void start(string animationKeyName);
	void start(string animationKeyName, int idx);
	void stop(string animationKeyName);
	void stop(string animationKeyName, int idx);
	void pause(string animationKeyName);
	void pause(string animationKeyName, int idx);
	void resume(string animationKeyName);
	void resume(string animationKeyName, int idx);

	animation* findAnimation(string animationKeyName);
	animation* findAnimation(string animationKeyName, int idx);

	void deleteAll();

	//	해당 키값에 벡터 없으면(신규) 맵과 벡터 생성해서 넣음
	void MakeNewObjFunc(string animationKeyName);

};

