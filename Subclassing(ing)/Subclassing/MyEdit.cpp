// MyEdit.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Subclassing.h"
#include "MyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit �޽��� ó�����Դϴ�.




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar >= '0' && nChar <= '9' || nChar == VK_BACK)
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}	
}
