
// GDIPlusDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "GDIPlus.h"
#include "GDIPlusDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

//CGDIPlusDlg::CGDIPlusDlg(CWnd* pParent /*=NULL*/)
//	: CDialogEx(CGDIPlusDlg::IDD, pParent)
//{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//	
//}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGDIPlusDlg 대화 상자


CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

CGDIPlusDlg::CGDIPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIPlusDlg::IDD, pParent)
	, m_hDC(NULL)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pBitmap	= NULL;
	m_pGraphics = NULL;	
	m_Width			= 0;
	m_Height		= 0;
	m_Width2		= 0;
	m_Height2		= 0;
	m_Width4		= 0;
	m_Height4		= 0;
	m_cstrMod		= _T("");
}

void CGDIPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR_H, m_scrollH);
	DDX_Control(pDX, IDC_SCROLLBAR_V, m_scrollV);
}

BEGIN_MESSAGE_MAP(CGDIPlusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CGDIPlusDlg::OnBnClickedButtonOpen)
	ON_WM_HSCROLL()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_RADIO_EXPAND2, &CGDIPlusDlg::OnBnClickedRadioExpand2)
	ON_BN_CLICKED(IDC_RADIO_NORMAL, &CGDIPlusDlg::OnBnClickedRadioNormal)
	ON_BN_CLICKED(IDC_RADIO_EXPAND4, &CGDIPlusDlg::OnBnClickedRadioExpand4)
	ON_BN_CLICKED(IDC_RADIO_FIT, &CGDIPlusDlg::OnBnClickedRadioFit)
	ON_CBN_SELCHANGE(IDC_COMBO_INTER, &CGDIPlusDlg::OnCbnSelchangeComboInter)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CGDIPlusDlg 메시지 처리기

BOOL CGDIPlusDlg::()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	static CClientDC dc(GetDlgItem(IDC_STATIC_VIEW));
	m_hDC = dc.GetSafeHdc();
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(m_rcDisp);
	m_pGraphics = Graphics::FromHDC(m_hDC);


	((CComboBox*)GetDlgItem(IDC_COMBO_INTER))->AddString(_T("Default"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTER))->AddString(_T("Bicubic"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTER))->AddString(_T("HighQualityBicubic"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTER))->AddString(_T("NearestNeighbor"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTER))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_INTER, m_cstrMod);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGDIPlusDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGDIPlusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		m_pGraphics->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGDIPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDIPlusDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(m_pBitmap)
	{
		::delete[] m_pBitmap;
		m_pBitmap = NULL;
	}
}


void CGDIPlusDlg::OnBnClickedButtonOpen()
{
	if(m_pBitmap) //open을 두번이상 눌렀을때 원래 할당하였던 Bitmap을 delete하기위해
	{
		::delete m_pBitmap;
		m_pBitmap = NULL;
	}

	CFileDialog OpenDlg(TRUE, _T("bmp"), NULL, OFN_ENABLESIZING,_T("All Support Files (*.bmp;*.jpg)|*.bmp;*.jpg|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|"));
	if (OpenDlg.DoModal() != IDOK) // CFileDialog 예외처리
		return;

	m_strPathName = OpenDlg.GetPathName();
	m_pBitmap = ::new Bitmap(m_strPathName,0);
	m_Width = m_pBitmap->GetWidth();
	m_Height = m_pBitmap->GetHeight();
	m_Width1 = m_Width;
	m_Height1= m_Height;
	m_Width2 = m_Width*2;
	m_Height2= m_Height*2;
	m_Width4 = m_Width*4;
	m_Height4= m_Height*4;

	m_pGraphics->SetInterpolationMode(InterpolationModeDefault);
	//m_CB(m_pBitmap,m_pGraphics);
	//m_pGraphics->DrawCachedBitmap(&m_CB,0,0);
	m_pGraphics->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);
	

	//m_scrHtinfo 구조체
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo 구조체
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);
}


void CGDIPlusDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) // nPos는 현재 스크롤 위치
{
	if(pScrollBar == (CScrollBar*)&m_scrollH) 
	{
		switch (nSBCode)
		{
		case SB_LINEUP:
			m_scrHinfo.nPos = m_scrHinfo.nPos >= -10 ? 0 : m_scrHinfo.nPos += 10;
			m_scrollH.SetScrollPos(-m_scrHinfo.nPos);
			break;
		case SB_LINEDOWN:
			m_scrHinfo.nPos = (m_Width - (int)m_scrHinfo.nPage) + (m_scrHinfo.nPos) <= 10 ? -(m_Width - (int)m_scrHinfo.nPage) : m_scrHinfo.nPos -= 10 ;
			m_scrollH.SetScrollPos(-m_scrHinfo.nPos);
			break;
		case SB_PAGEUP:
			break;
		case SB_PAGEDOWN:
			break;
		case SB_THUMBPOSITION:
			break;
		case SB_TOP:
		case SB_THUMBTRACK:
		case SB_BOTTOM:
			m_scrollH.SetScrollPos(nPos);
			m_scrHinfo.nPos = -(int)nPos;
			break;
		}

	}
	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CGDIPlusDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if(pScrollBar == (CScrollBar*)&m_scrollV) 
	{
		switch (nSBCode)
		{
		case SB_LINEUP:
			m_scrVinfo.nPos = m_scrVinfo.nPos >= -10 ? 0 : m_scrVinfo.nPos += 10;
			m_scrollV.SetScrollPos(-m_scrVinfo.nPos);
			break;
		case SB_LINEDOWN:
			m_scrVinfo.nPos = (m_Height - (int)m_scrVinfo.nPage) + (m_scrVinfo.nPos) <= 10 ? -(m_Height - (int)m_scrVinfo.nPage) : m_scrVinfo.nPos -= 10 ;
			m_scrollV.SetScrollPos(-m_scrVinfo.nPos);
			break;
		case SB_PAGEUP:
			break;
		case SB_PAGEDOWN:
			break;
		case SB_THUMBPOSITION:
			break;
		case SB_TOP:
		case SB_THUMBTRACK:
		case SB_BOTTOM:
			m_scrollV.SetScrollPos(nPos);
			m_scrVinfo.nPos = -(int)nPos;
			break;
		}

	}
	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CGDIPlusDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN) 			
	{			
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:			
		case VK_ESCAPE:			
			return TRUE;			
		default:			
			break;			
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CGDIPlusDlg::OnBnClickedRadioFit()
{
	m_Width = m_rcDisp.right;
	m_Height = m_rcDisp.bottom;

	//m_scrHtinfo 구조체
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo 구조체
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);

	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);
}

void CGDIPlusDlg::OnBnClickedRadioNormal()
{
	m_Width = m_Width1;
	m_Height = m_Height1;

	//m_scrHtinfo 구조체
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo 구조체
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);

	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);
}

void CGDIPlusDlg::OnBnClickedRadioExpand2()
{
	m_Width = m_Width2;
	m_Height = m_Height2;

	//m_scrHtinfo 구조체
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo 구조체
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);


	//m_pGraphics->SetInterpolationMode(InterpolationModeInvalid);
	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);

}

void CGDIPlusDlg::OnBnClickedRadioExpand4()
{
	m_Width = m_Width4;
	m_Height = m_Height4;

	//m_scrHtinfo 구조체
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo 구조체
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);

	m_pGraphics->DrawImage(m_pBitmap, m_scrHinfo.nPos, m_scrVinfo.nPos, m_Width, m_Height);
}




void CGDIPlusDlg::OnCbnSelchangeComboInter()
{
	GetDlgItemText(IDC_COMBO_INTER, m_cstrMod);

	if(m_cstrMod == _T("Default"))
		m_pGraphics->SetInterpolationMode(InterpolationModeDefault);
	else if(m_cstrMod == _T("Bicubic"))
		m_pGraphics->SetInterpolationMode(InterpolationModeBicubic);
	else if(m_cstrMod == _T("HighQualityBicubic"))
		m_pGraphics->SetInterpolationMode(InterpolationModeHighQualityBicubic);
	else if(m_cstrMod == _T("NearestNeighbor"))
		m_pGraphics->SetInterpolationMode(InterpolationModeNearestNeighbor);

	Invalidate();
	
}


void CGDIPlusDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CGDIPlusDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	RECT rc1;
	HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_VIEW); // IDC 의 hWnd 가져오기
	::GetWindowRect(hwndBox, &rc1); // hWnd의 Rect 가져오기
	POINT rc1LT = {rc1.left, rc1.top}; // Rect to Point 복사
	::ScreenToClient(m_hWnd, &rc1LT); // m_hWnd 에서 IDC의 위치좌표를 rc1LT에 저장

	Graphics GTemp(m_pBitmap);
	Pen P(Color(255,0,0),3);
	GTemp.DrawEllipse(&P,point.x-rc1LT.x-10,point.y-rc1LT.y-10,20,20); // DrawEllipse 함수는 x,y 를 잡고 넓이와 높이를 설정하여 얻은 사각형에 접하는 원을 그린다
	Invalidate();

	CDialogEx::OnRButtonUp(nFlags, point);
}
