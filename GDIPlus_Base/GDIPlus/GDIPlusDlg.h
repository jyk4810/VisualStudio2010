
// GDIPlusDlg.h : ��� ����
//

#pragma once

#include <gdiplus.h>
	#pragma comment(lib, "gdiplus")
	using namespace Gdiplus;

// CGDIPlusDlg ��ȭ ����
class CGDIPlusDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CGDIPlusDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GDIPlus_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
		afx_msg void OnDestroy();

		afx_msg void OnBnClickedButtonOpen();

private:
		HDC						m_hDC;
		Graphics*			m_pGraphics;
		Bitmap*				m_pBitmap;
		int						m_Width;
		int						m_Height;
		CRect					m_rcDisp;	
		CString				m_strPathName ;
};
