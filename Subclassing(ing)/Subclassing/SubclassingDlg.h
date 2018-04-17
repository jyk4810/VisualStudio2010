
// SubclassingDlg.h : ��� ����
//

#pragma once
#include "myedit.h"

class CMyButton;



// CSubclassingDlg ��ȭ ����
class CSubclassingDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSubclassingDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SUBCLASSING_DIALOG };

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
	CMyButton* m_myButton;
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void PostNcDestroy();
public:
	CMyEdit m_myEdit;
};
