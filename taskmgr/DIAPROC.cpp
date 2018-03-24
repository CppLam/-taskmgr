// DIAPROC.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "DIAPROC.h"
#include "afxdialogex.h"
#include "DIAFILE.h"
#include "PROCDLG1.h"
#include "PROCDLG2.h"
#include "PROCDLG3.h"
#include "PROCDLG4.h"
#include "PROCDLG5.h"
#include <Tlhelp32.h>
// CDIAPROC �Ի���

IMPLEMENT_DYNAMIC(CDIAPROC, CDialogEx)

CDIAPROC::CDIAPROC(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CDIAPROC, pParent)
{

}

CDIAPROC::~CDIAPROC()
{
}

void CDIAPROC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_MYTAB, m_MyTab);
}


BEGIN_MESSAGE_MAP(CDIAPROC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDIAPROC::OnBnClickedOk)
ON_BN_CLICKED(IDCANCEL, &CDIAPROC::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BUTTON1, &CDIAPROC::OnClickedButton1)
END_MESSAGE_MAP()


// CDIAPROC ��Ϣ�������

void CDIAPROC::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	
	GetParent() -> SendMessage(WM_TURN1, 1, 0);

}



BOOL CDIAPROC::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//Ϊtab�󶨸��Ӵ���
	m_MyTab.ShowWindow(SW_SHOW);
	m_MyTab.InsertItem(0, L"����");
	m_MyTab.InsertItem(1, L"�߳�");
	m_MyTab.InsertItem(2, L"ģ��");
	m_MyTab.InsertItem(3, L"��");
	m_MyTab.InsertItem(4, L"����");
	m_MyTab.m_Dia1.Create(IDD_PROCDLG1,&m_MyTab);
	m_MyTab.m_Dia2.Create(IDD_PROCDLG2,&m_MyTab);
	m_MyTab.m_Dia3.Create(IDD_PROCDLG3,&m_MyTab);
	m_MyTab.m_Dia4.Create(IDD_PROCDLG4, &m_MyTab);
	m_MyTab.m_Dia5.Create(IDD_PROCDLG5, &m_MyTab);
	m_MyTab.m_Dia1.ShowWindow(SW_SHOW);
	m_MyTab.m_Dia2.ShowWindow(SW_HIDE);
	m_MyTab.m_Dia3.ShowWindow(SW_HIDE);
	m_MyTab.m_Dia4.ShowWindow(SW_HIDE);
	m_MyTab.m_Dia5.ShowWindow(SW_HIDE);
	//���ڸ�tab�Ӵ���λ��
	CRect rc;
	m_MyTab.GetClientRect(rc);
	rc.DeflateRect(-10, 23, 0, 0);
	m_MyTab.m_Dia1.MoveWindow(rc);
	m_MyTab.m_Dia2.MoveWindow(rc);
	m_MyTab.m_Dia3.MoveWindow(rc);
	m_MyTab.m_Dia4.MoveWindow(rc);
	m_MyTab.m_Dia5.MoveWindow(rc);
	//��ʼ����tabҳlist�б�ǩ
	m_MyTab.m_Dia1.m_ListProc.AddColumn(4, L"�� ��", L"PID", L"������PID", L"�߳���");
	m_MyTab.m_Dia2.m_ListThr.AddColumn(3, L"TID", L"PID", L"���ȼ�");
	m_MyTab.m_Dia3.m_ListModule.AddColumn(4, L"ģ����", L"PID", L"ģ��·��",L"BYTE");
	m_MyTab.m_Dia4.m_ListHeap.AddColumn(4, L"HID", L"PID", L"���Ե�ַ", L"BYTE");
	m_MyTab.m_Dia5.m_ListWin.AddColumn(3, L"�� ��", L"�� ��", L"·��");

	//��ʼ��������Ϣ
	m_MyTab.m_Dia1.EnumProc();
	m_MyTab.m_Dia5.EnumW();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

//��������
void CDIAPROC::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nItem = m_MyTab.m_Dia1.m_ListProc.m_nItem;
	CString strPid = m_MyTab.m_Dia1.m_ListProc.GetItemText(nItem, 1);;
//	pid += "taskkill /pid ";
//	pid += m_MyTab.m_Dia1.m_ListProc.GetItemText(nItem, 1);
//	pid += " /f";
	int pid = _ttoi(strPid.GetBuffer());
	HANDLE hPro = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	if(TerminateProcess(hPro, 0))
		MessageBox(L"�����ѽ�����",L"��ʾ",MB_OK);
	else
	{
		CString errcode;
		errcode.Format(GetLastError(), "%d");
		MessageBox(errcode, L"��ʾ", MB_OK);

	}

	//_tsystem(pid.GetBuffer());
		
}



void CDIAPROC::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR* ch = new TCHAR[8];
	int temp = 0;
	int SIZE = m_MyTab.m_Dia1.m_ListProc.GetItemCount();
	m_MyTab.m_Dia2.m_ListThr.DeleteAllItems();
	m_MyTab.m_Dia3.m_ListModule.DeleteAllItems();
	for (int i = 0; i< SIZE; i++)
	{
		if (m_MyTab.m_Dia1.m_ListProc.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED || m_MyTab.m_Dia1.m_ListProc.GetCheck(i))
		{
			ch = m_MyTab.m_Dia1.m_ListProc.GetItemText(i, 1).GetBuffer();
			temp = _ttoi(ch);
			m_MyTab.m_Dia2.EnumThread(temp);
			m_MyTab.m_Dia3.EnumModule(temp);
			m_MyTab.m_Dia4.EnumHeap(temp);
		}
	}
	if (SIZE == 0)
		MessageBox(L"��ѡ��Ҫ�鿴����!", L"��ʾ",MB_OK);
	else
		MessageBox(L"�߳�ģ��ͬ���ɹ���", L"��ʾ", MB_OK);
}
