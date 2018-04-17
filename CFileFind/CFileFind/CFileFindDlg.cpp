
// CFileFindDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CFileFind.h"
#include "CFileFindDlg.h"
#include "afxdialogex.h"

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


// CCFileFindDlg 대화 상자




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


// CCFileFindDlg 메시지 처리기

BOOL CCFileFindDlg::OnInitDialog()
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

		HTREEITEM hItem = m_Tree.InsertItem(_T("C:"), 0, 1, TVI_ROOT, TVI_LAST );
		WindowExplorer1(hItem, _T(""));

		return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCFileFindDlg::OnPaint()
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
HCURSOR CCFileFindDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CCFileFindDlg::OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
		LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

		HTREEITEM hSelected = pNMTreeView-> itemNew.hItem; //선택한 아이템 핸들 가져와서 hSelected에 저장

		((CListBox*)GetDlgItem(IDC_LIST_FILE))->ResetContent();

		CString pathSelected;
		HTREEITEM hParentItem = hSelected;

		while(hParentItem != NULL)
		{
				pathSelected = _T("\\") + pathSelected;
				pathSelected = m_Tree.GetItemText(hParentItem) + pathSelected;
				hParentItem = m_Tree. GetParentItem(hParentItem);
		}

		//if( pathSelected != _T("C:\\") ) // 원래 "C:" 를 GetParentItem이 안먹었었는데 갑자기 먹어서 주석처리함.
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
				else if(finder.IsHidden())  //숨겨진 파일 패스
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
		if(strtemp==_T("")) // tree control root 초기값
		{
				path = m_Tree.GetItemText(hItem1) + _T("\\");
		}
		else 
		{
				path = strtemp + _T("\\");
		}

		path = path + _T("*.*");
		CFileFind finder;
		BOOL bWorking = finder.FindFile(path); // path에서 찾겠다고 선언

		while(bWorking)
		{
				bWorking = finder.FindNextFile(); // 다음 파일 존재를 미리 조사하여 없으면 bWorking을 0으로만들어 루프빠져나감				
				CString str1 = finder.GetFileName();
				if(finder.IsDots()) // . 과 .. 폴더(상위폴더로 이동)를 걸러주기위해 사용
				{
						continue;	
				}
				else if(finder.IsHidden())  //숨겨진 파일 패스
				{
						continue;
				}
				else if(finder.IsDirectory())	 //폴더경로들...
				{
						CString str2 = finder.GetFilePath();
						HTREEITEM hItem2 = m_Tree.InsertItem(finder.GetFileName(), hItem1); // hItem1 에 InsertItem.
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
