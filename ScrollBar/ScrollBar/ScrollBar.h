
// ScrollBar.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CScrollBarApp:
// �� Ŭ������ ������ ���ؼ��� ScrollBar.cpp�� �����Ͻʽÿ�.
//

class CScrollBarApp : public CWinApp
{
public:
	CScrollBarApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CScrollBarApp theApp;