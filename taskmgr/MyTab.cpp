// MyTab.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "MyTab.h"
#include <vector>


// CMyTab

IMPLEMENT_DYNAMIC(CMyTab, CTabCtrl)

CMyTab::CMyTab()
{

}

CMyTab::~CMyTab()
{
}


BEGIN_MESSAGE_MAP(CMyTab, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTab::OnTcnSelchange)
	ON_MESSAGE(WM_PIDM, &CMyTab::OnPidm)
//	ON_COMMAND(IDC_BUTTON1, &CMyTab::OnButton1)
END_MESSAGE_MAP()



// CMyTab ��Ϣ�������




void CMyTab::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//tab�����л�
	HIDE
	int nNum = GetCurSel();
	switch (nNum)
	{
	case 0:
		m_Dia1.ShowWindow(SW_SHOW);
		break;
	case 1:
		m_Dia2.ShowWindow(SW_SHOW);
		break;
	case 2:
		m_Dia3.ShowWindow(SW_SHOW);
		break;
	case 3:
		m_Dia4.ShowWindow(SW_SHOW);
		break;
	case 4:
		m_Dia5.ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}


afx_msg LRESULT CMyTab::OnPidm(WPARAM wParam, LPARAM lParam)
{
	m_Dia2.EnumThread(wParam);
	return 0;
}


//void CMyTab::OnButton1()
//{
//	// TODO: �ڴ���������������
//	
//
//}

