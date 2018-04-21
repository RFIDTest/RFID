#if !defined(AFX_ERRORTABLE_H__D3B35A2F_5E4F_4295_8233_4154A52C7C0A__INCLUDED_)
#define AFX_ERRORTABLE_H__D3B35A2F_5E4F_4295_8233_4154A52C7C0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ErrorTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ErrorTable window

class ErrorTable : public CWnd
{
// Construction
public:
	ErrorTable(int i);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ErrorTable)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ErrorTable();

	// Generated message map functions
protected:
	//{{AFX_MSG(ErrorTable)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORTABLE_H__D3B35A2F_5E4F_4295_8233_4154A52C7C0A__INCLUDED_)
