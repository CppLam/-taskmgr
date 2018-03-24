#pragma once
#include "afxcmn.h"
#include "MyTab.h"

// CDIAPROC 对话框

class CDIAPROC : public CDialogEx
{
	DECLARE_DYNAMIC(CDIAPROC)

public:
	CDIAPROC(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIAPROC();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDIAPROC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	afx_msg void OnSelchangeIddMytab(NMHDR *pNMHDR, LRESULT *pResult);
	CMyTab m_MyTab;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
protected:
//	afx_msg LRESULT OnProcpid(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnPidm(WPARAM wParam, LPARAM lParam);
public:
//	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton1();
};
