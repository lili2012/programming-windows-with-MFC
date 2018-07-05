
// MySqi.h : main header file for the MySqi application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMySqiApp:
// See MySqi.cpp for the implementation of this class
//

class CMySqiApp : public CWinAppEx
{
public:
	CMySqiApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMySqiApp theApp;
