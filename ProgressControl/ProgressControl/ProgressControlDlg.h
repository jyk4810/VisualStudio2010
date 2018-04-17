
// ProgressControlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"

#define USER_TIMER				0


// CProgressControlDlg ��ȭ ����
class CProgressControlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CProgressControlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROGRESSCONTROL_DIALOG };

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
public:
		CProgressCtrl m_progressCtrl;
		afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
		int m_timerCount;
		BOOL m_bKillTimer;
public:
		afx_msg void OnBnClickedButtonStop();
		afx_msg void OnDestroy();
};
