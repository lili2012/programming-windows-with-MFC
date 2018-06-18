#include <afxwin.h>
#include "Accel.h"

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() :m_nHScrollPos(0), m_nVScrollPos(0)
{
	Create(NULL, _T("Accel"),
		WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL);
}

int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//
	// Initialize internal width and height values based on screen metrics.
	//
	CClientDC dc(this);
	m_nCellWidth = dc.GetDeviceCaps(LOGPIXELSX);
	m_nCellHeight = dc.GetDeviceCaps(LOGPIXELSY) / 4;
	m_nRibbonWidth = m_nCellWidth / 2;
	m_nViewWidth = (26 * m_nCellWidth) + m_nRibbonWidth;
	m_nViewHeight = m_nCellHeight * 100;
	return 0;
}

void CMainWindow::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);
	m_nHPageSize = cx;
	// Set the horizontal scrolling parameters.
	SCROLLINFO si;
	si.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin = 0;
	si.nMax = m_nViewWidth;
	si.nPos = m_nHScrollPos;
	si.nPage = cx;

	SetScrollInfo(SB_HORZ, &si, TRUE);
	m_nVPageSize = cy;
	// Set the vertical scrolling parameters.
	si.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin = 0;
	si.nMax = m_nViewHeight;
	si.nPos = m_nVScrollPos;
	si.nPage = cy;

	SetScrollInfo(SB_VERT, &si, TRUE);
}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);

	// Set the window origin to reflect the current scroll positions.
	dc.SetWindowOrg(m_nHScrollPos, m_nVScrollPos);

	// Draw the grid lines.
	CPen pen(PS_SOLID, 0, RGB(192, 192, 192));
	CPen* pOldPen = dc.SelectObject(&pen);

	for (int i = 0; i < 99; i++) {
		int y = (i * m_nCellHeight) + m_nCellHeight;
		dc.MoveTo(0, y);
		dc.LineTo(m_nViewWidth, y);
	}

	for (int j = 0; j < 26; j++) {
		int x = (j * m_nCellWidth) + m_nRibbonWidth;
		dc.MoveTo(x, 0);
		dc.LineTo(x, m_nViewHeight);
	}

	dc.SelectObject(pOldPen);

	//
	// Draw the bodies of the rows and the column headers.
	//
	CBrush brush;
	brush.CreateStockObject(LTGRAY_BRUSH);

	CRect rcTop(0, 0, m_nViewWidth, m_nCellHeight);
	dc.FillRect(rcTop, &brush);
	CRect rcLeft(0, 0, m_nRibbonWidth, m_nViewHeight);
	dc.FillRect(rcLeft, &brush);

	dc.MoveTo(0, m_nCellHeight);
	dc.LineTo(m_nViewWidth, m_nCellHeight);
	dc.MoveTo(m_nRibbonWidth, 0);
	dc.LineTo(m_nRibbonWidth, m_nViewHeight);

	dc.SetBkMode(TRANSPARENT);

	//
	// Add numbers and button outlines to the row headers.
	//
	for (int i = 0; i < 99; i++) {
		int y = (i * m_nCellHeight) + m_nCellHeight;
		dc.MoveTo(0, y);
		dc.LineTo(m_nRibbonWidth, y);

		CString string;
		string.Format(_T("%d"), i + 1);

		CRect rect(0, y, m_nRibbonWidth, y + m_nCellHeight);
		dc.DrawText(string, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER);

		rect.top++;
		dc.Draw3dRect(rect, RGB(255, 255, 255),
			RGB(128, 128, 128));
	}

	//
	// Add letters and button outlines to the column headers.
	//
	for (int j = 0; j < 26; j++) {
		int x = (j * m_nCellWidth) + m_nRibbonWidth;
		dc.MoveTo(x, 0);
		dc.LineTo(x, m_nCellHeight);

		CString string;
		string.Format(_T("%c"), j + 'A');

		CRect rect(x, 0, x + m_nCellWidth, m_nCellHeight);
		dc.DrawText(string, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER);

		rect.left++;
		dc.Draw3dRect(rect, RGB(255, 255, 255),
			RGB(128, 128, 128));
	}
}

void CMainWindow::OnHScroll(UINT nCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nDelta;

	//
	// Compute the horizontal scroll distance, or "delta."
	//
	switch (nCode) {

	case SB_LINELEFT:
		nDelta = -LINESIZE;
		break;

	case SB_PAGELEFT:
		nDelta = -m_nHPageSize;
		break;

	case SB_THUMBTRACK:
		nDelta = (int)nPos - m_nHScrollPos;
		break;

	case SB_PAGERIGHT:
		nDelta = m_nHPageSize;
		break;

	case SB_LINERIGHT:
		nDelta = LINESIZE;
		break;

	default: // Ignore other scroll bar messages
		return;
	}

	//
	// Adjust the delta if adding it to the current scroll position would
	// cause an underrun or overrun.
	//
	int nScrollPos = m_nHScrollPos + nDelta;//new hscrollpos
	int nMaxPos = m_nViewWidth - m_nHPageSize;

	if (nScrollPos < 0)
		nScrollPos = 0;
	else if (nScrollPos > nMaxPos)
		nScrollPos = nMaxPos;

	nDelta = nScrollPos - m_nHScrollPos;
	// Update the scroll position and scroll the window.
	//
	if (nDelta != 0) {
		m_nHScrollPos = nScrollPos;
		SetScrollPos(SB_HORZ, m_nHScrollPos, TRUE);
		ScrollWindow(-nDelta, 0);
	}
}

void CMainWindow::OnVScroll(UINT nCode, UINT nPos, CScrollBar* pScrollBar)
{
	//
	// Compute the vertical scroll distance, or "delta."
	//
	int newPos = m_nVScrollPos;
	switch (nCode) {

	case SB_LINEUP:
		newPos -= LINESIZE;
		break;

	case SB_PAGEUP:
		newPos -= m_nVPageSize;
		break;

	case SB_THUMBTRACK:
		newPos = (int)nPos;
		break;

	case SB_PAGEDOWN:
		newPos += m_nVPageSize;
		break;

	case SB_LINEDOWN:
		newPos += LINESIZE;
		break;
	case SB_ENDSCROLL:
		ASSERT(nPos == 0);
		break;
	case SB_THUMBPOSITION:
		ASSERT(nPos == m_nVScrollPos);
		break;
	default: // Ignore other scroll bar messages
		return;
	}

	//
	// Adjust the delta if adding it to the current scroll position would
	// cause an underrun or overrun.
	//
	int nMaxPos = m_nViewHeight - m_nVPageSize;

	if (newPos < 0)
		newPos = 0;
	else if (newPos > nMaxPos)
		newPos = nMaxPos;

	int nDelta = newPos - m_nVScrollPos;
	//
	// Update the scroll position and scroll the window.
	//
	if (nDelta != 0) {
		m_nVScrollPos = newPos;
		SetScrollPos(SB_VERT, m_nVScrollPos, TRUE);
		ScrollWindow(0, -nDelta);
	}
}
