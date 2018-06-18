#include <afxwin.h>
#include "Ruler.h"

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

const double RULER_WIDTH = 12;//12 inch
const double RULER_HEIGHT = 1;// 1 inch
const double MARGIN_X = 0.5;//1 inch
const double MARGIN_Y = 1;//1 inch
const int MAPPING_MODE = MM_LOENGLISH;
const int INCH_LOUNIT = 100;//1 inch is 100 logical unit
const CPoint VISUAL_SPACE_LO(static_cast<int>((MARGIN_X * 2 + RULER_WIDTH)*INCH_LOUNIT), static_cast<int>(-(MARGIN_Y * 2 + RULER_HEIGHT)*INCH_LOUNIT));//visual space in logical unit

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(NULL, _T("Ruler"), WS_OVERLAPPEDWINDOW | WS_HSCROLL);

}

void CMainWindow::OnSize(UINT nType, int cx, int cy)
{
	CClientDC dc(this);
	dc.SetMapMode(MAPPING_MODE);
	m_VISUAL_SPACE_DE = VISUAL_SPACE_LO;
	dc.LPtoDP(&m_VISUAL_SPACE_DE);
	SCROLLINFO si;
	si.fMask = SIF_ALL;
	si.nMin = 0;
	si.nMax = m_VISUAL_SPACE_DE.x;
	si.nPage = cx;
	si.nPos = 0;
	//SetScrollInfo(SB_VERT, &si, TRUE);
	SetScrollInfo(SB_HORZ, &si, TRUE);
}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);

	//
	// Initialize the device context.
	//
	dc.SetMapMode(MAPPING_MODE);
	dc.SetTextAlign(TA_CENTER | TA_BOTTOM);
	dc.SetBkMode(TRANSPARENT);

	//
	// Draw the body of the ruler.
	//
	CBrush brush(RGB(255, 255, 0));
	CBrush* pOldBrush = dc.SelectObject(&brush);

	m_VISUAL_SPACE_DE = VISUAL_SPACE_LO;
	dc.LPtoDP(&m_VISUAL_SPACE_DE);


	dc.Rectangle(static_cast<int>(MARGIN_X*INCH_LOUNIT), static_cast<int>(-MARGIN_Y*INCH_LOUNIT), static_cast<int>((MARGIN_X + RULER_WIDTH)*INCH_LOUNIT), static_cast<int>(-(MARGIN_Y + RULER_HEIGHT)*INCH_LOUNIT));
	dc.SelectObject(pOldBrush);

	//
	// Draw the tick marks and labels.
	//
	double SPACE = 0.25;//0.25 inch
	//const int SPACE_LO = SPACE*INCH_LOUNIT;
	for (int i = static_cast<int>((MARGIN_X + SPACE)*INCH_LOUNIT); i < static_cast<int>((MARGIN_X + RULER_WIDTH)*INCH_LOUNIT); i += static_cast<int>(SPACE*INCH_LOUNIT))
	{
		dc.MoveTo(i, -192);
		dc.LineTo(i, -200);
	}

	SPACE = 0.5;//0.5 inch
	for (int i = static_cast<int>((MARGIN_X + SPACE)*INCH_LOUNIT); i < static_cast<int>((MARGIN_X + RULER_WIDTH)*INCH_LOUNIT); i += static_cast<int>(SPACE*INCH_LOUNIT)) {
		dc.MoveTo(i, -184);
		dc.LineTo(i, -200);
	}
	SPACE = 1;//1 inch
	for (int i = static_cast<int>((MARGIN_X + SPACE)*INCH_LOUNIT); i < static_cast<int>((MARGIN_X + RULER_WIDTH)*INCH_LOUNIT); i += static_cast<int>(SPACE*INCH_LOUNIT)) {
		dc.MoveTo(i, -175);
		dc.LineTo(i, -200);

		CString string;
		string.Format(_T("%d"), (i / 100) - 1);
		dc.TextOut(i, -175, string);
	}
}
