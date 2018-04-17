
// ListCtrlFontDlg.cpp : ���� ����
//


#include "stdafx.h"
#include "ListCtrlFont.h"
#include "ListCtrlFontDlg.h"
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


// CListCtrlFontDlg ��ȭ ����




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


// CListCtrlFontDlg �޽��� ó����

BOOL CListCtrlFontDlg::OnInitDialog()
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
	SetWindowTheme(GetDlgItem(IDC_RADIO_ALL)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_INT)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_FLOAT)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_ENUM)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_COM)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_STR)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_RADIO_BOOL)->GetSafeHwnd(), _T(""), _T(""));


	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(0, _T("FeatureName"), LVCFMT_LEFT, 140, 1); // Column �ʱ�ȭ
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(1, _T("Value"), LVCFMT_LEFT, 140, 1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(2, _T("Type"), LVCFMT_LEFT, 140, 1);

	m_pImageList = new CImageList;								// ������ �ʱ�ȭ
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


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CListCtrlFontDlg::OnPaint()
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CListCtrlFontDlg::OnBnClickedRadioAll()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems(); // ����Ʈ �ʱ�ȭ (��ư�� �ι������� �߰� ADDSTRING����)

	((CListCtrl*)GetDlgItem(IDC_LIST))->SetFont(&m_Gabriola); // font ����

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
		
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}