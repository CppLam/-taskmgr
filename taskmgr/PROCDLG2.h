#pragma once
#include "MyList.h"


// CPROCDLG2 对话框

class CPROCDLG2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG2)

public:
	CPROCDLG2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPROCDLG2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	BOOL CPROCDLG2::EnumThread(int PID);
	CMyList m_ListThr;
};
