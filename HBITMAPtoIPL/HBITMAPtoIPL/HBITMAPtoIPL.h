
// HBITMAPtoIPL.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHBITMAPtoIPLApp:
// �� Ŭ������ ������ ���ؼ��� HBITMAPtoIPL.cpp�� �����Ͻʽÿ�.
//

class CHBITMAPtoIPLApp : public CWinApp
{
public:
	CHBITMAPtoIPLApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHBITMAPtoIPLApp theApp;