
// GDIPlusDlg.h : 헤더 파일
//

#pragma once

#include <gdiplus.h>
#include "afxwin.h"
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;

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

	afx_msg void OnBnClickedButtonOpen();

private:
	HDC					m_hDC;
	Graphics*			m_pGraphics;
	Bitmap*				m_pBitmap;
	int					m_Width;
	int					m_Height;
	int					m_Width1;
	int					m_Height1;
	int					m_Width2;
	int					m_Height2;
	int					m_Width4;
	int					m_Height4;
	
	CRect				m_rcDisp;
	CString				m_strPathName;
	SCROLLINFO			m_scrHinfo;
	SCROLLINFO			m_scrVinfo;
	CString				m_cstrMod;
	//CachedBitmap		m_CB;
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_scrollH;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_scrollV;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedRadioExpand2();
	afx_msg void OnBnClickedRadioNormal();
	afx_msg void OnBnClickedRadioExpand4();
	afx_msg void OnBnClickedRadioFit();
	afx_msg void OnCbnSelchangeComboInter();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};
