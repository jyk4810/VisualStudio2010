
// Bitblt.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CBitbltApp:
// �� Ŭ������ ������ ���ؼ��� Bitblt.cpp�� �����Ͻʽÿ�.
//

class CBitbltApp : public CWinApp
{
public:
	CBitbltApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CBitbltApp theApp;