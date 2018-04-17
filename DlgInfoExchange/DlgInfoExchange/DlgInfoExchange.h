
// DlgInfoExchange.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.


// CDlgInfoExchangeApp:
// 이 클래스의 구현에 대해서는 DlgInfoExchange.cpp을 참조하십시오.
//

class CDlgInfoExchangeApp : public CWinAppEx
{
public:
	CDlgInfoExchangeApp();

// 재정의입니다.
	public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CDlgInfoExchangeApp theApp;


// CDlgInfoExchange 대화 상자입니다.

class CDlgInfoExchange : public CDialog
{
	DECLARE_DYNAMIC(CDlgInfoExchange)

public:
	CDlgInfoExchange(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgInfoExchange();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLGINFOEXCHANGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};