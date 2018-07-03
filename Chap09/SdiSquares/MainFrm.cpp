// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SdiSquares.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
static char THIS_FILE[] = "c:\\users\\shuya\\desktop\\programming-windows-with-mfc\\chap09\\sdisquares\\mainfrm.cpp";
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

//IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

CObject* __stdcall CMainFrame::CreateObject()
{
	return new CMainFrame;
}

CRuntimeClass* __stdcall CMainFrame::_GetBaseClass()
{
	return (CFrameWnd::GetThisClass());
}
__declspec(selectany) const CRuntimeClass CMainFrame::classCMainFrame =
{ "CMainFrame", sizeof(class CMainFrame), 0xFFFF, CMainFrame::CreateObject, &CMainFrame::_GetBaseClass, 0, 0 };

CRuntimeClass* __stdcall CMainFrame::GetThisClass()
{
	return ((CRuntimeClass*)(&CMainFrame::classCMainFrame));
}

CRuntimeClass* CMainFrame::GetRuntimeClass() const
{
	return ((CRuntimeClass*)(&CMainFrame::classCMainFrame));
}
/*
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	// NOTE - the ClassWizard will add and remove mapping macros here.
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
*/
__pragma(warning(push))
__pragma(warning(disable : 4867))
const AFX_MSGMAP* CMainFrame::GetMessageMap() const
{
	return GetThisMessageMap();
}
const AFX_MSGMAP* __stdcall CMainFrame::GetThisMessageMap() {
	typedef CMainFrame ThisClass;
	typedef CFrameWnd TheBaseClass;
	static const AFX_MSGMAP_ENTRY _messageEntries[] = {
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
	};
	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
	return &messageMap;
}
__pragma(warning(pop))

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here

}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

