
// GDIPlus_BitmapAndHBITMAPDlg.h : ��� ����
//

#pragma once

#include <gdiplus.h>
	#pragma comment(lib, "gdiplus")
	using namespace Gdiplus;

// CGDIPlus_BitmapAndHBITMAPDlg ��ȭ ����
class CGDIPlus_BitmapAndHBITMAPDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CGDIPlus_BitmapAndHBITMAPDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GDIPLUS_BITMAPANDHBITMAP_DIALOG };

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
	afx_msg void OnBnClickedButtonHbitmap();

	Bitmap*		m_pBitmap;
	HDC			m_hDC;
	HDC			m_hMemDC;
	Graphics*	m_pGraphics;
	afx_msg void OnBnClickedButtonTobitmap();
	afx_msg void OnBnClickedButtonTohbitmap();
};
