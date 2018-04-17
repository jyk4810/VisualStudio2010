
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGDIPlusDlg 대화 상자




CGDIPlusDlg::CGDIPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIPlusDlg::IDD, pParent)
	, m_hBitmapDC(NULL)
	, m_hMatDC(NULL)


{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pBitmap	= NULL;
	m_pGraphics = NULL;	
	m_pMatGraphics = NULL;
	m_Width			= 0;
	m_Height		= 0;
	m_nMatWidth		= 0;
	m_nMatHeight	= 0;
	m_nMatChanels	= 0;
}

void CGDIPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIPlusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_BOPEN, &CGDIPlusDlg::OnBnClickedButtonBOpen)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_toMat, &CGDIPlusDlg::OnBnClickedButtontomat)
	ON_BN_CLICKED(IDC_BUTTON_MOPEN, &CGDIPlusDlg::OnBnClickedButtonMopen)
	ON_BN_CLICKED(IDC_BUTTON_toBitmap, &CGDIPlusDlg::OnBnClickedButtontobitmap)
END_MESSAGE_MAP()


// CGDIPlusDlg 메시지 처리기

BOOL CGDIPlusDlg::OnInitDialog()
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
	static CClientDC dc(GetDlgItem(IDC_STATIC_BITMAP));
	m_hBitmapDC = dc.GetSafeHdc();
	static CClientDC Matdc(GetDlgItem(IDC_STATIC_MAT));
	m_hMatDC = Matdc.GetSafeHdc();
	GetDlgItem(IDC_STATIC_BITMAP)->GetClientRect(m_rcDisp);
	GetDlgItem(IDC_STATIC_MAT)->GetClientRect(m_MatRect);
	m_pGraphics = Graphics::FromHDC(m_hBitmapDC);
	m_pMatGraphics = Graphics::FromHDC(m_hMatDC);

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
	cvDestroyWindow("MatImage");
}


void CGDIPlusDlg::OnBnClickedButtonBOpen()
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
	m_pGraphics->DrawImage(m_pBitmap, 0, 0, m_rcDisp.right, m_rcDisp.bottom);
}


void CGDIPlusDlg::OnBnClickedButtontomat()
{
	ToMat();
}

void CGDIPlusDlg::ToMat()
{s
	int pixelformat;
	cv::Mat cv_image;

	// Gdi+ Bitmap을 이용하여 File load
	//Gdiplus::Bitmap gdi_bitmap(L"C:\\test.bmp", 0);
	//width			= gdi_bitmap.GetWidth();
	//height			= gdi_bitmap.GetHeight();
	pixelformat		= m_pBitmap->GetPixelFormat();


	// OpenCV cv::Mat 객체로 데이터 복사
	Gdiplus::BitmapData gdi_bitmapdata;
	Gdiplus::Rect rc(0, 0, m_Width, m_Height);
	m_pBitmap->LockBits(&rc, 0, pixelformat, &gdi_bitmapdata);

	switch(pixelformat)
	{
	case PixelFormat8bppIndexed:
		cv_image.create(m_Height, m_Width, CV_8UC1);
		memcpy(cv_image.data, gdi_bitmapdata.Scan0, m_Width*m_Height);
		break;
	case PixelFormat24bppRGB:
		cv_image.create(m_Height, m_Width, CV_8UC3);
		memcpy(cv_image.data, gdi_bitmapdata.Scan0, m_Width*m_Height*3);
		break;
	case PixelFormat32bppRGB:
		cv_image.create(m_Height, m_Width, CV_8UC4);
		memcpy(cv_image.data, gdi_bitmapdata.Scan0, m_Width*m_Height*4);
		break;
	}
	m_pBitmap->UnlockBits(&gdi_bitmapdata);	

	// OpenCV cv::imshow를 이용하여 Display
	cv::resize( cv_image, cv_image, cv::Size( m_rcDisp.right*2, m_rcDisp.bottom*2 ), 0, 0, CV_INTER_NN );
	cv::imshow("BitmapToMat", cv_image);
	

	cv::waitKey(0);

	cv_image.release();
}


void CGDIPlusDlg::OnBnClickedButtonMopen()
{
	CString cstrMatPath = _T("");
	CFileDialog OpenDlg(TRUE, _T("bmp"), NULL, OFN_ENABLESIZING,_T("All Support Files (*.bmp;*.jpg)|*.bmp;*.jpg|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|"));
	if (OpenDlg.DoModal() != IDOK) // CFileDialog 예외처리
		return;
	cstrMatPath = OpenDlg.GetPathName();
	std::string str;
	str = CT2CA(cstrMatPath.operator LPCWSTR());

	cv::Mat cv_image = cv::imread(str, CV_LOAD_IMAGE_ANYCOLOR);
	m_nMatWidth = cv_image.cols;
	m_nMatHeight = cv_image.rows;
	m_nMatChanels = cv_image.channels();
	m_cv_CopyImage = cv_image;
	cv::imshow("MatImage", cv_image);
	cv::waitKey(0);
}


void CGDIPlusDlg::OnBnClickedButtontobitmap()
{
	ToBitmap();
}

void CGDIPlusDlg::ToBitmap()
{
	//int width, height, channels;
	Gdiplus::BitmapData gdi_bitmapdata;
	Gdiplus::Bitmap		gdi_bitmap(m_nMatWidth, m_nMatHeight, PixelFormat24bppRGB);
	Gdiplus::Rect		rc(0, 0, m_nMatWidth, m_nMatHeight);

	gdi_bitmap.LockBits(&rc, 0, PixelFormat24bppRGB, &gdi_bitmapdata);
	switch(m_nMatChanels)
	{
	case 1:
		{
			cv::Mat cv_imgtmp(m_cv_CopyImage.rows, m_cv_CopyImage.cols, CV_8UC3);
			std::vector<cv::Mat> MergeImg;
			MergeImg.push_back(m_cv_CopyImage);
			MergeImg.push_back(m_cv_CopyImage);
			MergeImg.push_back(m_cv_CopyImage);
			cv::merge(MergeImg, cv_imgtmp);
			memcpy(gdi_bitmapdata.Scan0, cv_imgtmp.data, m_nMatWidth*m_nMatHeight*3);
		}
		break;
	case 3:
		{
			memcpy(gdi_bitmapdata.Scan0, m_cv_CopyImage.data, m_nMatWidth*m_nMatHeight*3);
		}
		break;
	default:
		break;
	}
	gdi_bitmap.UnlockBits(&gdi_bitmapdata);

	m_pMatGraphics->DrawImage(&gdi_bitmap, 0, 0, m_MatRect.right, m_MatRect.bottom);
}