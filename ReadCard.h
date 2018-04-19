#if !defined(AFX_READCARD_H__E10F95E8_6DC5_4D2A_AB19_9440951144D3__INCLUDED_)
#define AFX_READCARD_H__E10F95E8_6DC5_4D2A_AB19_9440951144D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReadCard.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReadCard dialog

class CReadCard : public CDialog
{
// Construction
public:
	CReadCard(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReadCard)
	enum { IDD = IDD_ReadCard };
	CEdit	m_Uid;
	CEdit	m_Status;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadCard)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReadCard)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READCARD_H__E10F95E8_6DC5_4D2A_AB19_9440951144D3__INCLUDED_)
