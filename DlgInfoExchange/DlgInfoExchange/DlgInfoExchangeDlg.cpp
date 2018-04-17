
// DlgInfoExchangeDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DlgInfoExchange.h"
#include "DlgInfoExchangeDlg.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDlgInfoExchangeDlg 대화 상자




CDlgInfoExchangeDlg::CDlgInfoExchangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInfoExchangeDlg::IDD, pParent)
	, m_Height(800)
	, m_Width(600)
	, m_OffsetX(0)
	, m_OffsetY(0)
	
	, m_TriggerDelay(1000.0f)
	, m_ExposureTime(0.0f)
	, m_AcquisitionFrameRate(100.0f)
	, m_TimerDuration(111.0f)
	
	, m_DeviceScanType(0)
	, m_PixelFormat(0)
	, m_TestPattern(0)
	, m_AcquisitionMode(0)
	
	, m_AcquisitionStart(1)
	, m_AcquisitionStop(0)
	, m_TriggerSoftware(0)
	, m_GevTimestampControlLatch(0)
	
	, m_DeviceID(2)
	, m_DeviceVendorName(0)
	, m_DeviceModelName(0)
	, m_DeviceManufacturerInfo(0)
	
	, m_LineInverter(3)
	, m_LineStatus(0)
	, m_UserOutputValue(0)
	, m_LUTEnable(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pChildDlg = NULL;
}

void CDlgInfoExchangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgInfoExchangeDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CHILDDIALOG, &CDlgInfoExchangeDlg::OnBnClickedButtonChilddialog)
	ON_MESSAGE(USER_MESSAGE_DELETE_DIALOG, OnUserMessageDeleteDialog)
END_MESSAGE_MAP()


// CDlgInfoExchangeDlg 메시지 처리기

BOOL CDlgInfoExchangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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


	CString strTemp = _T("");
	SetDlgItemText(IDC_STATIC_INTEGERNAME, _T("Width"));
	SetDlgItemText(IDC_STATIC_FLOATNAME, _T("TriggerDelay"));
	SetDlgItemText(IDC_STATIC_ENUMNAME, _T("DeviceScanType"));
	SetDlgItemText(IDC_STATIC_COMNAME, _T("AcquisitionStart"));
	SetDlgItemText(IDC_STATIC_STRNAME, _T("DeviceID"));
	SetDlgItemText(IDC_STATIC_BOOLNAME, _T("LineInverter"));

	strTemp.Format(_T("%d"), m_Width);
	SetDlgItemText(IDC_STATIC_INTEGERVALUE, strTemp);
	strTemp.Format(_T("%f"), m_TriggerDelay);
	SetDlgItemText(IDC_STATIC_FLOATVALUE, strTemp);
	strTemp.Format(_T("%d"), m_DeviceScanType);
	SetDlgItemText(IDC_STATIC_ENUMVALUE, strTemp);
	strTemp.Format(_T("%d"), m_AcquisitionStart);
	SetDlgItemText(IDC_STATIC_COMVALUE, strTemp);
	strTemp.Format(_T("%d"), m_DeviceID);
	SetDlgItemText(IDC_STATIC_STRVALUE, strTemp);
	strTemp.Format(_T("%d"), m_LineInverter);
	SetDlgItemText(IDC_STATIC_BOOLVALUE, strTemp);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDlgInfoExchangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDlgInfoExchangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

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
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDlgInfoExchangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDlgInfoExchangeDlg::OnBnClickedButtonChilddialog()
{
	if( m_pChildDlg == NULL )
	{
		m_pChildDlg = new CChildDlg(this);
		m_pChildDlg->Create(IDD_DIALOG_CHILDDIALOG);
		m_pChildDlg->ShowWindow(SW_SHOW);
	}
}

LRESULT CDlgInfoExchangeDlg::OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam)
{
	delete m_pChildDlg;
	m_pChildDlg = NULL;
	
	return (LRESULT)0;
}
BOOL CDlgInfoExchangeDlg::PreTranslateMessage(MSG* pMsg)
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
	return CDialog::PreTranslateMessage(pMsg);
}


