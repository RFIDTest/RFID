#if !defined(AFX_HISTORYRECORD_H__30F17D23_1EB4_4341_AEA9_AC6B262C8B38__INCLUDED_)
#define AFX_HISTORYRECORD_H__30F17D23_1EB4_4341_AEA9_AC6B262C8B38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistoryRecord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HistoryRecord dialog

class HistoryRecord : public CFileDialog
{
	DECLARE_DYNAMIC(HistoryRecord)

public:
	HistoryRecord(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

protected:
	//{{AFX_MSG(HistoryRecord)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYRECORD_H__30F17D23_1EB4_4341_AEA9_AC6B262C8B38__INCLUDED_)
