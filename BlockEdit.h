#if !defined(AFX_BLOCKEDIT_H__5B7AE370_11AC_400F_9038_C4A6A839A781__INCLUDED_)
#define AFX_BLOCKEDIT_H__5B7AE370_11AC_400F_9038_C4A6A839A781__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BlockEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBlockEdit dialog

class CBlockEdit : public CDialog
{
// Construction
public:
	CBlockEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBlockEdit)
	enum { IDD = IDD_BlockEdit };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlockEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBlockEdit)
	afx_msg void OnBUTTONdefualtKeyB();
	afx_msg void OnBUTTONreadBlock();
	afx_msg void OnBUTTONreadPage();
	afx_msg void OnBUTTONwriteBlock();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLOCKEDIT_H__5B7AE370_11AC_400F_9038_C4A6A839A781__INCLUDED_)
