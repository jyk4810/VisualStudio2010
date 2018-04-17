
// ScrollBarDlg.h : 헤더 파일
//

#pragma once


#include "stdafx.h"
#include "opencv2\opencv.hpp"
#include "afxwin.h"

using namespace cv;

// CScrollBarDlg 대화 상자
class CScrollBarDlg : public CDialogEx
{
		// 생성입니다.
public:
		CScrollBarDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

		// 대화 상자 데이터입니다.
		enum { IDD = IDD_SCROLLBAR_DIALOG };

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
		void InsertImg(int nWidth, int nHeight);
		
		HBITMAP Mat2DIB( Mat *Image);

private:
		CString		 m_strPathName;
		HBITMAP     m_hBitmap, m_hOldBitmap;
		HDC				 m_hMemDC, m_hDC;
		BITMAP       m_Bitmap;
		int				 m_Width;
		int				 m_Height;
		int				 m_Position;
		RECT			 m_dlgRect;
		Mat				 m_Image;
		CRect m_rect;
		HANDLE m_hImage;
		BITMAP bmpInfo;
public:
		CScrollBar m_ctrHScroll;
		CScrollBar m_ctrVScroll;

		afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		virtual BOOL PreTranslateMessage(MSG* pMsg);
};
