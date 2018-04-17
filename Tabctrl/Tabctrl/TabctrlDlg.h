
// TabctrlDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"

class CTabA;
class CTabB;
class CTabC;

#define TAB_CURSEL_A		0
#define TAB_CURSEL_B		1
#define TAB_CURSEL_C		2

// CTabctrlDlg 대화 상자
class CTabctrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CTabctrlDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TABCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CTabA* m_tabA;
	CTabB* m_tabB;
	CTabC* m_tabC;

public:
	CTabCtrl m_tabCtrl;
	afx_msg void OnTcnSelchangeTabTest(NMHDR *pNMHDR, LRESULT *pResult);
};
