// TabA.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabA.h"
#include "afxdialogex.h"


// CTabA ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTabA, CDialogEx)

CTabA::CTabA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabA::IDD, pParent)
{

}

CTabA::~CTabA()
{
}

void CTabA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_A, &CTabA::OnBnClickedButtonA)
END_MESSAGE_MAP()


// CTabA �޽��� ó�����Դϴ�.


void CTabA::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	delete this;
	CDialogEx::PostNcDestroy();
}


void CTabA::OnBnClickedButtonA()
{
	AfxMessageBox(_T(" A ��ư "));
}
