// OptionsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DlgDemoTry.h"
#include "OptionsDialog.h"
#include "afxdialogex.h"


// COptionsDialog dialog

IMPLEMENT_DYNAMIC(COptionsDialog, CDialog)

COptionsDialog::COptionsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDialog::IDD, pParent)
	, m_height(0)
	, m_width(0)
	, m_units(0)
{

}

COptionsDialog::~COptionsDialog()
{
}

void COptionsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Height, m_height);
	DDV_MinMaxInt(pDX, m_height, 1, 128);
	DDX_Text(pDX, IDC_Width, m_width);
	DDV_MinMaxInt(pDX, m_width, 1, 128);
	DDX_Radio(pDX, IDC_INCHES, m_units);
}


BEGIN_MESSAGE_MAP(COptionsDialog, CDialog)
END_MESSAGE_MAP()


// COptionsDialog message handlers
