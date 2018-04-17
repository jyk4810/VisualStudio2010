
// SpinControlDlg.h : ��� ����
//

#pragma once


// CSpinControlDlg ��ȭ ����
class CSpinControlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSpinControlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SPINCONTROL_DIALOG };

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
		int m_neditSpinVal;
public:
		afx_msg void OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult);
		virtual BOOL PreTranslateMessage(MSG* pMsg);
};
