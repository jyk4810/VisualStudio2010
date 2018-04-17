// MyButton.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Subclassing.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CMyButton 메시지 처리기입니다.




void CMyButton::OnLButtonDown(UINT nFlags, CPoint point)
{	
    GetParent()->PostMessage(WM_COMMAND, GetDlgCtrlID() + 10000, (LPARAM)m_hWnd);

	CButton::OnLButtonDown(nFlags, point);
}


void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	GetParent()->PostMessage(WM_COMMAND, GetDlgCtrlID() + 10001, (LPARAM)m_hWnd);

	CButton::OnLButtonUp(nFlags, point);
}
