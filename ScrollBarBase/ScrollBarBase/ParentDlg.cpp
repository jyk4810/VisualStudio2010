// ParentDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ScrollBarBase.h"
#include "ParentDlg.h"
#include "afxdialogex.h"


// CParentDlg 대화 상자입니다.

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


// CParentDlg 메시지 처리기입니다.
