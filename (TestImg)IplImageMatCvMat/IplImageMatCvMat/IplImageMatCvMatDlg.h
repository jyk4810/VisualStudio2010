
// IplImageMatCvMatDlg.h : ��� ����
//

#pragma once

#include "opencv2/opencv.hpp"
using namespace cv;

// CIplImageMatCvMatDlg ��ȭ ����
class CIplImageMatCvMatDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CIplImageMatCvMatDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IPLIMAGEMATCVMAT_DIALOG };

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
	void MakeIplImage(void);

private:
	IplImage* m_pimg;
	CvMat*	  m_pcvMatImage;
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtontomat();
	afx_msg void OnBnClickedButtontocvmat();
	afx_msg void OnBnClickedButtoncvmattoiplimage();
	afx_msg void OnBnClickedButtoncvmattomat();
};
