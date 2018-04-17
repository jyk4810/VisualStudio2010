#pragma once


// CChildDlg ��ȭ �����Դϴ�.

class CChildDlg : public CDialog
{
	DECLARE_DYNAMIC(CChildDlg)

public:
	CChildDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChildDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CHILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	int		m_VScrollPos;
	int		m_HScrollPos;
	HDC		m_hdc;
	HDC		m_hMemDC;
	HBITMAP m_hOldBitmap;
	BITMAP  m_bitmapInfo;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
