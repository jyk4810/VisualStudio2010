#pragma once


// CChildDlg 대화 상자입니다.
class CDlgInfoExchangeDlg;

#define		USER_MESSAGE_DELETE_DIALOG				WM_APP+1
#define		USER_MESSAGE_SET_VALUE					WM_APP+2
#define		VALUE_TYPE_INTEGER						0
#define		VALUE_TYPE_FLOAT						1
#define		VALUE_TYPE_ENUMERATION					2
#define		VALUE_TYPE_COMMAND						3
#define		VALUE_TYPE_STRING						4
#define		VALUE_TYPE_BOOLEAN						5

typedef struct Struct
{
	CString Name;
	CString Value;
}STRUCT, *PSTRUCT;

class CChildDlg : public CDialog
{
	DECLARE_DYNAMIC(CChildDlg)

public:
	CChildDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChildDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CHILDDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();
	afx_msg void OnDestroy();

private:
	CDlgInfoExchangeDlg*	m_pParentDlg;
	CString					m_strName;
	Struct					m_Struct;
public:
	afx_msg void OnCbnSelchangeComboIntegername();
	afx_msg void OnCbnSelchangeComboFloatname();
	afx_msg void OnCbnSelchangeComboEnumname();
	afx_msg void OnCbnSelchangeComboComname();
	afx_msg void OnCbnSelchangeComboStrname();
	afx_msg void OnCbnSelchangeComboBlnname();
	afx_msg void OnEnUpdateEditIntegervalue();
	afx_msg void OnEnUpdateEditFloatvalue();
	afx_msg void OnEnUpdateEditEnumvalue();
	afx_msg void OnEnUpdateEditComvalue();
	afx_msg void OnEnUpdateEditStrvalue();
	afx_msg void OnEnUpdateEditBlnvalue();
	virtual BOOL OnInitDialog();
};
