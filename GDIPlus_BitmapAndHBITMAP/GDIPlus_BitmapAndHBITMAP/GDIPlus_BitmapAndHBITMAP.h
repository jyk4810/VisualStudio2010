
// GDIPlus_BitmapAndHBITMAP.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CGDIPlus_BitmapAndHBITMAPApp:
// �� Ŭ������ ������ ���ؼ��� GDIPlus_BitmapAndHBITMAP.cpp�� �����Ͻʽÿ�.
//

class CGDIPlus_BitmapAndHBITMAPApp : public CWinApp
{
public:
	CGDIPlus_BitmapAndHBITMAPApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CGDIPlus_BitmapAndHBITMAPApp theApp;