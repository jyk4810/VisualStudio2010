
// IplImageMatCvMatDlg.h : 헤더 파일
//

#pragma once

#include "opencv2/opencv.hpp"
using namespace cv;

// CIplImageMatCvMatDlg 대화 상자
class CIplImageMatCvMatDlg : public CDialogEx
{
// 생성입니다.
public:
	CIplImageMatCvMatDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IPLIMAGEMATCVMAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
