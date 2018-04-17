
// DlgInfoExchangeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DlgInfoExchange.h"
#include "DlgInfoExchangeDlg.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDlgInfoExchangeDlg ��ȭ ����




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


// CDlgInfoExchangeDlg �޽��� ó����

BOOL CDlgInfoExchangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDlgInfoExchangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

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
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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