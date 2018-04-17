
// CFileFindDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CCFileFindDlg ��ȭ ����
class CCFileFindDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCFileFindDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CFILEFIND_DIALOG };

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
	CTreeCtrl m_Tree;
	void WindowExplorer1(HTREEITEM,CString);
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


