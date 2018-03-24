#pragma once
#include "MyList.h"


// CPROCDLG3 对话框

class CPROCDLG3 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG3)

public:
	CPROCDLG3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPROCDLG3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListModule;
	BOOL EnumModule(int PID);
};
