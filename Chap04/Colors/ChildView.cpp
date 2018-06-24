// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Colors.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
	m_nShape = 1; // Triangle
	m_nColor = 0; // Red
}

CChildView::~CChildView()
{
}

// BEGIN_MESSAGE_MAP(CChildView,CWnd )
// 	//{{AFX_MSG_MAP(CChildView)
// 	ON_WM_PAINT()
// 	ON_COMMAND(ID_SHAPE_CIRCLE, OnShapeCircle)
// 	ON_COMMAND(ID_SHAPE_TRIANGLE, OnShapeTriangle)
// 	ON_COMMAND(ID_SHAPE_SQUARE, OnShapeSquare)
// 	ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, OnUpdateShapeCircle)
// 	ON_UPDATE_COMMAND_UI(ID_SHAPE_TRIANGLE, OnUpdateShapeTriangle)
// 	ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, OnUpdateShapeSquare)
// 	ON_WM_CONTEXTMENU()
// 	//}}AFX_MSG_MAP
// 	//begin command_range
// 	ON_COMMAND_RANGE (ID_COLOR_RED, ID_COLOR_BLUE, OnColor)
// 	//end comand_range
// 	ON_UPDATE_COMMAND_UI_RANGE (ID_COLOR_RED, ID_COLOR_BLUE, OnUpdateColor)
// END_MESSAGE_MAP()
__pragma(warning(push))
__pragma(warning(disable : 4867))
const AFX_MSGMAP* CChildView::GetMessageMap() const
{
	return GetThisMessageMap();
}

const AFX_MSGMAP* __stdcall CChildView::GetThisMessageMap() {
	typedef CChildView ThisClass; 
	typedef CWnd TheBaseClass; 
	static const AFX_MSGMAP_ENTRY _messageEntries[] = 
	{
		//{{AFX_MSG_MAP(CChildView)
		{ 0x000F, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW)(static_cast<void (CWnd::*)(void)> (&ThisClass::OnPaint)) },
		{ 0x0111, 0, (WORD)32771, (WORD)32771, AfxSigCmd_v, static_cast<AFX_PMSG> (OnShapeCircle) },
		{ 0x0111, 0, (WORD)32772, (WORD)32772, AfxSigCmd_v, static_cast<AFX_PMSG> (OnShapeTriangle) },
		{ 0x0111, 0, (WORD)32773, (WORD)32773, AfxSigCmd_v, static_cast<AFX_PMSG> (OnShapeSquare) },
		{ 0x0111, ((UINT)(-1)), (WORD)32771, (WORD)32771, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateShapeCircle)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32772, (WORD)32772, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateShapeTriangle)) },
		{ 0x0111, ((UINT)(-1)), (WORD)32773, (WORD)32773, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateShapeSquare)) },
		{ 0x007B, 0, 0, 0, AfxSig_vWp, (AFX_PMSG)(AFX_PMSGW)(static_cast<void (CWnd::*)(CWnd*, CPoint)> (&ThisClass::OnContextMenu)) },
		//}}AFX_MSG_MAP
		//begin command_range
		{ 0x0111, 0, (WORD)32774, (WORD)32778, AfxSigCmd_RANGE, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(UINT)> (OnColor)) },
		//end comand_range
		{ 0x0111, ((UINT)(-1)), (WORD)32774, (WORD)32778, AfxSigCmdUI, (AFX_PMSG)(static_cast<void (CCmdTarget::*)(CCmdUI*)> (OnUpdateColor)) },
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } 
	}; 
	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; 
	return &messageMap;
} __pragma(warning(pop))

const COLORREF CChildView::m_clrColors[5] = {
	RGB(255, 0, 0), // Red
	RGB(255, 255, 0), // Yellow
	RGB(0, 255, 0), // Green
	RGB(0, 255, 255), // Cyan
	RGB(0, 0, 255)  // Blue
};

/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	//cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPoint points[3];
	CPaintDC dc(this);

	CRect rcClient;
	GetClientRect(&rcClient);

	int cx = rcClient.Width() / 2;
	int cy = rcClient.Height() / 2;
	CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);

	CBrush brush(m_clrColors[m_nColor]);
	CBrush* pOldBrush = dc.SelectObject(&brush);

	switch (m_nShape) {

	case 0: // Circle
		dc.Ellipse(rcShape);
		break;

	case 1: // Triangle
		points[0].x = cx - 45;
		points[0].y = cy + 45;
		points[1].x = cx;
		points[1].y = cy - 45;
		points[2].x = cx + 45;
		points[2].y = cy + 45;
		dc.Polygon(points, 3);
		break;

	case 2: // Square
		dc.Rectangle(rcShape);
		break;
	}
	dc.SelectObject(pOldBrush);
}

void CChildView::OnShapeCircle()
{
	m_nShape = 0;
	Invalidate();
}

void CChildView::OnShapeTriangle()
{
	m_nShape = 1;
	Invalidate();
}

void CChildView::OnShapeSquare()
{
	m_nShape = 2;
	Invalidate();
}

void CChildView::OnUpdateShapeCircle(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nShape == 0);
}

void CChildView::OnUpdateShapeTriangle(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nShape == 1);
}

void CChildView::OnUpdateShapeSquare(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nShape == 2);
}

void CChildView::OnColor(UINT nID)
{
	m_nColor = nID - ID_COLOR_RED;
	Invalidate();
}

void CChildView::OnUpdateColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck((int)pCmdUI->m_nID - ID_COLOR_RED == m_nColor);
	static int i = 0;
	i++;
	if (i>10)
		pCmdUI->SetCheck(TRUE); 
}

void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	int cx = rcClient.Width() / 2;
	int cy = rcClient.Height() / 2;
	CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);

	CPoint pos = point;
	ScreenToClient(&pos);

	CPoint points[3];
	BOOL bShapeClicked = FALSE;
	int dx, dy;

	//
	// Hit test the shape.
	//
	switch (m_nShape) {

	case 0: // Circle
		dx = pos.x - cx;
		dy = pos.y - cy;
		if ((dx * dx) + (dy * dy) <= (45 * 45))
			bShapeClicked = TRUE;
		break;

	case 1: // Triangle
		if (rcShape.PtInRect(pos)) {
			dx = min(pos.x - rcShape.left, rcShape.right - pos.x);
			if ((rcShape.bottom - pos.y) < (2 * dx))
				bShapeClicked = TRUE;
		}
		break;

	case 2: // Square
		if (rcShape.PtInRect(pos))
			bShapeClicked = TRUE;
		break;
	}

	//
	// Display a context menu if the shape was clicked.
	//
	if (bShapeClicked) {
		CMenu menu;
		menu.LoadMenu(IDR_CONTEXTMENU);
		CMenu* pContextMenu = menu.GetSubMenu(0);

		for (int i = 0; i < 5; i++)
			pContextMenu->ModifyMenu(ID_COLOR_RED + i,
			MF_BYCOMMAND | MF_OWNERDRAW, ID_COLOR_RED + i);

		pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON |
			TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
		return;
	}

	//
	// Call the base class if the shape was not clicked.
	//
	CWnd::OnContextMenu(pWnd, point);
}