CString CDlgInfoExchangeDlg::GetParam(int type, CString strName)
{
	CString strTemp = _T("");

	switch(type)
	{
	case 0:	//int
		strTemp = GetIntValue(strName);
		break;
	case 1: //float
		strTemp = GetFloValue(strName);
		break;
	case 2: 
		strTemp = GetEnumValue(strName);
		break;
	case 3: 
		strTemp = GetComValue(strName);
		break;
	case 4: 
		strTemp = GetStrValue(strName);
		break;
	case 5: 
		strTemp = GetBooValue(strName);
		break;
	default:
		break;
	}
	return strTemp;
}
void CDlgInfoExchangeDlg::SetParam(int type, CString strName, CString strVal)
{
	switch(type)
	{
	case 0:	//int
		SetIntValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_INTEGERNAME, strName);
		SetDlgItemText(IDC_STATIC_INTEGERVALUE, strVal);
		break;
	case 1:	//float
		SetFloValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_FLOATNAME, strName);
		SetDlgItemText(IDC_STATIC_FLOATVALUE, strVal);	
		break;
	case 2:	
		SetEnumValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_ENUMNAME, strName);
		SetDlgItemText(IDC_STATIC_ENUMVALUE, strVal);	
		break;
	case 3:	
		SetComValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_COMNAME, strName);
		SetDlgItemText(IDC_STATIC_COMVALUE, strVal);	
		break;
	case 4:	
		SetStrValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_STRNAME, strName);
		SetDlgItemText(IDC_STATIC_STRVALUE, strVal);	
		break;
	case 5:	
		SetBooValue(strName, strVal);
		SetDlgItemText(IDC_STATIC_BOOLNAME, strName);
		SetDlgItemText(IDC_STATIC_BOOLVALUE, strVal);	
		break;
	default:
		break;
	}
}

