#pragma once


// CTabA ��ȭ �����Դϴ�.

class CTabA : public CDialogEx
{
	DECLARE_DYNAMIC(CTabA)

public:
	CTabA(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabA();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_A };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedButtonA();
};
