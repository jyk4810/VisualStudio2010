
// GDIPlus.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CGDIPlusApp:
// �� Ŭ������ ������ ���ؼ��� GDIPlus.cpp�� �����Ͻʽÿ�.
//

class CGDIPlusApp : public CWinApp
{
public:
	CGDIPlusApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CGDIPlusApp theApp;