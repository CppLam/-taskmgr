// MyList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "MyList.h"


// CMyList

IMPLEMENT_DYNAMIC(CMyList, CListCtrl)

CMyList::CMyList()
{

}

CMyList::~CMyList()
{
}
//�Զ��������
void CMyList::AddColumn(int nNum, ...)
{
	SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	va_list vlist;
	va_start(vlist, nNum);
	for (int i = 0; i < nNum; ++i)
	{
		TCHAR* pName = va_arg(vlist, TCHAR*);
		int nWidth = 50 * _tcslen(pName);
		InsertColumn(i, pName, NULL, nWidth);
	}
	va_end(vlist);
}
//�Զ��������
void CMyList::AddItem(int nItemNum, int nCount, ...)
{
	va_list vlist;
	va_start(vlist, nCount);
	TCHAR* pText = va_arg(vlist, TCHAR*);
	InsertItem(nItemNum, pText);
	for (int i = 1; i < nCount; ++i)
	{
		pText = va_arg(vlist, TCHAR*);
		SetItemText(nItemNum, i, pText);
	}
}

BEGIN_MESSAGE_MAP(CMyList, CListCtrl)
//	ON_COMMAND(IDC_BUTTON1, &CMyList::OnButton1)
//ON_COMMAND(IDC_BUTTON1, &CMyList::OnButton1)
END_MESSAGE_MAP()



// CMyList ��Ϣ�������


//void CMyList::OnButton1()
//{
//	// TODO: �ڴ���������������
//	// TODO: Add your control notification handler code here  
//	
//
//}
