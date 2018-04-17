#pragma once


// CChildDlg 대화 상자입니다.

class CChildDlg : public CDialog
{
	DECLARE_DYNAMIC(CChildDlg)

public:
	CChildDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChildDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CHILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
