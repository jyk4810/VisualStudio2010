#pragma once


// CTabC ��ȭ �����Դϴ�.

class CTabC : public CDialogEx
{
	DECLARE_DYNAMIC(CTabC)

public:
	CTabC(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabC();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_C };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedButtonC();
};
