#include "stdafx.h"
#include "keyAniManager.h"
#include "image.h"
#include "animation.h"


keyAniManager::keyAniManager()
{
}


keyAniManager::~keyAniManager()
{
}

HRESULT keyAniManager::init()
{
	return S_OK;
}

void keyAniManager::release()
{
	deleteAll();
}

void keyAniManager::update()
{
	iterAnimation iter = _mTotalAnimation.begin();
	
	for (iter; iter != _mTotalAnimation.end(); ++iter)
	{
		//	������ �����ŭ
		for (int vAniIdx = 0; vAniIdx < iter->second->size(); vAniIdx++) {

			vAnimation* vAni = iter->second;

			if(!((*vAni)[vAniIdx]->isPlay()))	continue;
			(*vAni)[vAniIdx]->frameUpdate(TIMEMANAGER->getElpasedTime() * 1.0f);

		}
		
	}
}

void keyAniManager::render()
{
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, const char * imageKeyName, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	iterAnimation mIter;
	
	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
	
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, const char * imageKeyName, int fps, bool reverse, bool loop, void * cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;
	
	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, CALLBACK_FUNCTION(cbFunction));
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, const char * imageKeyName, int fps, bool reverse, bool loop, void * cbFunction, void * obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;
	
	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, const char * imageKeyName, int * arr, int arrLen, int fps, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;
	
	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, const char * imageKeyName, int * arr, int arrLen, int fps, bool loop, void * cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;
	
	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, CALLBACK_FUNCTION(cbFunction));
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, const char * imageKeyName, int * arr, int arrLen, int fps, bool loop, void * cbFunction, void * obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, const char * imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;
	
	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);

}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, const char * imageKeyName, int start, int end, int fps, bool reverse, bool loop, void * cbFunction)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, const char * imageKeyName, int start, int end, int fps, bool reverse, bool loop, void * cbFunction, void * obj)
{
	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	iterAnimation mIter;

	MakeNewObjFunc(animationKeyName);			//	�ʿ� key�� ��������������(�ű��̸�) -> ���ͻ����� ���

	ani->init(img->GetWidth(), img->GetHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, CALLBACK_FUNCTION_PARAMETER(cbFunction), obj);
	ani->setFPS(fps);

	mIter = _mTotalAnimation.find(animationKeyName);
	mIter->second->push_back(ani);
}

void keyAniManager::start(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	
	if ((*vTmpAni).size() < 1)		return;	//���Ϳ� ������ �Ѱ��� ������ ������
	(*vTmpAni)[0]->start();

}

void keyAniManager::start(string animationKeyName, int idx)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������

	if ((*vTmpAni).size() <= idx)	return; //���Ϳ� �ִ°� �̻����� idx�� ������ ������
	(*vTmpAni)[idx]->start();
}

void keyAniManager::stop(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() < 1)		return;	//���Ϳ� ������ �Ѱ��� ������ ������
	(*vTmpAni)[0]->stop();
}

void keyAniManager::stop(string animationKeyName, int idx)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() <= idx)	return; //���Ϳ� �ִ°� �̻����� idx�� ������ ������
	(*vTmpAni)[idx]->stop();
}

void keyAniManager::pause(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);
	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() < 1)		return;	//���Ϳ� ������ �Ѱ��� ������ ������
	(*vTmpAni)[0]->pause();
	
}

void keyAniManager::pause(string animationKeyName, int idx)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);
	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() <= idx)	return; //���Ϳ� �ִ°� �̻����� idx�� ������ ������
	(*vTmpAni)[idx]->pause();
}

void keyAniManager::resume(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);
	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() < 1)		return;	//���Ϳ� ������ �Ѱ��� ������ ������
	(*vTmpAni)[0]->resume();
}

void keyAniManager::resume(string animationKeyName, int idx)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);
	if (iter == _mTotalAnimation.end())		return;

	vAnimation* vTmpAni = iter->second;		//�ʿ��� ã�� ����������
	if ((*vTmpAni).size() <= idx)	return; //���Ϳ� �ִ°� �̻����� idx�� ������ ������
	(*vTmpAni)[idx]->resume();
}

animation* keyAniManager::findAnimation(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter != _mTotalAnimation.end()) {
		vAnimation* vTmpAni = iter->second;
		return (*vTmpAni)[0];
	}
	return nullptr;
}

animation * keyAniManager::findAnimation(string animationKeyName, int idx)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);

	if (iter != _mTotalAnimation.end()) {
		vAnimation* vTmpAni = iter->second;
		return (*vTmpAni)[idx];
	}
	return nullptr;
}

void keyAniManager::deleteAll()
{
	for (iterAnimation iter = _mTotalAnimation.begin(); iter != _mTotalAnimation.end();)
	{
		if (iter->second != NULL)
		{
			// ������������==========����==============
			for (int i = 0; i < iter->second->size();) {
				vAnimation* vAni = iter->second;
				(*vAni)[i]->release();
				SAFE_DELETE((*vAni)[i]);
				vAni->erase(vAni->begin());
				
			}
			SAFE_DELETE(iter->second);
			iter = _mTotalAnimation.erase(iter);
		}
		else ++iter;
	}

	_mTotalAnimation.clear();
}

void keyAniManager::MakeNewObjFunc(string animationKeyName)
{
	iterAnimation iter = _mTotalAnimation.find(animationKeyName);
	if (iter == _mTotalAnimation.end()) {
		vAnimation* vAni = new vAnimation;
		_mTotalAnimation.insert(pair<string, vAnimation*>(animationKeyName, vAni));
	}

	
}

