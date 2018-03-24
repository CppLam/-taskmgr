#pragma once
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"
#include "afxwin.h"


// CDIAFILE 对话框

class CDIAFILE : public CDialogEx
{
	DECLARE_DYNAMIC(CDIAFILE)

public:
	CDIAFILE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDIAFILE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDIAFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMFCShellTreeCtrl m_FileTree;
	CMFCShellListCtrl m_FileList;
	BOOL m_B1;
	BOOL m_B2;
	BOOL m_B3;
	BOOL m_B4;
	BOOL m_B5;
	BOOL m_B6;
	BOOL m_B7;
	BOOL m_BC;
	virtual BOOL OnInitDialog();
	CString m_Path;
	void CDIAFILE::SetTextPath();
	afx_msg void OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCancel();
	BOOL CDIAFILE::CleanFile(CString path);
	afx_msg void OnBnClickedCheck();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnLvnColumnclickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult);
};
