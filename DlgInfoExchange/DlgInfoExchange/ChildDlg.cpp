// ChildDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DlgInfoExchange.h"
#include "DlgInfoExchangeDlg.h"
#include "ChildDlg.h"


// CChildDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChildDlg, CDialog)

CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDlg::IDD, pParent)
{	
	m_pParentDlg = (CDlgInfoExchangeDlg*)AfxGetMainWnd();
	m_strName		 = "";
	m_Struct.Name = "";
	m_Struct.Value = "";
}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO_INTEGERNAME, &CChildDlg::OnCbnSelchangeComboIntegername)
	ON_CBN_SELCHANGE(IDC_COMBO_FLOATNAME, &CChildDlg::OnCbnSelchangeComboFloatname)
	ON_CBN_SELCHANGE(IDC_COMBO_ENUMNAME, &CChildDlg::OnCbnSelchangeComboEnumname)
	ON_CBN_SELCHANGE(IDC_COMBO_COMNAME, &CChildDlg::OnCbnSelchangeComboComname)
	ON_CBN_SELCHANGE(IDC_COMBO_STRNAME, &CChildDlg::OnCbnSelchangeComboStrname)
	ON_CBN_SELCHANGE(IDC_COMBO_BLNNAME, &CChildDlg::OnCbnSelchangeComboBlnname)
	ON_EN_UPDATE(IDC_EDIT_INTEGERVALUE, &CChildDlg::OnEnUpdateEditIntegervalue)
	ON_EN_UPDATE(IDC_EDIT_FLOATVALUE, &CChildDlg::OnEnUpdateEditFloatvalue)
	ON_EN_UPDATE(IDC_EDIT_ENUMVALUE, &CChildDlg::OnEnUpdateEditEnumvalue)
	ON_EN_UPDATE(IDC_EDIT_COMVALUE, &CChildDlg::OnEnUpdateEditComvalue)
	ON_EN_UPDATE(IDC_EDIT_STRVALUE, &CChildDlg::OnEnUpdateEditStrvalue)
	ON_EN_UPDATE(IDC_EDIT_BLNVALUE, &CChildDlg::OnEnUpdateEditBlnvalue)
END_MESSAGE_MAP()


// CChildDlg 메시지 처리기입니다.

BOOL CChildDlg::PreTranslateMessage(MSG* pMsg)
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

void CChildDlg::OnClose()
{
	PostMessage(WM_DESTROY, 0, 0);
	CDialog::OnClose();
}

void CChildDlg::OnDestroy()
{
	CDialog::OnDestroy();
	m_pParentDlg->PostMessage(USER_MESSAGE_DELETE_DIALOG, NULL, NULL );
}

