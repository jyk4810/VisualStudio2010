
// TreeCtrlDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CTreeCtrlDlg 대화 상자
class CTreeCtrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TREECTRL_DIALOG };

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
