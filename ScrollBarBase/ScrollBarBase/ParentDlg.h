#pragma once


// CParentDlg ��ȭ �����Դϴ�.

class CParentDlg : public CDialog
{
	DECLARE_DYNAMIC(CParentDlg)

public:
	CParentDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CParentDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_PARENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
