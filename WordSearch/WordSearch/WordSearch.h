
// WordSearch.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWordSearchApp:
// �� Ŭ������ ������ ���ؼ��� WordSearch.cpp�� �����Ͻʽÿ�.
//

class CWordSearchApp : public CWinApp
{
public:
	CWordSearchApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWordSearchApp theApp;