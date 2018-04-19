// Demo2Dlg.h : header file
//

#if !defined(AFX_DEMO2DLG_H__DEAF6F13_A8A2_439F_9548_ED89DCBFB406__INCLUDED_)
#define AFX_DEMO2DLG_H__DEAF6F13_A8A2_439F_9548_ED89DCBFB406__INCLUDED_

#include "ReadCard.h"
#include "KeyInput.h"
#include "BlockEdit.h"
#include "ZM124U.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDemo2Dlg dialog

class CDemo2Dlg : public CDialog
{
// Construction
public:
	CDemo2Dlg(CWnd* pParent = NULL);	// standard constructor
	CReadCard m_ReadCard;
	CKeyInput m_KeyInput;
	CBlockEdit m_BlockEdit;
// Dialog Data
	//{{AFX_DATA(CDemo2Dlg)
	enum { IDD = IDD_DEMO2_DIALOG };
	CTabCtrl	m_MainMenu;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemo2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO2DLG_H__DEAF6F13_A8A2_439F_9548_ED89DCBFB406__INCLUDED_)
