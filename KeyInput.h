#if !defined(AFX_KEYINPUT_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_)
#define AFX_KEYINPUT_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KeyInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKeyInput dialog

class CKeyInput : public CDialog
{
// Construction
public:
	CKeyInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyInput)
	enum { IDD = IDD_KeyInput };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKeyInput)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYINPUT_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_)
