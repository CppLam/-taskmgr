#pragma once
#include "MyList.h"


// CPROCDLG5 对话框

class CPROCDLG5 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG5)

public:
	CPROCDLG5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPROCDLG5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListWin;
	void EnumW();
	virtual BOOL OnInitDialog();
};
