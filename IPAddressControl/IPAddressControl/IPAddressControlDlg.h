
// IPAddressControlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CIPAddressControlDlg ��ȭ ����
class CIPAddressControlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CIPAddressControlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IPADDRESSCONTROL_DIALOG };

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
		CIPAddressCtrl m_IPAddressCtrl;
		afx_msg void OnBnClickedButton();
};
