
// IplImageMatCvMatDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "IplImageMatCvMat.h"
#include "IplImageMatCvMatDlg.h"
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


// CIplImageMatCvMatDlg ��ȭ ����




CIplImageMatCvMatDlg::CIplImageMatCvMatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIplImageMatCvMatDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pcvMatImage = NULL;
}

void CIplImageMatCvMatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIplImageMatCvMatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_tomat, &CIplImageMatCvMatDlg::OnBnClickedButtontomat)
	ON_BN_CLICKED(IDC_BUTTON_tocvMat, &CIplImageMatCvMatDlg::OnBnClickedButtontocvmat)
	ON_BN_CLICKED(IDC_BUTTON_cvMatToIplImage, &CIplImageMatCvMatDlg::OnBnClickedButtoncvmattoiplimage)
	ON_BN_CLICKED(IDC_BUTTON_cvMatToMat, &CIplImageMatCvMatDlg::OnBnClickedButtoncvmattomat)
END_MESSAGE_MAP()


// CIplImageMatCvMatDlg �޽��� ó����

BOOL CIplImageMatCvMatDlg::OnInitDialog()
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
	MakeIplImage();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CIplImageMatCvMatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIplImageMatCvMatDlg::OnPaint()
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
HCURSOR CIplImageMatCvMatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIplImageMatCvMatDlg::MakeIplImage(void)
{
	m_pimg = cvCreateImage(cvSize(256,256),IPL_DEPTH_8U,1);

	for ( int i = 0; i < m_pimg->height ; i++ )
	{
		for ( int j = 0 ; j < m_pimg->width ; j++ )
		{
			m_pimg->imageData[j+i*m_pimg->widthStep] = i ;
		}
	}

	cvShowImage("IplImage", m_pimg);
}


void CIplImageMatCvMatDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if( m_pimg != NULL )
	{
		cvReleaseImage(&m_pimg);
		cvDestroyWindow("IplImage");
		cvDestroyWindow("MatImage");
		cvDestroyWindow("cvMatImage");
		cvDestroyWindow("cvMat To IplImage");
		cvDestroyWindow("cvMat To cv::Mat");
	}

}


void CIplImageMatCvMatDlg::OnBnClickedButtontomat()
{
	Mat matImage = cvarrToMat(m_pimg);

	imshow("MatImage",matImage);
}


void CIplImageMatCvMatDlg::OnBnClickedButtontocvmat()
{
	m_pcvMatImage = new CvMat;
	cvGetMat(m_pimg,m_pcvMatImage);
}


void CIplImageMatCvMatDlg::OnBnClickedButtoncvmattoiplimage()
{
	IplImage tempImage;
	IplImage* iplImage = cvGetImage(&m_pcvMatImage,&tempImage);
	cvShowImage("cvMat To IplImage", iplImage);
}


void CIplImageMatCvMatDlg::OnBnClickedButtoncvmattomat()
{
	if( m_pcvMatImage != NULL )
	{
		Mat TempMat(m_pcvMatImage);
		imshow("cvMat To cv::Mat",TempMat);
	}
}
