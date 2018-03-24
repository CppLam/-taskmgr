
// taskmgrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "taskmgr.h"
#include "taskmgrDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
//	afx_msg LRESULT OnPidm(WPARAM wParam, LPARAM lParam);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_MESSAGE(WM_PIDM, &CAboutDlg::OnPidm)
END_MESSAGE_MAP()


// CtaskmgrDlg 对话框



CtaskmgrDlg::CtaskmgrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TASKMGR_DIALOG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtaskmgrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_CPU);
	m_CPU.SetRange(0, 100);
	m_CPU.SetPos(50);
	SetTimer(1, 100, NULL);
}

BEGIN_MESSAGE_MAP(CtaskmgrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CtaskmgrDlg::On32771)
	ON_MESSAGE(WM_TURN1, &CtaskmgrDlg::OnTurn1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CtaskmgrDlg 消息处理程序

BOOL CtaskmgrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	m_DiaProc.Create(IDD_CDIAPROC, this);
	m_DiaFile.Create(IDD_CDIAFILE, this);
	m_DiaProc.ShowWindow(SW_SHOW);
	m_DiaFile.ShowWindow(SW_HIDE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
//////////////////////////////////////////////////////////////////////////
void CtaskmgrDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtaskmgrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtaskmgrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//关于页查看
void CtaskmgrDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg Dlg;
	Dlg.DoModal();
}

//用于切换模式
afx_msg LRESULT CtaskmgrDlg::OnTurn1(WPARAM wParam, LPARAM lParam)
{
	if (wParam)
	{
		m_DiaProc.ShowWindow(SW_HIDE);
		m_DiaFile.ShowWindow(SW_SHOW);
	}
	else
	{
		m_DiaProc.ShowWindow(SW_SHOW);
		m_DiaFile.ShowWindow(SW_HIDE);
	}
	return 0;
}


//afx_msg LRESULT CAboutDlg::OnPidm(WPARAM wParam, LPARAM lParam)
//{
//	return 0;
//}

double FILETIME2Double(const _FILETIME& fileTime) {
	return double(fileTime.dwHighDateTime*4.294967296e9) + double(fileTime.dwLowDateTime);
}
void CtaskmgrDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnTimer(nIDEvent);
	//		  空闲时间	内核时间	用户时间
	_FILETIME idleTime, kernelTime, userTime;
	//获取时间
	GetSystemTimes(&idleTime, &kernelTime, &userTime);
	HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	WaitForSingleObject(hEvent, 100);
	_FILETIME newIdleTime, newKernelTime, newUserTime;
	GetSystemTimes(&newIdleTime, &newKernelTime, &newUserTime);
	double dOleIdleTime = FILETIME2Double(idleTime);
	double dNewIdleTime = FILETIME2Double(newIdleTime);
	double dOleKernelTime = FILETIME2Double(kernelTime);
	double dNewKernelTime = FILETIME2Double(newKernelTime);
	double dOleUserTime = FILETIME2Double(userTime);
	double dNewUserTime = FILETIME2Double(newUserTime);
	m_dwCPU = int(100.0 - (dNewIdleTime - dOleIdleTime) 
		/ (dNewKernelTime - dOleKernelTime + dNewUserTime - dOleUserTime)*100.0);
	m_CPU.SetPos(m_dwCPU);
}

