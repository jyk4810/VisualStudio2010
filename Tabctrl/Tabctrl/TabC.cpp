// TabC.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabC.h"
#include "afxdialogex.h"


// CTabC 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTabC, CDialogEx)

CTabC::CTabC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabC::IDD, pParent)
{

}

CTabC::~CTabC()
{
}

void CTabC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_C, &CTabC::OnBnClickedButtonC)
END_MESSAGE_MAP()


// CTabC 메시지 처리기입니다.


void CTabC::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;

	CDialogEx::PostNcDestroy();
}


void CTabC::OnBnClickedButtonC()
{
	AfxMessageBox(_T(" C 버튼 "));
}
