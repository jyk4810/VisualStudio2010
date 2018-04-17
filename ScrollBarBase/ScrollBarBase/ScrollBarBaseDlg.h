
// ScrollBarBaseDlg.h : 헤더 파일
//

#pragma once


// CScrollBarBaseDlg 대화 상자
class CScrollBarBaseDlg : public CDialogEx
{
// 생성입니다.
public:
	CScrollBarBaseDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SCROLLBARBASE_DIALOG };

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
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	int		m_VScrollPos;
	int		m_HScrollPos;
	afx_msg void OnBnClickedButton1();

	HDC m_hdc;
	HDC m_hMemDC;
	HBITMAP m_hOldBitmap;
	BITMAP  m_bitmapInfo;
	afx_msg void OnDestroy();
};
