// PROCDLG4.cpp : 实现文件
//

#include "stdafx.h"
#include "taskmgr.h"
#include "PROCDLG4.h"
#include "afxdialogex.h"



// CPROCDLG4 对话框

IMPLEMENT_DYNAMIC(CPROCDLG4, CDialogEx)

CPROCDLG4::CPROCDLG4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROCDLG4, pParent)
{

}

CPROCDLG4::~CPROCDLG4()
{
}

BOOL CPROCDLG4::EnumHeap(int PID)
{
	HANDLE hHeapSnap = CreateToolhelp32Snapshot(TH32CS_SNAPHEAPLIST,PID);
	HEAPLIST32 hlsi = { sizeof(HEAPLIST32) };
	HEAPENTRY32 hsi = { sizeof(HEAPENTRY32) };
	TCHAR item[4][MAX_PATH];
	if (INVALID_HANDLE_VALUE == hHeapSnap)
		return FALSE;
	if (!Heap32ListFirst(hHeapSnap,&hlsi))
	{
		MessageBox(L"Heap32First error!", L"警告", MB_ICONWARNING);
		return FALSE;
	}
	do
	{
		//print heap list info  
		if (!Heap32First(&hsi,PID,hlsi.th32HeapID))
		{
			continue;
		}
		do
		{
			//print heap info  
			_stprintf_s(item[0], MAX_PATH, L"%d"  , hsi.th32HeapID);
			_stprintf_s(item[1], MAX_PATH, L"%d", hsi.th32ProcessID);
			_stprintf_s(item[2], MAX_PATH, L"%08X", hsi.dwAddress);
			_stprintf_s(item[3], MAX_PATH, L"%d", hsi.dwBlockSize);
			//_stprintf_s(item[3], MAX_PATH, L"%d", );
			m_ListHeap.AddItem(0, 4, item[0], item[1], item[2], item[3]);
			//here u can use ToolhelpReadProcessMemory  or other api to read other process memory.  
			HEAPENTRY32 hsi = { sizeof(HEAPENTRY32) };
		} while (Heap32Next(&hsi));
	} while (Heap32ListNext(hHeapSnap,&hlsi));
	CloseHandle(hHeapSnap);
}

void CPROCDLG4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_ListHeap);
}


BEGIN_MESSAGE_MAP(CPROCDLG4, CDialogEx)
END_MESSAGE_MAP()


// CPROCDLG4 消息处理程序

