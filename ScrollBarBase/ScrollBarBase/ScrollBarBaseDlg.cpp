
// ScrollBarBaseDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ScrollBarBase.h"
#include "ScrollBarBaseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CScrollBarBaseDlg ��ȭ ����




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


// CScrollBarBaseDlg �޽��� ó����

BOOL CScrollBarBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_hdc = ::GetDC(this->m_hWnd);
	m_hMemDC=CreateCompatibleDC(m_hdc);


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CScrollBarBaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		BitBlt(m_hdc, -m_HScrollPos, -m_VScrollPos, m_bitmapInfo.bmWidth, m_bitmapInfo.bmHeight, m_hMemDC, 0, 0, SRCCOPY);
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	if (OpenDlg.DoModal() != IDOK) // CFileDialog ����ó��
	{
		AfxMessageBox(_T(" �̹��� �ҷ����� ����"));
	}
	strPathName = OpenDlg.GetPathName();
	hBitmap = (HBITMAP)LoadImage( NULL, 
	strPathName,// ���
	IMAGE_BITMAP,
	0, 0, //ũ��
	LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

	GetObject( hBitmap,sizeof( BITMAP ), &m_bitmapInfo );
	
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, hBitmap);
	BitBlt(m_hdc, 0, 0, 500, 500, m_hMemDC, 0, 0, SRCCOPY);
	ShowScrollBar(SB_BOTH, TRUE); // ó�� �̹��� �ҷ����϶� ��ũ�ѹٸ� ������ �� �Լ��� ���̰���
}


void CScrollBarBaseDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	SelectObject(m_hMemDC, m_hOldBitmap);
}
