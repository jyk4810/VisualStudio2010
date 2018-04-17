
// ListCtrlFontDlg.h : 헤더 파일
//

#pragma once



#define IMAGE_INT			0
#define IMAGE_FLOAT		1
#define IMAGE_ENUM		2
#define IMAGE_COM			3
#define IMAGE_STR			4
#define IMAGE_BOOL		5

// CListCtrlFontDlg 대화 상자
class CListCtrlFontDlg : public CDialogEx
{
// 생성입니다.
public:
	CListCtrlFontDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LISTCTRLFONT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CImageList*		m_pImageList;
	CFont					m_Gabriola;
	CFont					m_Impact;
	CFont					m_LucidaConsole;
	CFont					m_FranklinGothicMedium;
	CFont					m_Nina;
	CFont					m_SegoeScript;
	CFont					m_MVBoli;
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedRadioAll();
	afx_msg void OnBnClickedRadioInt();
	afx_msg void OnBnClickedRadioFloat();
	afx_msg void OnBnClickedRadioEnum();
	afx_msg void OnBnClickedRadioCom();
	afx_msg void OnBnClickedRadioStr();
	afx_msg void OnBnClickedRadioBool();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
