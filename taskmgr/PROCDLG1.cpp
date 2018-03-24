// PROCDLG1.cpp : 实现文件
//

#include "stdafx.h"
#include "taskmgr.h"
#include "PROCDLG1.h"
#include "afxdialogex.h"



// CPROCDLG1 对话框

IMPLEMENT_DYNAMIC(CPROCDLG1, CDialogEx)

CPROCDLG1::CPROCDLG1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROCDLG1, pParent)
{

}

CPROCDLG1::~CPROCDLG1()
{
}

void CPROCDLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_MYLIST, m_ListProc);
}


BEGIN_MESSAGE_MAP(CPROCDLG1, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDD_MYLIST, &CPROCDLG1::OnNMClickMylist)
END_MESSAGE_MAP()


// CPROCDLG1 消息处理程序


BOOL CPROCDLG1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
BOOL CPROCDLG1::EnumProc()
{
	HANDLE hProSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (hProSnap == INVALID_HANDLE_VALUE)
	{
		MessageBox(L"快照错误！", L"警告", MB_ICONWARNING);
		return FALSE;
	}
	PROCESSENTRY32W psi = { sizeof(PROCESSENTRY32W) };
	if (!Process32First(hProSnap, &psi))
	{
		MessageBox(L"Process32FirstW error!", L"警告", MB_ICONWARNING);
		return FALSE;
	}
	int i = 0;
	TCHAR* item1 = psi.szExeFile;
	TCHAR item2[8], item3[8],item4[8];
	
	do
	{
		_stprintf_s(item2, 8, L"%d", psi.th32ProcessID);
		//GetParent()->SendMessage(WM_PIDM, psi.th32ProcessID, NULL);
		_stprintf_s(item3, 8, L"%d", psi.th32ParentProcessID);
		_stprintf_s(item4, 8, L"%d", psi.cntThreads);
		m_ListProc.AddItem(i, 4, item1, item2, item3 , item4);
	} while (Process32NextW(hProSnap, &psi));
	CloseHandle(hProSnap);
	return TRUE;
}


void CPROCDLG1::OnNMClickMylist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_ListProc.UpdateData(TRUE);
	m_ListProc.m_nItem = m_ListProc.GetSelectionMark();
	m_ListProc.UpdateData(FALSE);
	*pResult = 0;
}
