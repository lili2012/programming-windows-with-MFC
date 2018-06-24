
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	int m_shape;
public:
	afx_msg void OnShapeCircle();
	afx_msg void OnShapeSqure();
	afx_msg void OnShapeTriangle();
	afx_msg void OnUpdateShapeCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeSqure(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeTriangle(CCmdUI *pCmdUI);
};

