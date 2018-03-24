#pragma once
#include "MyList.h"


// CPROCDLG4 对话框

class CPROCDLG4 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG4)

public:
	CPROCDLG4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPROCDLG4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListHeap;
	BOOL EnumHeap(int PID);
};
