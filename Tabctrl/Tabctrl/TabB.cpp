// TabB.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabB.h"
#include "afxdialogex.h"


// CTabB ��ȭ �����Դϴ�.

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


// CTabB �޽��� ó�����Դϴ�.


void CTabB::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	delete this;

	CDialogEx::PostNcDestroy();
}


void CTabB::OnBnClickedButtonB()
{
	AfxMessageBox(_T(" B ��ư "));
}
