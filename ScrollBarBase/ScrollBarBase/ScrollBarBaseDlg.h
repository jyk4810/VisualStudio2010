
// ScrollBarBaseDlg.h : ��� ����
//

#pragma once


// CScrollBarBaseDlg ��ȭ ����
class CScrollBarBaseDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CScrollBarBaseDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SCROLLBARBASE_DIALOG };

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
