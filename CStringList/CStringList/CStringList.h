
// CStringList.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCStringListApp:
// �� Ŭ������ ������ ���ؼ��� CStringList.cpp�� �����Ͻʽÿ�.
//

class CCStringListApp : public CWinApp
{
public:
	CCStringListApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCStringListApp theApp;