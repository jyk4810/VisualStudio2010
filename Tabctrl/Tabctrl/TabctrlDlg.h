
// TabctrlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"

class CTabA;
class CTabB;
class CTabC;

#define TAB_CURSEL_A		0
#define TAB_CURSEL_B		1
#define TAB_CURSEL_C		2

// CTabctrlDlg ��ȭ ����
class CTabctrlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTabctrlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TABCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
