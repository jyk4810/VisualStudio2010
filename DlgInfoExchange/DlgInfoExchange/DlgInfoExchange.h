
// DlgInfoExchange.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDlgInfoExchangeApp:
// �� Ŭ������ ������ ���ؼ��� DlgInfoExchange.cpp�� �����Ͻʽÿ�.
//

class CDlgInfoExchangeApp : public CWinAppEx
{
public:
	CDlgInfoExchangeApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDlgInfoExchangeApp theApp;


// CDlgInfoExchange ��ȭ �����Դϴ�.

class CDlgInfoExchange : public CDialog
{
	DECLARE_DYNAMIC(CDlgInfoExchange)

public:
	CDlgInfoExchange(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgInfoExchange();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLGINFOEXCHANGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};