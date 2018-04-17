
// ScrollBarBaseDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ScrollBarBase.h"
#include "ScrollBarBaseDlg.h"
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CScrollBarBaseDlg 대화 상자




CScrollBarBaseDlg::CScrollBarBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScrollBarBaseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_VScrollPos = 0;
	m_HScrollPos = 0;
	
}

void CScrollBarBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CScrollBarBaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CScrollBarBaseDlg::OnBnClickedButton1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CScrollBarBaseDlg 메시지 처리기

BOOL CScrollBarBaseDlg::OnInitDialog()
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
	m_hdc = ::GetDC(this->m_hWnd);
	m_hMemDC=CreateCompatibleDC(m_hdc);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CScrollBarBaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScrollBarBaseDlg::OnPaint()
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
		BitBlt(m_hdc, -m_HScrollPos, -m_VScrollPos, m_bitmapInfo.bmWidth, m_bitmapInfo.bmHeight, m_hMemDC, 0, 0, SRCCOPY);
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CScrollBarBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CScrollBarBaseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	
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


void CScrollBarBaseDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CScrollBarBaseDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CScrollBarBaseDlg::OnBnClickedButton1()
{	
	CString strPathName = _T("");
	HBITMAP hBitmap;
	
	CFileDialog OpenDlg(TRUE, _T("bmp"), NULL, OFN_ENABLESIZING,_T("All Support Files (*.bmp;*.jpg)|*.bmp;*.jpg|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|"));
	if (OpenDlg.DoModal() != IDOK) // CFileDialog 예외처리
	{
		AfxMessageBox(_T(" 이미지 불러오기 에러"));
	}
	strPathName = OpenDlg.GetPathName();
	hBitmap = (HBITMAP)LoadImage( NULL, 
	strPathName,// 경로
	IMAGE_BITMAP,
	0, 0, //크기
	LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

	GetObject( hBitmap,sizeof( BITMAP ), &m_bitmapInfo );
	
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, hBitmap);
	BitBlt(m_hdc, 0, 0, 500, 500, m_hMemDC, 0, 0, SRCCOPY);
	ShowScrollBar(SB_BOTH, TRUE); // 처음 이미지 불러들일때 스크롤바를 가려서 이 함수로 보이게함
}


void CScrollBarBaseDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	SelectObject(m_hMemDC, m_hOldBitmap);
}
