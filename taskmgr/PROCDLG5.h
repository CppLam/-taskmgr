#pragma once
#include "MyList.h"


// CPROCDLG5 �Ի���

class CPROCDLG5 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG5)

public:
	CPROCDLG5(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPROCDLG5();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListWin;
	void EnumW();
	virtual BOOL OnInitDialog();
};
