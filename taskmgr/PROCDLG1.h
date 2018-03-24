#pragma once
#include "afxcmn.h"
#include "MyList.h"

// CPROCDLG1 对话框

class CPROCDLG1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG1)

public:
	CPROCDLG1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPROCDLG1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListProc;
	virtual BOOL OnInitDialog();
	BOOL CPROCDLG1::EnumProc();
	
	afx_msg void OnNMClickMylist(NMHDR *pNMHDR, LRESULT *pResult);
};
