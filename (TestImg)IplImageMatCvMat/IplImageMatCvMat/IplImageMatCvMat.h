
// IplImageMatCvMat.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CIplImageMatCvMatApp:
// �� Ŭ������ ������ ���ؼ��� IplImageMatCvMat.cpp�� �����Ͻʽÿ�.
//

class CIplImageMatCvMatApp : public CWinApp
{
public:
	CIplImageMatCvMatApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CIplImageMatCvMatApp theApp;