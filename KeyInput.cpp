// KeyInput.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "KeyInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyInput dialog


CKeyInput::CKeyInput(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeyInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CKeyInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeyInput)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKeyInput, CDialog)
	//{{AFX_MSG_MAP(CKeyInput)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyInput message handlers
