
// DlgDemoTry.h : main header file for the DlgDemoTry application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDlgDemoTryApp:
// See DlgDemoTry.cpp for the implementation of this class
//

class CDlgDemoTryApp : public CWinApp
{
public:
	CDlgDemoTryApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDlgDemoTryApp theApp;
