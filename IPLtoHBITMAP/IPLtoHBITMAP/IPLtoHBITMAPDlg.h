
// IPLtoHBITMAPDlg.h : 헤더 파일
//

#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;

// CIPLtoHBITMAPDlg 대화 상자
class CIPLtoHBITMAPDlg : public CDialogEx
{
// 생성입니다.
public:
	CIPLtoHBITMAPDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IPLTOHBITMAP_DIALOG };

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
