#pragma once
#include "PROCDLG1.h"
#include "PROCDLG2.h"
#include "PROCDLG3.h"
#include "PROCDLG4.h"
#include "PROCDLG5.h"
#define HIDE m_Dia1.ShowWindow(SW_HIDE);\
			 m_Dia2.ShowWindow(SW_HIDE);\
			 m_Dia3.ShowWindow(SW_HIDE);\
			 m_Dia4.ShowWindow(SW_HIDE);\
			 m_Dia5.ShowWindow(SW_HIDE);

class CMyTab : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTab)

public:
	CMyTab();
	virtual ~CMyTab();
	CPROCDLG1 m_Dia1;
	CPROCDLG2 m_Dia2;
	CPROCDLG3 m_Dia3;
	CPROCDLG4 m_Dia4;
	CPROCDLG5 m_Dia5;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	afx_msg LRESULT OnPidm(WPARAM wParam, LPARAM lParam);
};


