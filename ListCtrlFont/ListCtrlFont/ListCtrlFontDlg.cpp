
// ListCtrlFontDlg.cpp : 구현 파일
//


#include "stdafx.h"
#include "ListCtrlFont.h"
#include "ListCtrlFontDlg.h"
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


// CListCtrlFontDlg 대화 상자




CListCtrlFontDlg::CListCtrlFontDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListCtrlFontDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CListCtrlFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlFontDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_ALL, &CListCtrlFontDlg::OnBnClickedRadioAll)
	ON_BN_CLICKED(IDC_RADIO_INT, &CListCtrlFontDlg::OnBnClickedRadioInt)
	ON_BN_CLICKED(IDC_RADIO_FLOAT, &CListCtrlFontDlg::OnBnClickedRadioFloat)
	ON_BN_CLICKED(IDC_RADIO_ENUM, &CListCtrlFontDlg::OnBnClickedRadioEnum)
	ON_BN_CLICKED(IDC_RADIO_COM, &CListCtrlFontDlg::OnBnClickedRadioCom)
	ON_BN_CLICKED(IDC_RADIO_STR, &CListCtrlFontDlg::OnBnClickedRadioStr)
	ON_BN_CLICKED(IDC_RADIO_BOOL, &CListCtrlFontDlg::OnBnClickedRadioBool)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CListCtrlFontDlg 메시지 처리기

BOOL CListCtrlFontDlg::OnInitDialog()
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
	SetWindowTheme(GetDlgItem(IDC_RADIO_ALL)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_INT)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_FLOAT)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_ENUM)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_COM)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_STR)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_BOOL)->GetSafeHwnd(), _T(""), _T(""));


	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(0, _T("FeatureName"), LVCFMT_LEFT, 140, 1); // Column 초기화
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(1, _T("Value"), LVCFMT_LEFT, 140, 1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(2, _T("Type"), LVCFMT_LEFT, 140, 1);

	m_pImageList = new CImageList;								// 아이콘 초기화
	m_pImageList->Create(48,48,ILC_COLOR32,0,5);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP_INT);	
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	bmp.LoadBitmap(IDB_BITMAP_FLOAT);
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	bmp.LoadBitmap(IDB_BITMAP_ENUM);
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	bmp.LoadBitmap(IDB_BITMAP_COM);
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	bmp.LoadBitmap(IDB_BITMAP_STR);
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	bmp.LoadBitmap(IDB_BITMAP_BOOL);
	m_pImageList->Add(&bmp,RGB(122,122,122));
	bmp.DeleteObject();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetImageList(m_pImageList, LVSIL_SMALL);
	
	m_Gabriola.CreatePointFont(150,_T("Gabriola"));
	m_Impact.CreatePointFont(100,_T("Impact"));
	m_LucidaConsole.CreatePointFont(100,_T("Lucida Console"));
	m_FranklinGothicMedium.CreatePointFont(100,_T("Franklin Gothic Medium"));
	m_Nina.CreatePointFont(100,_T("Nina"));
	m_SegoeScript.CreatePointFont(100,_T("Segoe Script"));
	m_MVBoli.CreatePointFont(100,_T("MV Boli"));

	GetDlgItem(IDC_RADIO_ALL)->SetFont(&m_Gabriola);
	GetDlgItem(IDC_RADIO_INT)->SetFont(&m_Impact);
	GetDlgItem(IDC_RADIO_FLOAT)->SetFont(&m_LucidaConsole);
	GetDlgItem(IDC_RADIO_ENUM)->SetFont(&m_FranklinGothicMedium);
	GetDlgItem(IDC_RADIO_COM)->SetFont(&m_Nina);
	GetDlgItem(IDC_RADIO_STR)->SetFont(&m_SegoeScript);
	GetDlgItem(IDC_RADIO_BOOL)->SetFont(&m_MVBoli);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListCtrlFontDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListCtrlFontDlg::OnPaint()
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
HCURSOR CListCtrlFontDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListCtrlFontDlg::OnDestroy()
{
	if( !(m_pImageList == NULL) )
	{
		delete m_pImageList;
	}

	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CListCtrlFontDlg::OnBnClickedRadioAll()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems(); // 리스트 초기화 (버튼이 두번눌릴때 추가 ADDSTRING방지)

	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_Gabriola); // font 적용

	//INT
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("Width"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("Height"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("WidthMax"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );

	//FLOAT
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(3, _T("TriggerDelay"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(4, _T("ExposureTime"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(5, _T("AcquisitionFrameRate"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(3,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(4,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(5,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(3,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(4,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(5,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );

	//ENUM
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(6, _T("DeviceScanType"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(7, _T("PixelFormat"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(8, _T("TestPattern"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(6,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(7,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(8,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(6,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(7,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(8,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );

	//COM
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(9, _T("AcquisitionStart"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(10, _T("AcquisitionStop"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(11, _T("TriggerSoftware"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(9,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(10,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(11,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(9,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(10,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(11,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );

	//STR
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(12, _T("DeviceID"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(13, _T("DeviceVendorName"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(14, _T("DeviceModelName"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(12,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(13,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(14,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(12,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(13,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(14,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );

	//BOOL
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(15, _T("LineInverter"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(16, _T("LineStatus"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(17, _T("UserOutputValue"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(15,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(16,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(17,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(15,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(16,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(17,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioInt()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_Impact);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("Width"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("Height"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("WidthMax"),IMAGE_INT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioFloat()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_LucidaConsole);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("TriggerDelay"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("ExposureTime"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("AcquisitionFrameRate"),IMAGE_FLOAT);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioEnum()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_FranklinGothicMedium);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("DeviceScanType"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("PixelFormat"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("TestPattern"),IMAGE_ENUM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioCom()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_Nina);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("AcquisitionStart"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("AcquisitionStop"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("TriggerSoftware"),IMAGE_COM);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioStr()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_SegoeScript);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("DeviceID"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("DeviceVendorName"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("DeviceModelName"),IMAGE_STR);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );

}


void CListCtrlFontDlg::OnBnClickedRadioBool()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_MVBoli);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("LineInverter"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("LineStatus"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("UserOutputValue"),IMAGE_BOOL);
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );

}


HBRUSH CListCtrlFontDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if(  pWnd->GetDlgCtrlID() == IDC_RADIO_ALL )
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);		
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_INT )
	{
		pDC->SetTextColor(RGB(255,94,0));
		pDC->SetBkMode(TRANSPARENT);			
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_FLOAT )
	{
		pDC->SetTextColor(RGB(255,228,0));
		pDC->SetBkMode(TRANSPARENT);			
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_ENUM )
	{
		pDC->SetTextColor(RGB(47,157,39));
		pDC->SetBkMode(TRANSPARENT);			
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_COM )
	{
		pDC->SetTextColor(RGB(0,0,255));
		pDC->SetBkMode(TRANSPARENT);			
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_STR )
	{
		pDC->SetTextColor(RGB(3,0,102));
		pDC->SetBkMode(TRANSPARENT);			
	}
	else if ( pWnd->GetDlgCtrlID() == IDC_RADIO_BOOL )
	{
		pDC->SetTextColor(RGB(128,65,217));
		pDC->SetBkMode(TRANSPARENT);			
	}
		
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}