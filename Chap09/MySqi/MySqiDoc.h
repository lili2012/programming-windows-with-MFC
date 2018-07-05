
// MySqiDoc.h : interface of the CMySqiDoc class
//


#pragma once


class CMySqiDoc : public CDocument
{
protected: // create from serialization only
	CMySqiDoc();
	DECLARE_DYNCREATE(CMySqiDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMySqiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	COLORREF m_clrCurrentColor;
	COLORREF m_clrGrid[4][4];


public:
	COLORREF GetCurrentColor();
	COLORREF GetSquare(int i, int j);
	void SetSquare(int i, int j, COLORREF color);
};
