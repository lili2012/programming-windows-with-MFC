
// MySqiView.h : interface of the CMySqiView class
//

#pragma once


class CMySqiView : public CView
{
protected: // create from serialization only
	CMySqiView();
	DECLARE_DYNCREATE(CMySqiView)

// Attributes
public:
	CMySqiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMySqiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MySqiView.cpp
inline CMySqiDoc* CMySqiView::GetDocument() const
   { return reinterpret_cast<CMySqiDoc*>(m_pDocument); }
#endif

