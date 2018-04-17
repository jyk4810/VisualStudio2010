
// GDIPlusDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "GDIPlus.h"
#include "GDIPlusDlg.h"
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


// CGDIPlusDlg ��ȭ ����


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


// CGDIPlusDlg �޽��� ó����

BOOL CGDIPlusDlg::()
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CGDIPlusDlg::OnPaint()
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
		CDialogEx::OnPaint();
		m_pGraphics->DrawImage(m_pBitmap, 0, 0, m_Width, m_Height);
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	if(m_pBitmap) //open�� �ι��̻� �������� ���� �Ҵ��Ͽ��� Bitmap�� delete�ϱ�����
	{
		::delete m_pBitmap;
		m_pBitmap = NULL;
	}

	CFileDialog OpenDlg(TRUE, _T("bmp"), NULL, OFN_ENABLESIZING,_T("All Support Files (*.bmp;*.jpg)|*.bmp;*.jpg|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|"));
	if (OpenDlg.DoModal() != IDOK) // CFileDialog ����ó��
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
	

	//m_scrHtinfo ����ü
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo ����ü
	m_scrVinfo.cbSize = sizeof(m_scrVinfo);
	m_scrVinfo.fMask = SIF_ALL;
	m_scrVinfo.nMin = 0;
	m_scrVinfo.nMax = m_Height;
	m_scrVinfo.nPage = m_rcDisp.bottom;
	m_scrVinfo.nPos = 0;
	m_scrVinfo.nTrackPos = 0;
	m_scrollV.SetScrollInfo(&m_scrVinfo);
}


void CGDIPlusDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) // nPos�� ���� ��ũ�� ��ġ
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

	//m_scrHtinfo ����ü
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo ����ü
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

	//m_scrHtinfo ����ü
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo ����ü
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

	//m_scrHtinfo ����ü
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo ����ü
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

	//m_scrHtinfo ����ü
	m_scrHinfo.cbSize = sizeof(m_scrHinfo);
	m_scrHinfo.fMask = SIF_ALL;
	m_scrHinfo.nMin = 0;
	m_scrHinfo.nMax = m_Width;
	m_scrHinfo.nPage = m_rcDisp.right;
	m_scrHinfo.nPos = 0;
	m_scrHinfo.nTrackPos = 0/*m_scrHinfo.nPos*/;
	m_scrollH.SetScrollInfo(&m_scrHinfo);

	//m_scrVtinfo ����ü
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CGDIPlusDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	RECT rc1;
	HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_VIEW); // IDC �� hWnd ��������
	::GetWindowRect(hwndBox, &rc1); // hWnd�� Rect ��������
	POINT rc1LT = {rc1.left, rc1.top}; // Rect to Point ����
	::ScreenToClient(m_hWnd, &rc1LT); // m_hWnd ���� IDC�� ��ġ��ǥ�� rc1LT�� ����

	Graphics GTemp(m_pBitmap);
	Pen P(Color(255,0,0),3);
	GTemp.DrawEllipse(&P,point.x-rc1LT.x-10,point.y-rc1LT.y-10,20,20); // DrawEllipse �Լ��� x,y �� ��� ���̿� ���̸� �����Ͽ� ���� �簢���� ���ϴ� ���� �׸���
	Invalidate();

	CDialogEx::OnRButtonUp(nFlags, point);
}
