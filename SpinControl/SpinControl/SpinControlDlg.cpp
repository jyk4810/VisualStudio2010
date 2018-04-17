
// SpinControlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SpinControl.h"
#include "SpinControlDlg.h"
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


// CSpinControlDlg ��ȭ ����




CSpinControlDlg::CSpinControlDlg(CWnd* pParent /*=NULL*/)
		: CDialogEx(CSpinControlDlg::IDD, pParent)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		m_neditSpinVal = 0;
}

void CSpinControlDlg::DoDataExchange(CDataExchange* pDX)
{
		CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSpinControlDlg, CDialogEx)
		ON_WM_SYSCOMMAND()
		ON_WM_PAINT()
		ON_WM_QUERYDRAGICON()
		ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &CSpinControlDlg::OnDeltaposSpin)
END_MESSAGE_MAP()


// CSpinControlDlg �޽��� ó����

BOOL CSpinControlDlg::OnInitDialog()
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

		SetDlgItemInt(IDC_EDIT_SPIN, 0);

		return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSpinControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSpinControlDlg::OnPaint()
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
HCURSOR CSpinControlDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CSpinControlDlg::OnDeltaposSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
		LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

		CString strTemp = _T("");
		GetDlgItemText(IDC_EDIT_SPIN, strTemp);
		m_neditSpinVal= (int)_wtoi( strTemp.GetBuffer(0));
		if(m_neditSpinVal > 99)
				m_neditSpinVal = 99;
		else if( m_neditSpinVal <0 )
				m_neditSpinVal = 1;

		SetDlgItemInt(IDC_EDIT_SPIN, m_neditSpinVal);
		if(pNMUpDown->iDelta<0)
		{
				m_neditSpinVal++;
		}
		else if(m_neditSpinVal >0)
		{
				m_neditSpinVal--;
		}
		SetDlgItemInt(IDC_EDIT_SPIN, m_neditSpinVal);
		*pResult = 0;
}


BOOL CSpinControlDlg::PreTranslateMessage(MSG* pMsg)
{
		if(pMsg->message == WM_KEYDOWN && GetDlgItem(IDC_EDIT_SPIN) == GetFocus())			
		{			
				switch(pMsg->wParam)
				{
				case VK_RETURN:
						{
								CString strTemp = _T("");
								GetDlgItemText(IDC_EDIT_SPIN, strTemp);
								m_neditSpinVal= (int)_wtoi( strTemp.GetBuffer(0));
								if(m_neditSpinVal > 99)
										m_neditSpinVal = 100;
								else if( m_neditSpinVal <1 )
										m_neditSpinVal = 0;
						}
						SetDlgItemInt(IDC_EDIT_SPIN, m_neditSpinVal);
				default:
						break;
				}
		}

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
