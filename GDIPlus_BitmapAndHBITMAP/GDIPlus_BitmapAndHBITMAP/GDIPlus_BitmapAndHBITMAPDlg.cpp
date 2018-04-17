
// GDIPlus_BitmapAndHBITMAPDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "GDIPlus_BitmapAndHBITMAP.h"
#include "GDIPlus_BitmapAndHBITMAPDlg.h"
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


// CGDIPlus_BitmapAndHBITMAPDlg ��ȭ ����




CGDIPlus_BitmapAndHBITMAPDlg::CGDIPlus_BitmapAndHBITMAPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIPlus_BitmapAndHBITMAPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pBitmap = NULL;
	m_pGraphics = NULL;	
}

void CGDIPlus_BitmapAndHBITMAPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIPlus_BitmapAndHBITMAPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_HBITMAP, &CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonHbitmap)
	ON_BN_CLICKED(IDC_BUTTON_TOBITMAP, &CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonTobitmap)
	ON_BN_CLICKED(IDC_BUTTON_TOHBITMAP, &CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonTohbitmap)
END_MESSAGE_MAP()


// CGDIPlus_BitmapAndHBITMAPDlg �޽��� ó����

BOOL CGDIPlus_BitmapAndHBITMAPDlg::OnInitDialog()
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
	m_hDC = ::GetDC(this->m_hWnd);
	m_pGraphics = Graphics::FromHDC(m_hDC);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CGDIPlus_BitmapAndHBITMAPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGDIPlus_BitmapAndHBITMAPDlg::OnPaint()
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
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CGDIPlus_BitmapAndHBITMAPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonHbitmap()
{
	CFileDialog OpenDlg(TRUE, _T("bmp"), NULL, OFN_ENABLESIZING,_T("All Support Files (*.bmp;*.jpg)|*.bmp;*.jpg|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|"));
	if (OpenDlg.DoModal() != IDOK) // CFileDialog ����ó��	
		return;
	
	CString strPathName = _T("");
	HBITMAP hBitmap = NULL;
	strPathName = OpenDlg.GetPathName();
	hBitmap = 
		(HBITMAP)LoadImage( NULL, 
		strPathName,// ���
		IMAGE_BITMAP, 
		300, 300, //ũ��
		LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
		

	m_pBitmap = Bitmap::FromHBITMAP(hBitmap, NULL); // hBitmap TO Bitmap
}


void CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonTobitmap()
{	
	if(m_pBitmap !=NULL)
	{
		m_pGraphics->DrawImage(m_pBitmap, 0, 0, 256, 256);
	}
	
}


void CGDIPlus_BitmapAndHBITMAPDlg::OnBnClickedButtonTohbitmap()
{
	if(m_pBitmap !=NULL)
	{
		HBITMAP hBitmap1 = NULL;
		m_pBitmap->GetHBITMAP(Color(0,0,0), &hBitmap1);
		
		m_hMemDC=CreateCompatibleDC(m_hDC);
		HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, hBitmap1);
		BitBlt(m_hDC, 300, 0, 256, 256, m_hMemDC, 0, 0, SRCCOPY);
		SelectObject(m_hMemDC, hOldBitmap);
	}	
}
