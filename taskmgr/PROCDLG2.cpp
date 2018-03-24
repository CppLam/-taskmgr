// PROCDLG2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "PROCDLG2.h"
#include "afxdialogex.h"


// CPROCDLG2 �Ի���

IMPLEMENT_DYNAMIC(CPROCDLG2, CDialogEx)

CPROCDLG2::CPROCDLG2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROCDLG2, pParent)
{

}

CPROCDLG2::~CPROCDLG2()
{
}

void CPROCDLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListThr);
}


BEGIN_MESSAGE_MAP(CPROCDLG2, CDialogEx)
END_MESSAGE_MAP()


// CPROCDLG2 ��Ϣ�������


BOOL CPROCDLG2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CPROCDLG2::EnumThread(int PID)
{
	HANDLE hThrSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, PID);
	if (hThrSnap == INVALID_HANDLE_VALUE)
	{
		MessageBox(L"���մ���", L"����", MB_ICONWARNING);
		return FALSE;
	}
	THREADENTRY32 tsi = { sizeof(THREADENTRY32) };
	if (!Thread32First(hThrSnap, &tsi))
	{
		MessageBox(L"Thread32First error!", L"����", MB_ICONWARNING);
		return FALSE;
	}
	int i = 0;
	TCHAR item1[8],item2[8], item3[8];

	do
	{
		_stprintf_s(item1, 8, L"%d", tsi.th32ThreadID);
		_stprintf_s(item2, 8, L"%d", tsi.th32OwnerProcessID);
		_stprintf_s(item3, 8, L"%d", tsi.tpBasePri);
		if(tsi.th32OwnerProcessID == PID)
			m_ListThr.AddItem(i, 3, item1, item2, item3);
	} while (Thread32Next(hThrSnap, &tsi));
	CloseHandle(hThrSnap);
	return TRUE;
}