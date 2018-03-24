// PROCDLG5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "PROCDLG5.h"
#include "afxdialogex.h"


// CPROCDLG5 �Ի���

IMPLEMENT_DYNAMIC(CPROCDLG5, CDialogEx)

BOOL CALLBACK EnumWinProc(HWND hWnd, LPARAM lParam)
{
	TCHAR buff[MAX_PATH];
	::GetWindowText(hWnd, buff, MAX_PATH);
	if (::IsWindowVisible(hWnd) == TRUE&&_tcslen(buff) != 0)
	{
		CMyList* temp = (CMyList*)lParam;
		TCHAR szClass[MAX_PATH] = {L"1"}, szPath[MAX_PATH] = {};
		::RealGetWindowClass(hWnd, szClass, MAX_PATH);
		::GetWindowModuleFileName(hWnd, szPath, MAX_PATH);
		temp->InsertItem(0, buff);
		temp->SetItemText(0, 1, szClass);
		temp->SetItemText(0, 2, szPath);
	}
	return TRUE;
}

CPROCDLG5::CPROCDLG5(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROCDLG5, pParent)
{

}

CPROCDLG5::~CPROCDLG5()
{
}
void CPROCDLG5::EnumW()
{
	EnumWindows(EnumWinProc, LPARAM(&m_ListWin));
}


void CPROCDLG5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_ListWin);
}


BEGIN_MESSAGE_MAP(CPROCDLG5, CDialogEx)
END_MESSAGE_MAP()


// CPROCDLG5 ��Ϣ�������


BOOL CPROCDLG5::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
