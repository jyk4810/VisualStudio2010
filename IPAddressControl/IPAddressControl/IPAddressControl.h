
// IPAddressControl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CIPAddressControlApp:
// �� Ŭ������ ������ ���ؼ��� IPAddressControl.cpp�� �����Ͻʽÿ�.
//

class CIPAddressControlApp : public CWinApp
{
public:
	CIPAddressControlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CIPAddressControlApp theApp;