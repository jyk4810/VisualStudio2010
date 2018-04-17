
// IPLtoHBITMAPDlg.h : ��� ����
//

#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;

// CIPLtoHBITMAPDlg ��ȭ ����
class CIPLtoHBITMAPDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CIPLtoHBITMAPDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IPLTOHBITMAP_DIALOG };

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
	IplImage*	 m_pimg;
	HBITMAP		 m_hOldBitmap;
	HDC			 m_hMemDC;

	HDC			m_hDC;
public:
	IplImage* makeIplImage(void);
	afx_msg void OnBnClickedButton1();

	IplImage* m_pimage;
};
