
// ParentDlgChildDlgScroll.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CParentDlgChildDlgScrollApp:
// �� Ŭ������ ������ ���ؼ��� ParentDlgChildDlgScroll.cpp�� �����Ͻʽÿ�.
//

class CParentDlgChildDlgScrollApp : public CWinApp
{
public:
	CParentDlgChildDlgScrollApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CParentDlgChildDlgScrollApp theApp;