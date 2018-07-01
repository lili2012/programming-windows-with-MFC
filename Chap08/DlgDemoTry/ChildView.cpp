
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "DlgDemoTry.h"
#include "ChildView.h"
#include "OptionsDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_width = 4;
	m_height = 2;
	m_units = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_OPTION, &CChildView::OnFileOption)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CBrush brush(RGB(255, 0, 255));
	CBrush* pOldBrush = dc.SelectObject(&brush);

	switch (m_units) {

	case 0: // Inches
		dc.SetMapMode(MM_LOENGLISH);
		dc.Rectangle(0, 0, m_width * 100, -m_height* 100);
		break;

	case 1: // Centimeters
		dc.SetMapMode(MM_LOMETRIC);
		dc.Rectangle(0, 0, m_width * 100, -m_height * 100);
		break;

	case 2: // Pixels
		dc.SetMapMode(MM_TEXT);
		dc.Rectangle(0, 0, m_width, m_height);
		break;
	}
	dc.SelectObject(pOldBrush);
}



void CChildView::OnFileOption()
{
	COptionsDialog dlg;

	dlg.m_width = m_width;
	dlg.m_height = m_height;
	dlg.m_units = m_units;

	if (dlg.DoModal() == IDOK) {
		m_width = dlg.m_width;
		m_height = dlg.m_height;
		m_units = dlg.m_units;
		Invalidate();
	}
}
