
// MatToIplImageDlg.h : ��� ����
//

#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;

// CMatToIplImageDlg ��ȭ ����
class CMatToIplImageDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMatToIplImageDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MATTOIPLIMAGE_DIALOG };

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
	afx_msg void OnBnClickedButtonOpen();

	Mat					m_cv_CopyImage;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonMattoipl();
};
