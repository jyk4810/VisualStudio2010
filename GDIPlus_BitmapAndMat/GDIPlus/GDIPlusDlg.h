
// GDIPlusDlg.h : 헤더 파일
//

#pragma once

#include <gdiplus.h>
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;

#include "opencv2/opencv.hpp"
using namespace cv;

// CGDIPlusDlg 대화 상자
class CGDIPlusDlg : public CDialogEx
{
	// 생성입니다.
public:
	CGDIPlusDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_GDIPlus_DIALOG };

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
	afx_msg void OnDestroy();

	afx_msg void OnBnClickedButtonBOpen();

private:
	HDC					m_hBitmapDC;
	HDC					m_hMatDC;
	Graphics*			m_pGraphics;
	Graphics*			m_pMatGraphics;
	Bitmap*				m_pBitmap;
	int					m_Width;
	int					m_Height;
	CRect				m_rcDisp;
	CRect				m_MatRect;
	CString				m_strPathName ;

	int					m_nMatWidth;
	int					m_nMatHeight;
	int					m_nMatChanels;

	Mat					m_cv_CopyImage;

public:
	afx_msg void OnBnClickedButtontomat();
	afx_msg void OnBnClickedButtonMopen();
	afx_msg void OnBnClickedButtontobitmap();
	
	void				ToMat();
	void				ToBitmap();

};
