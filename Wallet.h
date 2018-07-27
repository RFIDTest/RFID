#if !defined(AFX_Wallet_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_)
#define AFX_Wallet_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wallet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWallet dialog

class CWallet : public CDialog
{
// Construction
public:
	CWallet(CWnd* pParent = NULL);   // standard constructor
	void GetParameters( int& page,int& block,unsigned char& pwdType,unsigned char* pwdCH);
// Dialog Data
	//{{AFX_DATA(CWallet)
	enum { IDD = IDD_Wallet };
	CEdit	m_walletKey;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWallet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWallet)
	afx_msg void OnBUTTONwalletInit();
	afx_msg void OnBUTTONdefualtKey();
	afx_msg void OnBUTTONbalanceInquiry();
	afx_msg void OnBUTTONrechange();
	afx_msg void OnBUTTONdeduction();
	afx_msg void OnBUTTONcleraRecord();
	afx_msg void OnBUTTONhistoryIquiry();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Wallet_H__73F5A4FC_370E_4836_A2A7_CD5D9E0DB5E5__INCLUDED_)
