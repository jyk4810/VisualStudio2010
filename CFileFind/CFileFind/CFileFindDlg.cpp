
// CFileFindDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CFileFind.h"
#include "CFileFindDlg.h"
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


// CCFileFindDlg ��ȭ ����




CCFileFindDlg::CCFileFindDlg(CWnd* pParent /*=NULL*/)
		: CDialogEx(CCFileFindDlg::IDD, pParent)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CCFileFindDlg::DoDataExchange(CDataExchange* pDX)
{
		CDialogEx::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_TREE, m_Tree);
}

BEGIN_MESSAGE_MAP(CCFileFindDlg, CDialogEx)
		ON_WM_SYSCOMMAND()
		ON_WM_PAINT()
		ON_WM_QUERYDRAGICON()
		ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CCFileFindDlg::OnTvnSelchangedTree)
		ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCFileFindDlg �޽��� ó����

BOOL CCFileFindDlg::OnInitDialog()
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

		HTREEITEM hItem = m_Tree.InsertItem(_T("C:"), 0, 1, TVI_ROOT, TVI_LAST );
		WindowExplorer1(hItem, _T(""));

		return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCFileFindDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCFileFindDlg::OnPaint()
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
HCURSOR CCFileFindDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CCFileFindDlg::OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
		LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

		HTREEITEM hSelected = pNMTreeView-> itemNew.hItem; //������ ������ �ڵ� �����ͼ� hSelected�� ����

		((CListBox*)GetDlgItem(IDC_LIST_FILE))->ResetContent();

		CString pathSelected;
		HTREEITEM hParentItem = hSelected;

		while(hParentItem != NULL)
		{
				pathSelected = _T("\\") + pathSelected;
				pathSelected = m_Tree.GetItemText(hParentItem) + pathSelected;
				hParentItem = m_Tree. GetParentItem(hParentItem);
		}

		//if( pathSelected != _T("C:\\") ) // ���� "C:" �� GetParentItem�� �ȸԾ����µ� ���ڱ� �Ծ �ּ�ó����.
		//{
		//	pathSelected = _T("C:\\") + pathSelected;
		//}

		pathSelected = pathSelected + _T("*.*");

		CFileFind finder;
		BOOL bWorking = finder.FindFile(pathSelected);

		while(bWorking)
		{
				bWorking = finder.FindNextFile();
				if(finder.IsDots()){continue;}
				else if(finder.IsHidden())  //������ ���� �н�
				{
						continue;
				}
				else if(finder.IsDirectory()) {continue;}
				else
				{
						CString strTemp = _T("");
						strTemp = finder.GetFileName();
						((CListBox*)GetDlgItem(IDC_LIST_FILE))->AddString(strTemp);
				}
		}

		*pResult = 0;
}

void CCFileFindDlg::WindowExplorer1(HTREEITEM hItem1, CString strtemp )
{
		CString path = _T("");
		if(strtemp==_T("")) // tree control root �ʱⰪ
		{
				path = m_Tree.GetItemText(hItem1) + _T("\\");
		}
		else 
		{
				path = strtemp + _T("\\");
		}

		path = path + _T("*.*");
		CFileFind finder;
		BOOL bWorking = finder.FindFile(path); // path���� ã�ڴٰ� ����

		while(bWorking)
		{
				bWorking = finder.FindNextFile(); // ���� ���� ���縦 �̸� �����Ͽ� ������ bWorking�� 0���θ���� ������������				
				CString str1 = finder.GetFileName();
				if(finder.IsDots()) // . �� .. ����(���������� �̵�)�� �ɷ��ֱ����� ���
				{
						continue;	
				}
				else if(finder.IsHidden())  //������ ���� �н�
				{
						continue;
				}
				else if(finder.IsDirectory())	 //������ε�...
				{
						CString str2 = finder.GetFilePath();
						HTREEITEM hItem2 = m_Tree.InsertItem(finder.GetFileName(), hItem1); // hItem1 �� InsertItem.
						WindowExplorer1(hItem2, finder.GetFilePath());
				}
				else
				{
						break;
				}
		}
		finder.Close();
}


void CCFileFindDlg::OnDestroy()
{
		m_Tree.DeleteAllItems();
		CDialogEx::OnDestroy();
}


BOOL CCFileFindDlg::PreTranslateMessage(MSG* pMsg)
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

		return CDialogEx::PreTranslateMessage(pMsg);
}
