
// CFileFind.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCFileFindApp:
// �� Ŭ������ ������ ���ؼ��� CFileFind.cpp�� �����Ͻʽÿ�.
//

class CCFileFindApp : public CWinApp
{
public:
	CCFileFindApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCFileFindApp theApp;