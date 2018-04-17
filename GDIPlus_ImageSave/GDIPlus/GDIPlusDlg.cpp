
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
	, m_hDC(NULL)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pBitmap	= NULL;
	m_pGraphics = NULL;	
	m_Width			= 0;
	m_Height		= 0;
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
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CGDIPlusDlg::OnBnClickedButtonOpen)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CGDIPlusDlg::OnBnClickedButtonSave)
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
	static CClientDC dc(GetDlgItem(IDC_STATIC_VIEW));
	m_hDC = dc.GetSafeHdc();
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(m_rcDisp);
	m_pGraphics = Graphics::FromHDC(m_hDC);


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
	m_pGraphics->DrawImage(m_pBitmap, 0, 0, m_rcDisp.right, m_rcDisp.bottom);
}


void CGDIPlusDlg::OnFileSaveDisplayImage()
{
	CFileDialog OpenDlg(FALSE, _T("bmp"), NULL, OFN_ENABLESIZING, _T("All Support Files (*.bmp;*.jpg;*.png;*.tif;*.gif)|*.bmp;*.jpg;*.png;*.tif;*.gif|BITMAP File(*.bmp)|*.bmp|JPEG File(*.jpg)|*.jpg|PNG File(*.png)|*.png|TIFF File(*.tif)|*.tif|GIF File(*.gif)|*.gif|"));
	if (OpenDlg.DoModal() != IDOK)
		return;

	Rect rc(0, 0, m_Width, m_Height);
	//EnterCriticalSection(&m_csImg);
	Bitmap* pClone = m_pBitmap->Clone(rc, PixelFormatDontCare);
	//LeaveCriticalSection(&m_csImg);

	CString strPathName = OpenDlg.GetPathName();
	CString strExtName = strPathName.Right(3);
	strExtName.MakeUpper();

	CLSID clsid;
	USES_CONVERSION;
	if(strExtName == "BMP")
	{
		GetEncoderClsid(L"image/bmp", &clsid);
		pClone->Save(T2CW(strPathName), &clsid, NULL);
	}
	else if(strExtName == "PNG")
	{
		GetEncoderClsid(L"image/png", &clsid);
		pClone->Save(T2CW(strPathName), &clsid, NULL);
	}
	else if(strExtName == "TIF")
	{
		GetEncoderClsid(L"image/tiff", &clsid);
		pClone->Save(T2CW(strPathName), &clsid, NULL);
	}
	else if(strExtName == "GIF")
	{
		GetEncoderClsid(L"image/gif", &clsid);
		pClone->Save(T2CW(strPathName), &clsid, NULL);
	}
	else if(strExtName == "JPG")
	{
		int Quality = 100;
		EncoderParameters encoderParameters;	
		encoderParameters.Count=1;
		encoderParameters.Parameter[0].Guid=EncoderQuality;
		encoderParameters.Parameter[0].Type=EncoderParameterValueTypeLong;
		encoderParameters.Parameter[0].NumberOfValues=1;
		encoderParameters.Parameter[0].Value=&Quality;

		GetEncoderClsid(L"image/jpeg", &clsid);
		pClone->Save(T2CW(strPathName), &clsid, &encoderParameters);
	}
	delete pClone;
}

int CGDIPlusDlg::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	using namespace Gdiplus;
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for(UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}    
	}

	free(pImageCodecInfo);
	return 0;
}

void CGDIPlusDlg::OnBnClickedButtonSave()
{
	OnFileSaveDisplayImage();
}
