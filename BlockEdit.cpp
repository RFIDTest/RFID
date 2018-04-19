// BlockEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "BlockEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlockEdit dialog


CBlockEdit::CBlockEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CBlockEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBlockEdit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBlockEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlockEdit)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBlockEdit, CDialog)
	//{{AFX_MSG_MAP(CBlockEdit)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlockEdit message handlers
