
// taskmgr.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <Tlhelp32.h>

// CtaskmgrApp: 
// �йش����ʵ�֣������ taskmgr.cpp
//

class CtaskmgrApp : public CWinApp
{
public:
	CtaskmgrApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtaskmgrApp theApp;