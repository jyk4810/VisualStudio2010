
// TabctrlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabctrlDlg.h"
#include "afxdialogex.h"
#include "TabA.h"
#include "TabB.h"
#include "TabC.h"


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


// CTabctrlDlg 대화 상자




CTabctrlDlg::CTabctrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabctrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_tabA = NULL;
	m_tabB = NULL;
	m_tabC = NULL;
}

void CTabctrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_TEST, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CTabctrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_TEST, &CTabctrlDlg::OnTcnSelchangeTabTest)
END_MESSAGE_MAP()


// CTabctrlDlg 메시지 처리기

BOOL CTabctrlDlg::OnInitDialog()
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

	CString strDay[]={_T("A"),_T("B"),_T("C")};
	for(int i=0 ; i<3 ; i++)
	{
		((CTabCtrl*)GetDlgItem(IDC_TAB_TEST))->InsertItem(i,strDay[i]); // Tab List 추가
	}

	CRect rect;
	m_tabCtrl.GetWindowRect(&rect);

	m_tabA = new CTabA;
	m_tabA ->Create(IDD_DIALOG_A,&m_tabCtrl);
	m_tabA ->MoveWindow(0,20,rect.Width()+1,rect.Height()-19);
	m_tabA ->ShowWindow(SW_SHOW);

	m_tabB = new CTabB;
	m_tabB ->Create(IDD_DIALOG_B,&m_tabCtrl);
	m_tabB ->MoveWindow(0,20,rect.Width()+1,rect.Height()-19);
	m_tabB ->ShowWindow(SW_HIDE);

	m_tabC = new CTabC;
	m_tabC ->Create(IDD_DIALOG_C,&m_tabCtrl);
	m_tabC ->MoveWindow(0,20,rect.Width()+1,rect.Height()-19);
	m_tabC ->ShowWindow(SW_HIDE);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTabctrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTabctrlDlg::OnPaint()
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
HCURSOR CTabctrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabctrlDlg::OnTcnSelchangeTabTest(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	int TabCursel = m_tabCtrl.GetCurSel();

	switch(TabCursel )
	{
	case TAB_CURSEL_A:
		{
			m_tabA->ShowWindow(SW_SHOW);
			m_tabB->ShowWindow(SW_HIDE);
			m_tabC->ShowWindow(SW_HIDE);

		}
		break;
	case TAB_CURSEL_B:
		{
			m_tabA->ShowWindow(SW_HIDE);
			m_tabB->ShowWindow(SW_SHOW);
			m_tabC->ShowWindow(SW_HIDE);
		}
		break;
	case TAB_CURSEL_C:
		{
			m_tabA->ShowWindow(SW_HIDE);
			m_tabB->ShowWindow(SW_HIDE);
			m_tabC->ShowWindow(SW_SHOW);
		}
		break;
	}
	
	*pResult = 0;
}
