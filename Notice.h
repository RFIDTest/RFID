/*
提示类
在操作后弹出提示窗口
*/

#if !defined(AFX_NOTICE_H__034EFE19_E11B_4F51_81BB_17E155A6210F__INCLUDED_)
#define AFX_NOTICE_H__034EFE19_E11B_4F51_81BB_17E155A6210F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Notice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Notice window

class Notice : public CWnd
{
// Construction
public:
	Notice(int code);//根据函数返回值进行提示
	Notice(CString content,CString title);//根据内容和标题进行提示


// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Notice)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Notice();

	// Generated message map functions
protected:
	//{{AFX_MSG(Notice)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTICE_H__034EFE19_E11B_4F51_81BB_17E155A6210F__INCLUDED_)
