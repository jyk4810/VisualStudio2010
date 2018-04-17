#pragma once


// CTabB 대화 상자입니다.

class CTabB : public CDialogEx
{
	DECLARE_DYNAMIC(CTabB)

public:
	CTabB(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabB();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_B };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedButtonB();
};
