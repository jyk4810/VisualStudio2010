#pragma once


// CTabB ��ȭ �����Դϴ�.

class CTabB : public CDialogEx
{
	DECLARE_DYNAMIC(CTabB)

public:
	CTabB(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabB();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_B };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedButtonB();
};
