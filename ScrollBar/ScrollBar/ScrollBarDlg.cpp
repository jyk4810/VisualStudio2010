
// ScrollBarDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ScrollBar.h"
#include "ScrollBarDlg.h"
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


// CScrollBarDlg ��ȭ ����

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


// CScrollBarDlg �޽��� ó����

BOOL CScrollBarDlg::OnInitDialog()
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
		m_Image = imread("naver.bmp");

		HWND hwndBox = ::GetDlgItem(this->m_hWnd, IDC_STATIC_BOX); // IDC�� ��ǥ�� ���� ������ �� �ִ�
		::GetClientRect(hwndBox, &m_dlgRect);
		m_ctrHScroll.SetScrollRange(0,m_Image.cols-m_dlgRect.right);
		m_ctrVScroll.SetScrollRange(0,m_Image.rows-m_dlgRect.bottom);
		InsertImg(m_Width,m_Height);

		return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CScrollBarDlg::OnPaint()
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
				InsertImg(m_Width,m_Height);

		}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CScrollBarDlg::OnQueryDragIcon()
{
		return static_cast<HCURSOR>(m_hIcon);
}



void CScrollBarDlg::InsertImg(int nWidth, int nHeight)
{
		m_hDC = ::GetDC(this->m_hWnd); // ���� ���̾�α� hwnd�� hdc�� ��´�.
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
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

		if(pScrollBar == (CScrollBar*)&m_ctrHScroll) 
		{
				switch(nSBCode) // case �߿� SB_THUMBPOSITION�� SB_THUMBTRACK�� �ִµ� SB_THUMBTRACK�� ���� ȣ��ǰ� SB_THUMBPOSITION �� ȣ��Ǵµ�
				{							 // SB_THUMBPOSITION�� ȣ��Ǹ� nPos�� 0���� �ʱ�ȭ�ȴ�. �̸� �����ϰ� �ڵ��ؾ��Ѵ�
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
				HWND hwnd = AfxGetMainWnd()->m_hWnd; // ���� ���̾�α��� hWnd��������
				InvalidateRect((LPCRECT)(m_Width,m_Height,m_dlgRect.right,m_dlgRect.bottom)); // ���ϴ� �κи� ��ȿȭ���� ���� �ٽñ׸����ϱ�
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
