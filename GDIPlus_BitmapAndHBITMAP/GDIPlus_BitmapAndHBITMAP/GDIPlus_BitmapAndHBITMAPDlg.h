
// GDIPlus_BitmapAndHBITMAPDlg.h : 헤더 파일
//

#pragma once

#include <gdiplus.h>
	#pragma comment(lib, "gdiplus")
	using namespace Gdiplus;

// CGDIPlus_BitmapAndHBITMAPDlg 대화 상자
class CGDIPlus_BitmapAndHBITMAPDlg : public CDialogEx
{
// 생성입니다.
public:
	CGDIPlus_BitmapAndHBITMAPDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GDIPLUS_BITMAPANDHBITMAP_DIALOG };

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
	afx_msg void OnBnClickedButtonHbitmap();

	Bitmap*		m_pBitmap;
	HDC			m_hDC;
	HDC			m_hMemDC;
	Graphics*	m_pGraphics;
	afx_msg void OnBnClickedButtonTobitmap();
	afx_msg void OnBnClickedButtonTohbitmap();
};
