
// DemoHyperLPR-mfc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDemoHyperLPRmfcApp: 
// �йش����ʵ�֣������ DemoHyperLPR-mfc.cpp
//

class CDemoHyperLPRmfcApp : public CWinApp
{
public:
	CDemoHyperLPRmfcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDemoHyperLPRmfcApp theApp;