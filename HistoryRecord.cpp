// HistoryRecord.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "HistoryRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HistoryRecord

IMPLEMENT_DYNAMIC(HistoryRecord, CFileDialog)

HistoryRecord::HistoryRecord(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
}


BEGIN_MESSAGE_MAP(HistoryRecord, CFileDialog)
	//{{AFX_MSG_MAP(HistoryRecord)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
