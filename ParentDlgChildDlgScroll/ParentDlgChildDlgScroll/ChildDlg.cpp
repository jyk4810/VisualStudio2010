// ChildDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ParentDlgChildDlgScroll.h"
#include "ChildDlg.h"
#include "afxdialogex.h"


// CChildDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChildDlg, CDialog)

CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDlg::IDD, pParent)
{
	m_VScrollPos = 0;
	m_HScrollPos = 0;
	Create(CChildDlg::IDD,pParent);
	m_bitmapInfo.bmHeight = 300;
	m_bitmapInfo.bmWidth  = 300;
}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialog)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CChildDlg 메시지 처리기입니다.


void CChildDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nDelta;
	switch (nSBCode)
	{
	case SB_LINEUP:
		nDelta = 1;
		m_HScrollPos--;
		SetScrollPos(SB_HORZ,m_HScrollPos,TRUE);
		ScrollWindow(nDelta, 0);
		break;
	case SB_LINEDOWN:
		nDelta = -1;
		m_HScrollPos++;
		SetScrollPos(SB_HORZ,m_HScrollPos,TRUE);
		ScrollWindow(nDelta, 0);
		break;
	case SB_PAGEUP:
	case SB_PAGEDOWN:
	case SB_THUMBPOSITION:
	case SB_TOP:
	case SB_THUMBTRACK:
	case SB_BOTTOM:
		nDelta = m_HScrollPos- nPos;
		m_HScrollPos = nPos;
		SetScrollPos(SB_HORZ,m_HScrollPos,TRUE);
		ScrollWindow(nDelta, 0);
		break;
    default:
		return;
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CChildDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nDelta;
	switch (nSBCode)
	{
	case SB_LINEUP:
		nDelta = 1;
		m_VScrollPos--;
		SetScrollPos(SB_VERT,m_VScrollPos,TRUE);
		ScrollWindow(0, nDelta);
		break;
	case SB_LINEDOWN:
		nDelta = -1;
		m_VScrollPos++;
		SetScrollPos(SB_VERT,m_VScrollPos,TRUE);
		ScrollWindow(0, nDelta);
		break;
	case SB_PAGEUP:
	case SB_PAGEDOWN:
	case SB_THUMBPOSITION:
	case SB_TOP:
	case SB_THUMBTRACK:
	case SB_BOTTOM:
		nDelta = m_VScrollPos- nPos;
		m_VScrollPos = nPos;
		SetScrollPos(SB_VERT,m_VScrollPos,TRUE);
		ScrollWindow(0, nDelta);
		break;
    default:
		return;
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CChildDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_ALL;
	si.nMin = 0;
	si.nMax = m_bitmapInfo.bmHeight;
	si.nPage = cy;
	si.nPos = 0;

	SetScrollInfo(SB_VERT, &si);
	
	si.nMax = m_bitmapInfo.bmWidth;
	si.nPage = cx;
	SetScrollInfo(SB_HORZ, &si);
}


BOOL CChildDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_hdc = ::GetDC(this->m_hWnd);
	m_hMemDC=CreateCompatibleDC(m_hdc);
		

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CChildDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	BitBlt(m_hdc, -m_HScrollPos, -m_VScrollPos, m_bitmapInfo.bmWidth, m_bitmapInfo.bmHeight, m_hMemDC, 0, 0, SRCCOPY);
	// 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
}
