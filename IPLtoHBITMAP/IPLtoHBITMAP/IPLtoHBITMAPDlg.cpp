
// IPLtoHBITMAPDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "IPLtoHBITMAP.h"
#include "IPLtoHBITMAPDlg.h"
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


// CIPLtoHBITMAPDlg ��ȭ ����




CIPLtoHBITMAPDlg::CIPLtoHBITMAPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIPLtoHBITMAPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pimg = NULL;
	m_pimage = NULL;
}

void CIPLtoHBITMAPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIPLtoHBITMAPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CIPLtoHBITMAPDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CIPLtoHBITMAPDlg �޽��� ó����

BOOL CIPLtoHBITMAPDlg::OnInitDialog()
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
		
	m_pimage = makeIplImage();
	m_hDC = ::GetDC(this->m_hWnd);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CIPLtoHBITMAPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIPLtoHBITMAPDlg::OnPaint()
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
HCURSOR CIPLtoHBITMAPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


IplImage* CIPLtoHBITMAPDlg::makeIplImage(void)
{
	IplImage* iplImage;
	iplImage = cvCreateImage(cvSize(256,256),IPL_DEPTH_8U,1);
	for ( int i = 0; i < iplImage->height ; i++ )
	{
		for ( int j = 0 ; j < iplImage->width ; j++ )
		{
			iplImage->imageData[j + i * iplImage->widthStep] =i ;
		}
	}

	return iplImage;
}


void CIPLtoHBITMAPDlg::OnBnClickedButton1()
{	
	/*	Readme.md
	CreateBitmap�� Bit per pixel���� ���� �����ε� �Ǿ��ִ�.
	8�� ��� infoheader�� colortable�� �ǳ� �� �κк��� imagedata�� �����Ѵٰ� �����ϰ� ����ؾ��Ѵ�.
	32�� ��� �ٷ� 4����Ʈ�� BGRA ������ �ȼ����� �־��ָ� �ȴ�.
	*/
	unsigned char bits[256*256*4] = {0,};
	int j = 0;
	for (int i = 0 ; i <256*256*4 ; i = i+4)
	{		
		bits[i] = (unsigned char)m_pimage->imageData[j];
		bits[i+1] = (unsigned char)m_pimage->imageData[j];
		bits[i+2] = (unsigned char)m_pimage->imageData[j];
		bits[i+3] = (unsigned char)m_pimage->imageData[j];
		j++;
	}
	HBITMAP hBitmap = CreateBitmap(256,256, 1, 32, bits);
	
	m_hMemDC=CreateCompatibleDC(m_hDC);
	HBITMAP m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, hBitmap);
	BitBlt(m_hDC, 0, 0, 256, 256, m_hMemDC, 0, 0, SRCCOPY);
	SelectObject(m_hMemDC, m_hOldBitmap);
}
