// TabB.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabB.h"
#include "afxdialogex.h"


// CTabB 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTabB, CDialogEx)

CTabB::CTabB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabB::IDD, pParent)
{

}

CTabB::~CTabB()
{
}

void CTabB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_B, &CTabB::OnBnClickedButtonB)
END_MESSAGE_MAP()


// CTabB 메시지 처리기입니다.


void CTabB::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;

	CDialogEx::PostNcDestroy();
}


void CTabB::OnBnClickedButtonB()
{
	AfxMessageBox(_T(" B 버튼 "));
}
