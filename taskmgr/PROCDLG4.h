#pragma once
#include "MyList.h"


// CPROCDLG4 �Ի���

class CPROCDLG4 : public CDialogEx
{
	DECLARE_DYNAMIC(CPROCDLG4)

public:
	CPROCDLG4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPROCDLG4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCDLG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMyList m_ListHeap;
	BOOL EnumHeap(int PID);
};
