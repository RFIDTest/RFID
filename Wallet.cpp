// Wallet.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "Wallet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWallet dialog


CWallet::CWallet(CWnd* pParent /*=NULL*/)
	: CDialog(CWallet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWallet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWallet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWallet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWallet, CDialog)
	//{{AFX_MSG_MAP(CWallet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWallet message handlers
