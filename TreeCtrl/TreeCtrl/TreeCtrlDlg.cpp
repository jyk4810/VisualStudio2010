
// TreeCtrlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TreeCtrl.h"
#include "TreeCtrlDlg.h"
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


// CTreeCtrlDlg ��ȭ ����




CTreeCtrlDlg::CTreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTreeCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strFocus =  _T("");
}

void CTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_Tree);
}

BEGIN_MESSAGE_MAP(CTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CTreeCtrlDlg::OnTvnSelchangedTree)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CTreeCtrlDlg::OnEnChangeEditName)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CTreeCtrlDlg::OnNMDblclkTree)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CTreeCtrlDlg::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CTreeCtrlDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CTreeCtrlDlg::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// CTreeCtrlDlg �޽��� ó����

BOOL CTreeCtrlDlg::OnInitDialog()
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

	HTREEITEM  hRoot;
	hRoot = m_Tree.InsertItem(L"Root", 0, 1, TVI_ROOT, TVI_LAST ) ;

	HTREEITEM  hA;
	hA = m_Tree.InsertItem(L"A", 1, 1, hRoot, TVI_LAST ) ;

	HTREEITEM  hA1;
	hA1 = m_Tree.InsertItem(L"A1", 1, 1, hA, TVI_LAST ) ;

	HTREEITEM  hB;
	hB = ((CTreeCtrl*)GetDlgItem(IDC_TREE))->InsertItem(L"B", 1, 1,hRoot, TVI_LAST ) ;

	HTREEITEM  hB1;
	hB1 = ((CTreeCtrl*)GetDlgItem(IDC_TREE))->InsertItem(L"B1", 1, 1,hB, TVI_LAST ) ;

	HTREEITEM  hB2;
	hB2 = ((CTreeCtrl*)GetDlgItem(IDC_TREE))->InsertItem(L"B2", 1, 1,hB1, TVI_LAST ) ;
	
	phB2 = &hB2;
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtrlDlg::OnPaint()
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
HCURSOR CTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeCtrlDlg::OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	m_strFocus = m_Tree.GetItemText(pNMTreeView->itemNew.hItem);
	SetDlgItemText(IDC_EDIT_NAME, m_strFocus);

	*pResult = 0;
}


void CTreeCtrlDlg::OnEnChangeEditName()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTreeCtrlDlg::OnNMDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{	
	AfxMessageBox(m_strFocus);
	*pResult = 0;
}


void CTreeCtrlDlg::OnBnClickedButtonInsert()
{
	CString strTemp = _T("");
	GetDlgItemText(IDC_EDIT_INSERT, strTemp);

	HTREEITEM hTreeItem = m_Tree.GetSelectedItem();	
	m_Tree.InsertItem(strTemp, 0, 1, hTreeItem, TVI_LAST ) ;
	m_Tree.Expand(hTreeItem, TVE_EXPAND);
	
}


void CTreeCtrlDlg::OnBnClickedButtonDelete()
{
	HTREEITEM hTreeItem = m_Tree.GetSelectedItem();
	m_Tree.DeleteItem(hTreeItem);

	//ref.
	//m_Tree.DeleteAllItems();

}


void CTreeCtrlDlg::OnBnClickedButtonChange()
{
	CString strTemp = _T("");
	HTREEITEM hTreeItem = m_Tree.GetSelectedItem();
	GetDlgItemText(IDC_EDIT_CHANGE, strTemp);
	m_Tree.SetItemText(hTreeItem,strTemp);
}
