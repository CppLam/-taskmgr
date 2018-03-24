
// taskmgrDlg.h : 头文件
//

#pragma once
#include "DIAFILE.h"
#include "DIAPROC.h"
#include "afxcmn.h"
// CtaskmgrDlg 对话框
class CtaskmgrDlg : public CDialogEx
{
// 构造
public:
	CtaskmgrDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TASKMGR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_Menu;
	afx_msg void On32771();
	CDIAFILE m_DiaFile;
	CDIAPROC m_DiaProc;
protected:
	afx_msg LRESULT OnTurn1(WPARAM wParam, LPARAM lParam);
public:
	CProgressCtrl m_CPU;
	DWORD m_dwCPU;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
