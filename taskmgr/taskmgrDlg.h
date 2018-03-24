
// taskmgrDlg.h : ͷ�ļ�
//

#pragma once
#include "DIAFILE.h"
#include "DIAPROC.h"
#include "afxcmn.h"
// CtaskmgrDlg �Ի���
class CtaskmgrDlg : public CDialogEx
{
// ����
public:
	CtaskmgrDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TASKMGR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
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
