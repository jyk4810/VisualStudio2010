
// IPAddressControlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "IPAddressControl.h"
#include "IPAddressControlDlg.h"
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


// CIPAddressControlDlg ��ȭ ����




CIPAddressControlDlg::CIPAddressControlDlg(CWnd* pParent /*=NULL*/)
		: CDialogEx(CIPAddressControlDlg::IDD, pParent)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPAddressControlDlg::DoDataExchange(CDataExchange* pDX)
{
		CDialogEx::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_IPADDRESS, m_IPAddressCtrl);
}

BEGIN_MESSAGE_MAP(CIPAddressControlDlg, CDialogEx)
		ON_WM_SYSCOMMAND()
		ON_WM_PAINT()
		ON_WM_QUERYDRAGICON()
		ON_BN_CLICKED(IDC_BUTTON, &CIPAddressControlDlg::OnBnClickedButton)
END_MESSAGE_MAP()


// CIPAddressControlDlg �޽��� ó����

BOOL CIPAddressControlDlg::OnInitDialog()
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
		
		return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CIPAddressControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIPAddressControlDlg::OnPaint()
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
HCURSOR CIPAddressControlDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CIPAddressControlDlg::OnBnClickedButton()
{
		BYTE IP_a, IP_b, IP_c, IP_d;

		m_IPAddressCtrl.GetAddress(IP_a, IP_b, IP_c, IP_d );
		CString dstIP;
		dstIP.Format(_T("%d.%d.%d.%d"), IP_a, IP_b, IP_c, IP_d );
		AfxMessageBox(dstIP);
}
