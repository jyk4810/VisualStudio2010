
// IPLtoHBITMAP.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CIPLtoHBITMAPApp:
// �� Ŭ������ ������ ���ؼ��� IPLtoHBITMAP.cpp�� �����Ͻʽÿ�.
//

class CIPLtoHBITMAPApp : public CWinApp
{
public:
	CIPLtoHBITMAPApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CIPLtoHBITMAPApp theApp;