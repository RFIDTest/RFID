#if !defined(AFX_ERROR_H__9839C372_2AA3_4424_9B5A_D76EA36528FA__INCLUDED_)
#define AFX_ERROR_H__9839C372_2AA3_4424_9B5A_D76EA36528FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Error.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Error view

class Error : public CView
{
public:
	Error(int i);           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(Error)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Error)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~Error();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(Error)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERROR_H__9839C372_2AA3_4424_9B5A_D76EA36528FA__INCLUDED_)
