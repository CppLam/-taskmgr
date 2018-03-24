// DIAFILE.cpp : 实现文件
//

#include "stdafx.h"
#include "taskmgr.h"
#include "DIAFILE.h"
#include "afxdialogex.h"


// CDIAFILE 对话框

IMPLEMENT_DYNAMIC(CDIAFILE, CDialogEx)

CDIAFILE::CDIAFILE(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CDIAFILE, pParent)
	, m_B1(FALSE)
	, m_B2(FALSE)
	, m_B3(FALSE)
	, m_B4(FALSE)
	, m_B5(FALSE)
	, m_B6(FALSE)
	, m_Path(_T(""))
	, m_B7(FALSE)
{

}

CDIAFILE::~CDIAFILE()
{
}

void CDIAFILE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_FileTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_FileList);
	DDX_Check(pDX, IDC_CHECK1, m_B1);
	DDX_Check(pDX, IDC_CHECK2, m_B2);
	DDX_Check(pDX, IDC_CHECK3, m_B3);
	DDX_Check(pDX, IDC_CHECK4, m_B4);
	DDX_Check(pDX, IDC_CHECK5, m_B5);
	DDX_Check(pDX, IDC_CHECK6, m_B6);
	DDX_Text(pDX, IDC_EDIT1, m_Path);
	DDX_Check(pDX, IDC_CHECK7, m_B7);
	DDX_Check(pDX, IDC_CHECK8, m_BC);
}


BEGIN_MESSAGE_MAP(CDIAFILE, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDIAFILE::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_MFCSHELLTREE1, &CDIAFILE::OnNMDblclkMfcshelltree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MFCSHELLTREE1, &CDIAFILE::OnTvnSelchangedMfcshelltree1)
	ON_BN_CLICKED(IDCANCEL, &CDIAFILE::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK1, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK2, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK3, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK4, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK5, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK6, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK7, &CDIAFILE::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_CHECK8, &CDIAFILE::OnBnClickedCheck8)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_MFCSHELLLIST1, &CDIAFILE::OnLvnColumnclickMfcshelllist1)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &CDIAFILE::OnNMClickMfcshelllist1)
END_MESSAGE_MAP()


// CDIAFILE 消息处理程序


void CDIAFILE::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	GetParent()->SendMessage(WM_TURN1, 0, 0);
}


BOOL CDIAFILE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_FileTree.SetRelatedList(&m_FileList);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDIAFILE::SetTextPath()
{
	UpdateData(TRUE);
	m_FileList.GetCurrentFolder(m_Path);
	UpdateData(FALSE);
}



void CDIAFILE::OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	SetTextPath();
	*pResult = 0;
}


void CDIAFILE::OnTvnSelchangedMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	SetTextPath();
	*pResult = 0;
}


void CDIAFILE::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
	UpdateData(TRUE);
	if(CleanFile(m_Path.GetBuffer()))
		MessageBox(L"清理成功",L"消息",MB_OK);
	else
		MessageBox(L"清理失败", L"消息", MB_OK);
	m_FileList.Refresh();
	UpdateData(FALSE);

}
BOOL CDIAFILE::CleanFile(CString path)
{
	CString FileName = path;
	FileName += "\\*.*";
	WIN32_FIND_DATA wsd = {};
	HANDLE hFile = FindFirstFile(FileName.GetBuffer(), &wsd);
	if (hFile == INVALID_HANDLE_VALUE)return FALSE;
	do
	{
		if ('.' == wsd.cFileName[0])continue;
		if (wsd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			CString tNew = path;
			tNew += "\\";
			tNew += wsd.cFileName;
			if (!_tcscmp(wsd.cFileName, L"Debug") && m_B5 || !_tcscmp(wsd.cFileName, L"ipch") && m_B7
				|| !_tcscmp(wsd.cFileName, L"Release") && m_B6)
			{
				SHFILEOPSTRUCT FileOp = {};
				FileOp.fFlags = FOF_NOCONFIRMATION;
				tNew += '\0';
				FileOp.pFrom = tNew;
				FileOp.wFunc = FO_DELETE;
				SHFileOperation(&FileOp);
			}
			CleanFile(tNew);
		}
		else
		{
			TCHAR* FileExten = PathFindExtension(wsd.cFileName);
			if (!_tcscmp(FileExten, L".db") && m_B1 || !_tcscmp(FileExten, L".filters") && m_B2
				|| !_tcscmp(FileExten, L".lik") && m_B3 || !_tcscmp(FileExten, L".pdb") && m_B4)
			{
				CString delFile = path;
				delFile += "\\";
				delFile += wsd.cFileName;
				_tremove(delFile.GetBuffer());
			}
		}
	} while (FindNextFile(hFile, &wsd));
	return TRUE;
}




void CDIAFILE::OnBnClickedCheck8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);	
	m_B1 = m_BC;
	m_B2 = m_BC;
	m_B3 = m_BC;
	m_B4 = m_BC;
	m_B5 = m_BC;
	m_B6 = m_BC;
	m_B7 = m_BC;
	UpdateData(FALSE);
}

void CDIAFILE::OnBnClickedCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_BC = 2;
	m_BC = 2;
	m_BC = 2;
	m_BC = 2;
	m_BC = 2;
	m_BC = 2;
	m_BC = 2;
	UpdateData(FALSE);
}


void CDIAFILE::OnLvnColumnclickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	SetTextPath();
	*pResult = 0;
}


void CDIAFILE::OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int FItem = pNMItemActivate->iItem;
	CString temp = m_FileList.GetItemText(FItem, 0);
	m_FileList.GetCurrentFolder(m_Path);
	m_Path += "\\";
	m_Path += temp;
	UpdateData(FALSE);
	*pResult = 0;
}
