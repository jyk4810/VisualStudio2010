
// ListCtrlFont.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CListCtrlFontApp:
// �� Ŭ������ ������ ���ؼ��� ListCtrlFont.cpp�� �����Ͻʽÿ�.
//

class CListCtrlFontApp : public CWinApp
{
public:
	CListCtrlFontApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CListCtrlFontApp theApp;