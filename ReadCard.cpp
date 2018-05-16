// ReadCard.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "ReadCard.h"
#include "StringHelper.h"
#include "MySqlHelper.h"
#include "ZM124U.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReadCard dialog

MySqlHelper test;
CReadCard::CReadCard(CWnd* pParent /*=NULL*/)
	: CDialog(CReadCard::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadCard)
	//}}AFX_DATA_INIT
}


void CReadCard::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadCard)
	DDX_Control(pDX, IDC_EDIT2, m_Uid);
	DDX_Control(pDX, IDC_EDIT1, m_Status);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReadCard, CDialog)
	//{{AFX_MSG_MAP(CReadCard)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadCard message handlers

void CReadCard::OnButton1() 
{
	test.Connect();
	// TODO: Add your control notification handler code here
    if(IDD_PowerOn() == IFD_OK) {
        // 更新状态栏，成功
        //isDeviceOpen = true;
        ((CWnd*)GetDlgItem(IDC_EDIT1))->SetWindowText(_T("开启设备成功"));
    }
    else {
        // 更新状态栏，失败
       // isDeviceOpen = false;
        ((CWnd*)GetDlgItem(IDC_EDIT1))->SetWindowText(_T("开启设备失败"));
    }
}

void CReadCard::OnButton2() 
{
	// TODO: Add your control notification handler code here
	test.Close();
	CString uid;
	
	if (StringHelper::GetUIDCStr(uid))
	{
		m_Status.SetWindowText(_T("寻卡成功"));
		m_Uid.SetWindowText(_T(uid));
	}
	else {
		m_Status.SetWindowText(_T("寻卡失败"));
		m_Uid.SetWindowText(_T(""));
	}

}
