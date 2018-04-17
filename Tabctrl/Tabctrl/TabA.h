#pragma once


// CTabA 대화 상자입니다.

class CTabA : public CDialogEx
{
	DECLARE_DYNAMIC(CTabA)

public:
	CTabA(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabA();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_A };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedButtonA();
};
