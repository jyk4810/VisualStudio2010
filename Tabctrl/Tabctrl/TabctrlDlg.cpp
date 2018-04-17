
// TabctrlDlg.cpp : ���� ����
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


// CTabctrlDlg ��ȭ ����




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


// CTabctrlDlg �޽��� ó����

BOOL CTabctrlDlg::OnInitDialog()
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

	CString strDay[]={_T("A"),_T("B"),_T("C")};
	for(int i=0 ; i<3 ; i++)
	{
		((CTabCtrl*)GetDlgItem(IDC_TAB_TEST))->InsertItem(i,strDay[i]); // Tab List �߰�
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


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTabctrlDlg::OnPaint()
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
