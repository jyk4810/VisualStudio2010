
// ScrollBarBase.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CScrollBarBaseApp:
// �� Ŭ������ ������ ���ؼ��� ScrollBarBase.cpp�� �����Ͻʽÿ�.
//

class CScrollBarBaseApp : public CWinApp
{
public:
	CScrollBarBaseApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CScrollBarBaseApp theApp;