// TabC.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tabctrl.h"
#include "TabC.h"
#include "afxdialogex.h"


// CTabC ��ȭ �����Դϴ�.

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


// CTabC �޽��� ó�����Դϴ�.


void CTabC::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	delete this;

	CDialogEx::PostNcDestroy();
}


void CTabC::OnBnClickedButtonC()
{
	AfxMessageBox(_T(" C ��ư "));
}
