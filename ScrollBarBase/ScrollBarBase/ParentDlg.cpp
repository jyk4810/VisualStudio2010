// ParentDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScrollBarBase.h"
#include "ParentDlg.h"
#include "afxdialogex.h"


// CParentDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CParentDlg, CDialog)

CParentDlg::CParentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CParentDlg::IDD, pParent)
{

}

CParentDlg::~CParentDlg()
{
}

void CParentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CParentDlg, CDialog)
END_MESSAGE_MAP()


// CParentDlg �޽��� ó�����Դϴ�.
