#pragma once
#include "MyList.h"


// CPROCDLG3 �Ի���

class CPROCDLG3 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG3)

public:
	CPROCDLG3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPROCDLG3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListModule;
	BOOL EnumModule(int PID);
};
