#pragma once


// COptionsDialog dialog

class COptionsDialog : public CDialog
{
	DECLARE_DYNAMIC(COptionsDialog)

public:
	COptionsDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~COptionsDialog();

// Dialog Data
	enum { IDD = IDD_OPTIONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	int m_height;
//	int m_height;
	int m_height;
	int m_width;
	int m_units;
};
