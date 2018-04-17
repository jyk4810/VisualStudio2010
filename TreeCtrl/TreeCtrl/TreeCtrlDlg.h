
// TreeCtrlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CTreeCtrlDlg ��ȭ ����
class CTreeCtrlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TREECTRL_DIALOG };

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
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditName();
	afx_msg void OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);

public:
	CString m_strFocus;
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();

	HTREEITEM* phB2;
	
};
