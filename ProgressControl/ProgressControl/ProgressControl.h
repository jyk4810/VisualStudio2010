
// ProgressControl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CProgressControlApp:
// �� Ŭ������ ������ ���ؼ��� ProgressControl.cpp�� �����Ͻʽÿ�.
//

class CProgressControlApp : public CWinApp
{
public:
	CProgressControlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CProgressControlApp theApp;