CString CDlgInfoExchangeDlg::GetIntValue(CString strName)
{
	CString strTemp = _T("");
	int iVal = 0;

	if(strName == "Height")
	{
		iVal = m_Height;
	}
	else if(strName == "Width")
	{
		iVal = m_Width;
	}
	else if(strName == "OffsetX")
	{
		iVal = m_OffsetX;
	}
	else if(strName == "OffsetY")
	{
		iVal = m_OffsetY;
	}
	strTemp.Format(_T("%d"), iVal);

	return strTemp;
}
void CDlgInfoExchangeDlg::SetIntValue(CString strName, CString strVal)
{
	if(strName == "Width")
	{
		m_Width = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "Height")
	{
		m_Height = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "OffsetX")
	{
		m_OffsetX = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "OffsetY")
	{
		m_OffsetY = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CDlgInfoExchangeDlg::GetFloValue(CString strName)
{
	CString strVal;
	float iVal = 0.0f;

	if(strName == "TriggerDelay")
	{
		iVal = m_TriggerDelay;
	}
	else if(strName == "ExposureTime")
	{
		iVal = m_ExposureTime;
	}
	else if(strName == "AcquisitionFrameRate")
	{
		iVal = m_AcquisitionFrameRate;
	}
	else if(strName == "TimerDuration")
	{
		iVal = m_TimerDuration;
	}
	strVal.Format(_T("%f"), iVal);
	return strVal;
}
void CDlgInfoExchangeDlg::SetFloValue(CString strName, CString strVal)
{
	if(strName == "TriggerDelay")
	{
		m_TriggerDelay = (float)_wtof(strVal.GetBuffer(0));
	}
	else if(strName == "ExposureTime")
	{
		m_ExposureTime = (float)_wtof(strVal.GetBuffer(0));
	}
	else if(strName == "AcquisitionFrameRate")
	{
		m_AcquisitionFrameRate = (float)_wtof(strVal.GetBuffer(0));
	}
	else if(strName == "TimerDuration")
	{
		m_TimerDuration = (float)_wtof(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CDlgInfoExchangeDlg::GetEnumValue(CString strName)
{
	CString strTemp = _T("");
	int iVal = 0;

	if(strName == "DeviceScanType")
	{
		iVal = m_DeviceScanType;
	}
	else if(strName == "PixelFormat")
	{
		iVal = m_PixelFormat;
	}
	else if(strName == "TestPattern")
	{
		iVal = m_TestPattern;
	}
	else if(strName == "AcquisitionMode")
	{
		iVal = m_AcquisitionMode;
	}
	strTemp.Format(_T("%d"), iVal);

	return strTemp;
}
void CDlgInfoExchangeDlg::SetEnumValue(CString strName, CString strVal)
{
	if(strName == "DeviceScanType")
	{
		m_DeviceScanType = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "PixelFormat")
	{
		m_PixelFormat = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "TestPattern")
	{
		m_TestPattern = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "AcquisitionMode")
	{
		m_AcquisitionMode = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CDlgInfoExchangeDlg::GetComValue(CString strName)
{
	CString strTemp = _T("");
	int iVal = 0;

	if(strName == "AcquisitionStart")
	{
		iVal = m_AcquisitionStart;
	}
	else if(strName == "AcquisitionStop")
	{
		iVal = m_AcquisitionStop;
	}
	else if(strName == "TriggerSoftware")
	{
		iVal = m_TriggerSoftware;
	}
	else if(strName == "GevTimestampControlLatch")
	{
		iVal = m_GevTimestampControlLatch;
	}
	strTemp.Format(_T("%d"), iVal);

	return strTemp;
}
void CDlgInfoExchangeDlg::SetComValue(CString strName, CString strVal)
{
	if(strName == "AcquisitionStart")
	{
		m_AcquisitionStart = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "AcquisitionStop")
	{
		m_AcquisitionStop = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "TriggerSoftware")
	{
		m_TriggerSoftware = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "GevTimestampControlLatch")
	{
		m_GevTimestampControlLatch = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CDlgInfoExchangeDlg::GetStrValue(CString strName)
{
	CString strTemp = _T("");
	int iVal = 0;

	if(strName == "DeviceID")
	{
		iVal = m_DeviceID;
	}
	else if(strName == "DeviceVendorName")
	{
		iVal = m_DeviceVendorName;
	}
	else if(strName == "DeviceModelName")
	{
		iVal = m_DeviceModelName;
	}
	else if(strName == "DeviceManufacturerInfo")
	{
		iVal = m_DeviceManufacturerInfo;
	}
	strTemp.Format(_T("%d"), iVal);

	return strTemp;
}
void CDlgInfoExchangeDlg::SetStrValue(CString strName, CString strVal)
{
	if(strName == "DeviceID")
	{
		m_DeviceID = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "DeviceVendorName")
	{
		m_DeviceVendorName = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "DeviceModelName")
	{
		m_DeviceModelName = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "DeviceManufacturerInfo")
	{
		m_DeviceManufacturerInfo = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CDlgInfoExchangeDlg::GetBooValue(CString strName)
{
	CString strTemp = _T("");
	int iVal = 0;

	if(strName == "LineInverter")
	{
		iVal = m_LineInverter;
	}
	else if(strName == "LineStatus")
	{
		iVal = m_LineStatus;
	}
	else if(strName == "UserOutputValue")
	{
		iVal = m_UserOutputValue;
	}
	else if(strName == "LUTEnable")
	{
		iVal = m_LUTEnable;
	}
	strTemp.Format(_T("%d"), iVal);

	return strTemp;
}
void CDlgInfoExchangeDlg::SetBooValue(CString strName, CString strVal)
{
	if(strName == "LineInverter")
	{
		m_LineInverter = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "LineStatus")
	{
		m_LineStatus = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "UserOutputValue")
	{
		m_UserOutputValue = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "LUTEnable")
	{
		m_LUTEnable = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}