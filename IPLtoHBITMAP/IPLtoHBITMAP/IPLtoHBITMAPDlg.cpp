
// IPLtoHBITMAPDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "IPLtoHBITMAP.h"
#include "IPLtoHBITMAPDlg.h"
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


// CIPLtoHBITMAPDlg 대화 상자




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


// CIPLtoHBITMAPDlg 메시지 처리기

BOOL CIPLtoHBITMAPDlg::OnInitDialog()
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
		
	m_pimage = makeIplImage();
	m_hDC = ::GetDC(this->m_hWnd);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CIPLtoHBITMAPDlg::OnPaint()
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
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	CreateBitmap의 Bit per pixel값에 따라 오버로딩 되어있다.
	8인 경우 infoheader와 colortable을 건너 뛴 부분부터 imagedata가 시작한다고 설정하고 사용해야한다.
	32인 경우 바로 4바이트에 BGRA 순으로 픽셀값을 넣어주면 된다.
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
