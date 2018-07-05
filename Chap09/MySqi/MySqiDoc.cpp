
// MySqiDoc.cpp : implementation of the CMySqiDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MySqi.h"
#endif

#include "MySqiDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMySqiDoc

IMPLEMENT_DYNCREATE(CMySqiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySqiDoc, CDocument)
END_MESSAGE_MAP()


// CMySqiDoc construction/destruction

CMySqiDoc::CMySqiDoc()
{
	// TODO: add one-time construction code here

}

CMySqiDoc::~CMySqiDoc()
{
}

BOOL CMySqiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_clrGrid[i][j] = RGB(255, 255, 255);

	m_clrCurrentColor = RGB(255, 0, 0);

	return TRUE;
}




// CMySqiDoc serialization

void CMySqiDoc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMySqiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMySqiDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMySqiDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMySqiDoc diagnostics

#ifdef _DEBUG
void CMySqiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySqiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMySqiDoc commands


COLORREF CMySqiDoc::GetCurrentColor()
{
	return m_clrCurrentColor;
}

COLORREF CMySqiDoc::GetSquare(int i, int j)
{
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	return m_clrGrid[i][j];
}

void CMySqiDoc::SetSquare(int i, int j, COLORREF color)
{
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}