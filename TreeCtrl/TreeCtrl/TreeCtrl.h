
// TreeCtrl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTreeCtrlApp:
// �� Ŭ������ ������ ���ؼ��� TreeCtrl.cpp�� �����Ͻʽÿ�.
//

class CTreeCtrlApp : public CWinApp
{
public:
	CTreeCtrlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTreeCtrlApp theApp;