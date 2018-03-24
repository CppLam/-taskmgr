// PROCDLG3.cpp : 实现文件
//

#include "stdafx.h"
#include "taskmgr.h"
#include "PROCDLG3.h"
#include "afxdialogex.h"
#include <Psapi.h>

// CPROCDLG3 对话框

IMPLEMENT_DYNAMIC(CPROCDLG3, CDialogEx)

CPROCDLG3::CPROCDLG3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROCDLG3, pParent)
{

}

CPROCDLG3::~CPROCDLG3()
{
}

void CPROCDLG3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListModule);
}

BOOL CPROCDLG3::EnumModule(int PID)
{
	HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
	//if (hModuleSnap == INVALID_HANDLE_VALUE)
	//{
	//	MessageBox(L"快照错误！", L"警告", MB_ICONWARNING);
	//	return FALSE;
	//}
	//MODULEENTRY32 msi = { sizeof(MODULEENTRY32) };
	//if (!Module32First(hModuleSnap, &msi))
	//{
	//	MessageBox(L"Thread32First error!", L"警告", MB_ICONWARNING);
	//	return FALSE;
	//}
	//int i = 0;
	//TCHAR item2[8],item4[32];
	//
	//do
	//{
	//	//_stprintf_s(item1, 8, L"%d", msi.szModule);
	//	_stprintf_s(item2, 8, L"%d", msi.th32ProcessID);
	//	//_stprintf_s(item3, 8, L"%d", msi.szExePath);
	//	_stprintf_s(item4, 8, L"%d", msi.modBaseSize);
	//	if (msi.th32ProcessID == PID)
	//		m_ListModule.AddItem(i, 4, msi.szModule, item2, msi.szExePath, item4);
	//} while (Module32Next(hModuleSnap, &msi));
	/**********************************************************/
	HANDLE hProcess = NULL;
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, PID);
	HMODULE hModules[0x2000] = {};//只用于获取模块句柄个数
	DWORD dwNeed = 0;//模块句柄个数
	EnumProcessModules(hProcess, hModules, sizeof(hModules), &dwNeed);
	DWORD dwModuleCount = dwNeed / sizeof(HMODULE);
	TCHAR item[4][MAX_PATH];
	MODULEINFO moif = { 0 };
	for (SIZE_T i = 0; i < dwModuleCount; ++i)
	{
		//根据进程句柄和模块句柄获取模块路径
		GetModuleFileNameEx(hProcess, hModules[i], item[2], MAX_PATH);
		GetModuleInformation(hProcess, hModules[i], &moif, sizeof(MODULEINFO));
		GetModuleBaseName(hProcess, hModules[i], item[0], MAX_PATH);
		_stprintf_s(item[1], MAX_PATH, L"%d", PID);
		_stprintf_s(item[3], MAX_PATH, L"%d", moif.SizeOfImage);
		m_ListModule.AddItem(i, 4, item[0], item[1], item[2], item[3]);
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CPROCDLG3, CDialogEx)
END_MESSAGE_MAP()


// CPROCDLG3 消息处理程序
