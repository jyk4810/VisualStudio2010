
// ScrollBarDlg.h : ��� ����
//

#pragma once


#include "stdafx.h"
#include "opencv2\opencv.hpp"
#include "afxwin.h"

using namespace cv;

// CScrollBarDlg ��ȭ ����
class CScrollBarDlg : public CDialogEx
{
		// �����Դϴ�.
public:
		CScrollBarDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

		// ��ȭ ���� �������Դϴ�.
		enum { IDD = IDD_SCROLLBAR_DIALOG };

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
