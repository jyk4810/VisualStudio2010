
// HBITMAPtoIPLDlg.h : ��� ����
//

#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;

// CHBITMAPtoIPLDlg ��ȭ ����
class CHBITMAPtoIPLDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHBITMAPtoIPLDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HBITMAPTOIPL_DIALOG };

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
	afx_msg void OnDestroy();
};
