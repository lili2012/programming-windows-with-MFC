
// MySqiView.cpp : implementation of the CMySqiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MySqi.h"
#endif

#include "MySqiDoc.h"
#include "MySqiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMySqiView

IMPLEMENT_DYNCREATE(CMySqiView, CView)

BEGIN_MESSAGE_MAP(CMySqiView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMySqiView construction/destruction

CMySqiView::CMySqiView()
{
	// TODO: add construction code here

}

CMySqiView::~CMySqiView()
{
}

BOOL CMySqiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMySqiView drawing

void CMySqiView::OnDraw(CDC* /*pDC*/)
{
	CMySqiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CMySqiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMySqiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMySqiView diagnostics

#ifdef _DEBUG
void CMySqiView::AssertValid() const
{
	CView::AssertValid();
}

void CMySqiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySqiDoc* CMySqiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySqiDoc)));
	return (CMySqiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySqiView message handlers
