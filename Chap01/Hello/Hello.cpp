#include <afxwin.h>

#include "Hello.h"

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();// 调用第一个UpdateWindow函数给窗口发送第一个WM_PAINT消息
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

// BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
//     ON_WM_PAINT () //WM_PAINT 消息通过MFC的消息映射机制转换为对CMainWindow：：OnPaint函数的调用
// END_MESSAGE_MAP ()
__pragma(warning(push))
__pragma(warning(disable : 4867))
const AFX_MSGMAP* CMainWindow::GetMessageMap() const
{
	return GetThisMessageMap();
}
const AFX_MSGMAP* __stdcall CMainWindow::GetThisMessageMap() {
	typedef CMainWindow ThisClass;
	typedef CFrameWnd TheBaseClass;
	static const AFX_MSGMAP_ENTRY _messageEntries[] =
	{
		{ 0x000F, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW)(static_cast<void (CWnd::*)(void)> (&ThisClass::OnPaint)) },
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
	};
	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
	return &messageMap;
}
__pragma(warning(pop))


CMainWindow::CMainWindow()
{
	Create(NULL, _T("The Hello Application"), WS_OVERLAPPEDWINDOW);
}
#include <math.h>
#define SEGMENTS 500
#define PI 3.1415926

void CMainWindow::OnPaint()
{
	/*
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	dc.DrawText(_T("Hello, MFC"), -1, &rect,
	DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	*/
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));


	CRect rect;
	GetClientRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();
	CPaintDC dc(this);
	dc.SelectObject(pen);
	CPoint aPoint[SEGMENTS];
	for (int i = 0; i < SEGMENTS; i++) {
		aPoint[i].x = (i * nWidth) / SEGMENTS;
		aPoint[i].y = (int)((nHeight / 2) *
			(1 - (sin((2 * PI * i) / SEGMENTS))));
	}
	dc.Polyline(aPoint, SEGMENTS);

}
