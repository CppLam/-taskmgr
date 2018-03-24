
// taskmgrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "taskmgr.h"
#include "taskmgrDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CtaskmgrDlg �Ի���



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


// CtaskmgrDlg ��Ϣ�������

BOOL CtaskmgrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	m_DiaProc.Create(IDD_CDIAPROC, this);
	m_DiaFile.Create(IDD_CDIAFILE, this);
	m_DiaProc.ShowWindow(SW_SHOW);
	m_DiaFile.ShowWindow(SW_HIDE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtaskmgrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtaskmgrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//����ҳ�鿴
void CtaskmgrDlg::On32771()
{
	// TODO: �ڴ���������������
	CAboutDlg Dlg;
	Dlg.DoModal();
}

//�����л�ģʽ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnTimer(nIDEvent);
	//		  ����ʱ��	�ں�ʱ��	�û�ʱ��
	_FILETIME idleTime, kernelTime, userTime;
	//��ȡʱ��
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

