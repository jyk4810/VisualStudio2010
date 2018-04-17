
// ScrollBarDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ScrollBar.h"
#include "ScrollBarDlg.h"
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


// CScrollBarDlg 대화 상자

CScrollBarDlg::CScrollBarDlg(CWnd* pParent /*=NULL*/)
		: CDialogEx(CScrollBarDlg::IDD, pParent)
{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		m_Width = 0;
		m_Height = 0;
		m_Position=0;
}

void CScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
		CDialogEx::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_SCROLLBAR_H, m_ctrHScroll);
		DDX_Control(pDX, IDC_SCROLLBAR_V, m_ctrVScroll);
}

BEGIN_MESSAGE_MAP(CScrollBarDlg, CDialogEx)
		ON_WM_SYSCOMMAND()
		ON_WM_PAINT()
		ON_WM_QUERYDRAGICON()
		ON_WM_HSCROLL()
		ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CScrollBarDlg 메시지 처리기

BOOL CScrollBarDlg::OnInitDialog()
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
		m_Image = imread("naver.bmp");

		HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_BOX); // IDC의 좌표를 직접 가져올 수 있다
		::GetClientRect(hwndBox, &m_dlgRect);
		m_ctrHScroll.SetScrollRange(0,m_Image.cols-m_dlgRect.right);
		m_ctrVScroll.SetScrollRange(0,m_Image.rows-m_dlgRect.bottom);
		InsertImg(m_Width,m_Height);

		return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CScrollBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScrollBarDlg::OnPaint()
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
				InsertImg(m_Width,m_Height);

		}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CScrollBarDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CScrollBarDlg::InsertImg(int nWidth, int nHeight)
{
		m_hDC = ::GetDC(this->m_hWnd); // 현재 다이얼로그 hwnd로 hdc를 잡는다.
		Mat imageROI = m_Image(Rect(nWidth,nHeight,m_dlgRect.right,m_dlgRect.bottom));

		m_hBitmap=CreateCompatibleBitmap(m_hDC,0,0);
		m_hBitmap = Mat2DIB(&imageROI);
		((CStatic*)GetDlgItem(IDC_STATIC_PICTURE))->SetBitmap(m_hBitmap);
		//	CWnd* pWnd(GetDlgItem(IDC_STATIC_PICTURE));
		//HWND hWnd =pWnd->m_hWnd;
		//HDC GetDC(hWnd);
		//CClientDC dc(pWnd);
		//BitBlt((HDC)&dc, 0, 0, m_Bitmap.bmWidth, m_Bitmap.bmHeight, m_hMemDC, 0, 0, SRCCOPY);

		//((CStatic*)GetDlgItem(IDC_STATIC_PICTURE))->SetBitmap((HBITMAP)bmp.GetSafeHandle());
		//((CStatic*)GetDlgItem(IDC_STATIC_PICTURE))->MoveWindow(0,0,200,200);

		//SelectObject(m_hMemDC, m_hOldBitmap);
}


HBITMAP CScrollBarDlg::Mat2DIB(Mat* Image)
{
		HBITMAP hbmp = NULL;
		int bpp = Image->channels() * 8;

		Mat tmp;
		cvtColor(*Image, tmp,CV_BGRA2BGR);

		BITMAPINFO bmpInfo = { 0 };
		LONG lBmpSize = Image->rows * Image->cols * 3;
		bmpInfo.bmiHeader.biBitCount = bpp;
		bmpInfo.bmiHeader.biHeight = Image->rows;
		bmpInfo.bmiHeader.biWidth = Image->cols;
		bmpInfo.bmiHeader.biPlanes = 1;
		bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		// Pointer to access the pixels of bitmap
		BYTE * pPixels = 0, *pP;
		hbmp = CreateDIBSection(NULL, (BITMAPINFO *)&bmpInfo, DIB_RGB_COLORS, (void **)&pPixels , NULL, 0);

		if ( !hbmp )
				return hbmp; // return if invalid bitmaps

		int left_width = ((bpp*Image->cols+31)/32)*4;
		pP = pPixels;
		for(int y=Image->rows-1, row=0; row<Image->rows; row++, y--) 
		{
				for(int x=0, col=0; col<Image->cols; x+=3, col++) 
				{
						pP[x] = tmp.at<Vec3b>(y, col).val[0];
						pP[x+1] = tmp.at<Vec3b>(y, col).val[1];
						pP[x+2] = tmp.at<Vec3b>(y, col).val[2];
				}
				pP += left_width;
		}
		return hbmp;
}

void CScrollBarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		if(pScrollBar == (CScrollBar*)&m_ctrHScroll) 
		{
				switch(nSBCode) // case 중에 SB_THUMBPOSITION와 SB_THUMBTRACK가 있는데 SB_THUMBTRACK가 먼저 호출되고 SB_THUMBPOSITION 가 호출되는데
				{							 // SB_THUMBPOSITION가 호출되면 nPos는 0으로 초기화된다. 이를 유념하고 코딩해야한다
				case SB_PAGEUP:
						{
								if( m_Width > m_dlgRect.right )
								{
										m_Width = m_Width - m_dlgRect.right;
										pScrollBar->SetScrollPos(m_Width);
								}
								else
								{
										m_Width = 0;
										pScrollBar->SetScrollPos(m_Width);
								}
						}
						break;
				case SB_PAGEDOWN:
						{
								m_Width = m_Width + m_dlgRect.right;
								if( m_Image.cols-(m_Width+m_dlgRect.right) >0 )
								{
										pScrollBar->SetScrollPos(m_Width);
								}
								else
								{
										m_Width = m_Image.cols - m_dlgRect.right;
										pScrollBar->SetScrollPos(m_Width);
								}
						}
						break;

				case SB_LINEDOWN:
						{
								if(m_Image.cols-m_dlgRect.right  > m_Width)
								{
										m_Width = m_Width + 10;
										pScrollBar->SetScrollPos(m_Width);
								}
						}
						break;
				case SB_LINEUP:
						{
								if(m_Width >= 10)
								{
										m_Width = m_Width - 10;
										pScrollBar->SetScrollPos(m_Width);
								}
						}
						break;
				case SB_THUMBPOSITION:
						break;
				case SB_THUMBTRACK:
						{
								m_Width = nPos;
								pScrollBar->SetScrollPos(nPos);

						}
						break;
				default:
						break;
				}
				InsertImg(m_Width,m_Height);
				HWND hwnd = AfxGetMainWnd()->m_hWnd; // 메인 다이얼로그의 hWnd가져오기
				InvalidateRect((LPCRECT)(m_Width,m_Height,m_dlgRect.right,m_dlgRect.bottom)); // 원하는 부분만 무효화영역 만들어서 다시그리게하기
		}
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CScrollBarDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
		if(pScrollBar == (CScrollBar*)&m_ctrVScroll)
		{
				switch(nSBCode)
				{
				case SB_PAGEUP:
						{
								if( m_Height > m_dlgRect.bottom )
								{
										m_Height  = m_Height - m_dlgRect.bottom;
										pScrollBar->SetScrollPos(m_Height );
								}
								else
								{
										m_Height  = 0;
										pScrollBar->SetScrollPos(m_Height );
								}
						}
						break;
				case SB_PAGEDOWN:
						{
								m_Height = m_Height + m_dlgRect.bottom;
								if( m_Image.rows-(m_Height+m_dlgRect.bottom) >0 )
								{
										pScrollBar->SetScrollPos(m_Height);
								}
								else
								{
										m_Height = m_Image.rows - m_dlgRect.bottom;
										pScrollBar->SetScrollPos(m_Height);
								}
						}
						break;
				case SB_LINEDOWN:
						{
								if(m_Image.rows-m_dlgRect.bottom  > m_Height)
								{
										m_Height = m_Height + 10;
										pScrollBar->SetScrollPos(m_Height);
								}
						}
						break;
				case SB_LINEUP:
						{
								if(m_Height >= 10)
								{
										m_Height = m_Height - 10;
										pScrollBar->SetScrollPos(m_Height);
								}
						}
						break;
				case SB_THUMBTRACK:
						{
								pScrollBar->SetScrollPos(nPos);
								m_Height = nPos;
						}
						break;
				}
				InsertImg(m_Width,m_Height);
				HWND hwnd = AfxGetMainWnd()->m_hWnd;
				InvalidateRect((LPCRECT)(m_Width,m_Height,m_dlgRect.right,m_dlgRect.bottom));
		}
		CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CScrollBarDlg::PreTranslateMessage(MSG* pMsg)
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
