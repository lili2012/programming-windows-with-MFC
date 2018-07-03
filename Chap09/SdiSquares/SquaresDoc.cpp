// SquaresDoc.cpp : implementation of the CSquaresDoc class
//

#include "stdafx.h"
#include "SdiSquares.h"

#include "SquaresDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSquaresDoc

IMPLEMENT_DYNCREATE(CSquaresDoc, CDocument)
/*
BEGIN_MESSAGE_MAP(CSquaresDoc, CDocument)//为什么他能把message route 到这里来呢？
	//{{AFX_MSG_MAP(CSquaresDoc)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_YELLOW, OnColorYellow)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_CYAN, OnColorCyan)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_WHITE, OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, OnUpdateColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN, OnUpdateColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, OnUpdateColorWhite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
*/
__pragma(warning(push))
__pragma(warning(disable : 4867))
const AFX_MSGMAP* CSquaresDoc::GetMessageMap() const
{
	return GetThisMessageMap();
}
const AFX_MSGMAP* __stdcall CSquaresDoc::GetThisMessageMap() {
	typedef CSquaresDoc ThisClass;
	typedef CDocument TheBaseClass;
	static const AFX_MSGMAP_ENTRY _messageEntries[] = {
		{ 0x0111, 0, (WORD)32771, (WORD)32771, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorRed) },
		{ 0x0111, 0, (WORD)32772, (WORD)32772, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorYellow) },
		{ 0x0111, 0, (WORD)32773, (WORD)32773, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorGreen) },
		{ 0x0111, 0, (WORD)32774, (WORD)32774, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorCyan) },
		{ 0x0111, 0, (WORD)32775, (WORD)32775, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorBlue) },
		{ 0x0111, 0, (WORD)32776, (WORD)32776, AfxSigCmd_v, static_cast<AFX_PMSG> (OnColorWhite) },
		{ 0x0111, ((UINT)(-1)), (WORD)32771, (WORD)32771, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorRed)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32772, (WORD)32772, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorYellow)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32773, (WORD)32773, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorGreen)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32774, (WORD)32774, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorCyan)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32775, (WORD)32775, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorBlue)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32776, (WORD)32776, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColorWhite)) },
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
	};

	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
	return &messageMap;
}
__pragma(warning(pop))

/////////////////////////////////////////////////////////////////////////////
// CSquaresDoc construction/destruction

CSquaresDoc::CSquaresDoc()
{
	// TODO: add one-time construction code here

}

CSquaresDoc::~CSquaresDoc()
{
}

BOOL CSquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_clrGrid[i][j] = RGB(255, 255, 255);

	m_clrCurrentColor = RGB(255, 0, 0);
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSquaresDoc serialization

void CSquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				ar << m_clrGrid[i][j];
		ar << m_clrCurrentColor;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				ar >> m_clrGrid[i][j];
		ar >> m_clrCurrentColor;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSquaresDoc diagnostics

#ifdef _DEBUG
void CSquaresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSquaresDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSquaresDoc commands

COLORREF CSquaresDoc::GetCurrentColor()
{
	return m_clrCurrentColor;
}

COLORREF CSquaresDoc::GetSquare(int i, int j)
{
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	return m_clrGrid[i][j];
}

void CSquaresDoc::SetSquare(int i, int j, COLORREF color)
{
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}

void CSquaresDoc::OnColorRed()
{
	m_clrCurrentColor = RGB(255, 0, 0);
}

void CSquaresDoc::OnColorYellow()
{
	m_clrCurrentColor = RGB(255, 255, 0);
}

void CSquaresDoc::OnColorGreen()
{
	m_clrCurrentColor = RGB(0, 255, 0);
}

void CSquaresDoc::OnColorCyan()
{
	m_clrCurrentColor = RGB(0, 255, 255);
}

void CSquaresDoc::OnColorBlue()
{
	m_clrCurrentColor = RGB(0, 0, 255);
}

void CSquaresDoc::OnColorWhite()
{
	m_clrCurrentColor = RGB(255, 255, 255);
}

void CSquaresDoc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 0, 0));
}

void CSquaresDoc::OnUpdateColorYellow(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 255, 0));
}

void CSquaresDoc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 255, 0));
}

void CSquaresDoc::OnUpdateColorCyan(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 255, 255));
}

void CSquaresDoc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 0, 255));
}

void CSquaresDoc::OnUpdateColorWhite(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 255, 255));
}
