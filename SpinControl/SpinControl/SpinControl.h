
// SpinControl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSpinControlApp:
// �� Ŭ������ ������ ���ؼ��� SpinControl.cpp�� �����Ͻʽÿ�.
//

class CSpinControlApp : public CWinApp
{
public:
	CSpinControlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSpinControlApp theApp;