void CChildDlg::OnCbnSelchangeComboIntegername()
{
	GetDlgItemText(IDC_COMBO_INTEGERNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_INTEGER, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_INTEGERVALUE, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboFloatname()
{
	GetDlgItemText(IDC_COMBO_FLOATNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_FLOAT, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboEnumname()
{
	GetDlgItemText(IDC_COMBO_ENUMNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_ENUMERATION, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_ENUMVALUE, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboComname()
{
	GetDlgItemText(IDC_COMBO_COMNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_COMMAND, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_COMVALUE, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboStrname()
{
	GetDlgItemText(IDC_COMBO_STRNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_STRING, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_STRVALUE, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboBlnname()
{
	GetDlgItemText(IDC_COMBO_BLNNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_BOOLEAN, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_BLNVALUE, m_Struct.Value);
}


void CChildDlg::OnEnUpdateEditIntegervalue()
{
	GetDlgItemText(IDC_COMBO_INTEGERNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_INTEGERVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_INTEGER, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnEnUpdateEditFloatvalue()
{
	GetDlgItemText(IDC_COMBO_FLOATNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_FLOAT, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnEnUpdateEditEnumvalue()
{
	GetDlgItemText(IDC_COMBO_ENUMNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_ENUMVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_ENUMERATION, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnEnUpdateEditComvalue()
{
	GetDlgItemText(IDC_COMBO_COMNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_COMVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_COMMAND, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnEnUpdateEditStrvalue()
{
	GetDlgItemText(IDC_COMBO_STRNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_STRVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_STRING, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnEnUpdateEditBlnvalue()
{
	GetDlgItemText(IDC_COMBO_BLNNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_BLNVALUE, m_Struct.Value);
	m_pParentDlg->SetParam(VALUE_TYPE_BOOLEAN, m_Struct.Name, m_Struct.Value);
}

BOOL CChildDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//INTEGER
	((CComboBox*)GetDlgItem(IDC_COMBO_INTEGERNAME))->AddString(_T("Width"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTEGERNAME))->AddString(_T("Height"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTEGERNAME))->AddString(_T("OffsetX"));
	((CComboBox*)GetDlgItem(IDC_COMBO_INTEGERNAME))->AddString(_T("OffsetY"));
	//FLOAT
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("TriggerDelay"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("ExposureTime"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("AcquisitionFrameRate"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("TimerDuration"));
	//ENUMERATION
	((CComboBox*)GetDlgItem(IDC_COMBO_ENUMNAME))->AddString(_T("DeviceScanType"));
	((CComboBox*)GetDlgItem(IDC_COMBO_ENUMNAME))->AddString(_T("PixelFormat"));
	((CComboBox*)GetDlgItem(IDC_COMBO_ENUMNAME))->AddString(_T("TestPattern"));
	((CComboBox*)GetDlgItem(IDC_COMBO_ENUMNAME))->AddString(_T("AcquisitionMode"));
	//COMMAND
	((CComboBox*)GetDlgItem(IDC_COMBO_COMNAME))->AddString(_T("AcquisitionStart"));
	((CComboBox*)GetDlgItem(IDC_COMBO_COMNAME))->AddString(_T("AcquisitionStop"));
	((CComboBox*)GetDlgItem(IDC_COMBO_COMNAME))->AddString(_T("TriggerSoftware"));
	((CComboBox*)GetDlgItem(IDC_COMBO_COMNAME))->AddString(_T("GevTimestampControlLatch"));
	//STRING
	((CComboBox*)GetDlgItem(IDC_COMBO_STRNAME))->AddString(_T("DeviceID"));
	((CComboBox*)GetDlgItem(IDC_COMBO_STRNAME))->AddString(_T("DeviceVendorName"));
	((CComboBox*)GetDlgItem(IDC_COMBO_STRNAME))->AddString(_T("DeviceModelName"));
	((CComboBox*)GetDlgItem(IDC_COMBO_STRNAME))->AddString(_T("DeviceManufacturerInfo"));
	//BOOLEAN
	((CComboBox*)GetDlgItem(IDC_COMBO_BLNNAME))->AddString(_T("LineInverter"));
	((CComboBox*)GetDlgItem(IDC_COMBO_BLNNAME))->AddString(_T("LineStatus"));
	((CComboBox*)GetDlgItem(IDC_COMBO_BLNNAME))->AddString(_T("UserOutputValue"));
	((CComboBox*)GetDlgItem(IDC_COMBO_BLNNAME))->AddString(_T("LUTEnable"));

	((CComboBox*)GetDlgItem(IDC_COMBO_INTEGERNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_INTEGERNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_INTEGER, m_strName);
	SetDlgItemText(IDC_EDIT_INTEGERVALUE, m_Struct.Value);

	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_FLOATNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_FLOAT, m_strName);
	SetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);

	((CComboBox*)GetDlgItem(IDC_COMBO_ENUMNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_ENUMNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_ENUMERATION, m_strName);
	SetDlgItemText(IDC_EDIT_ENUMVALUE, m_Struct.Value);

	((CComboBox*)GetDlgItem(IDC_COMBO_COMNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_COMNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_COMMAND, m_strName);
	SetDlgItemText(IDC_EDIT_COMVALUE, m_Struct.Value);

	((CComboBox*)GetDlgItem(IDC_COMBO_STRNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_STRNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_STRING, m_strName);
	SetDlgItemText(IDC_EDIT_STRVALUE, m_Struct.Value);

	((CComboBox*)GetDlgItem(IDC_COMBO_BLNNAME))->SetCurSel(0);
	GetDlgItemText(IDC_COMBO_BLNNAME, m_strName);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_BOOLEAN, m_strName);
	SetDlgItemText(IDC_EDIT_BLNVALUE, m_Struct.Value);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

