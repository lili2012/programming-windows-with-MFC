class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
};

class CMainWindow : public CFrameWnd
{
public:
    CMainWindow ();

protected:
    afx_msg void OnPaint ();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nCode, UINT nPos, CScrollBar* pScrollBar);
    DECLARE_MESSAGE_MAP ()
	CPoint m_VISUAL_SPACE_DE;
};
