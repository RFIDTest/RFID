// Wallet.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "Wallet.h"
#include "ZM124U.h"

#include "Notice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CWallet dialog


CWallet::CWallet(CWnd* pParent /*=NULL*/)
	: CDialog(CWallet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWallet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWallet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWallet)
	DDX_Control(pDX, IDC_EDIT_key, m_walletKey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWallet, CDialog)
	//{{AFX_MSG_MAP(CWallet)
	ON_BN_CLICKED(IDC_BUTTON_walletInit, OnBUTTONwalletInit)
	ON_BN_CLICKED(IDC_BUTTON_defualtKey, OnBUTTONdefualtKey)
	ON_BN_CLICKED(IDC_BUTTON_balanceInquiry, OnBUTTONbalanceInquiry)
	ON_BN_CLICKED(IDC_BUTTON_rechange, OnBUTTONrechange)
	ON_BN_CLICKED(IDC_BUTTON_deduction, OnBUTTONdeduction)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWallet message handlers

void CWallet::OnBUTTONwalletInit() 
{
	// TODO: Add your control notification handler code here

	//��ȡpage��block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//��ȡpage��block

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_balance)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		Notice n("�������ʼ����","Warnning!");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		Notice n("��ʼ������С��0��","Warnning!");
		return;
	}
	//������

	//�������ʹ���
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//�������ʹ���

	//��ȡ����
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	unsigned char* pwdCH = (unsigned char*)(LPCSTR)pwdCStr;
	//��ȡ����

	

	int code = write_account(page, block, pwdType, pwdCH, amount);
	Notice n(code);
	

}

void CWallet::OnBUTTONdefualtKey() 
{
	// TODO: Add your control notification handler code here
	m_walletKey.SetWindowText("FFFFFFFFFFFF");
	return ;
}

void CWallet::OnBUTTONbalanceInquiry() 
{
	// TODO: Add your control notification handler code here

	//��ȡpage��block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//��ȡpage��block

	//�������ʹ���
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//�������ʹ���

	//��ȡ����
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	unsigned char* pwdCH = (unsigned char*)(LPCSTR)pwdCStr;
	//��ȡ����

	long balance=0;

	int code = read_account(page, block, pwdType, pwdCH, &balance); 
	Notice n(code);
	CString balanceCStr;
	balanceCStr.Format(_T("%d"), balance);
	if(code==0) GetDlgItem(IDC_EDIT_balance)->SetWindowText(balanceCStr);

}

void CWallet::OnBUTTONrechange() 
{
	// TODO: Add your control notification handler code here
	//��ȡpage��block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//��ȡpage��block

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_balance)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		Notice n("�������ֵ��","Warnning!");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		Notice n("��ֵ����С��0��","Warnning!");
		return;
	}
	//������

	//�������ʹ���
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//�������ʹ���

	//��ȡ����
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	unsigned char* pwdCH = (unsigned char*)(LPCSTR)pwdCStr;
	//��ȡ����

	int code = add_account(page, block, pwdType, pwdCH, amount);
	Notice n(code);
}

void CWallet::OnBUTTONdeduction() 
{
	// TODO: Add your control notification handler code here
	//��ȡpage��block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//��ȡpage��block

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_balance)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		Notice n("���������ѽ�","Warnning!");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		Notice n("���ѽ���С��0��","Warnning!");
		return;
	}
	//������



	//�������ʹ���
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//�������ʹ���

	//��ȡ����
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	unsigned char* pwdCH = (unsigned char*)(LPCSTR)pwdCStr;
	//��ȡ����

	long balance=0;
	Notice n(read_account(page, block, pwdType, pwdCH, &balance));
	if(balance<amount)
	{
		Notice n("���㣬���ֵ��","Warnning!");
		return ;
	}
	int code = add_account(page, block, pwdType, pwdCH, amount);
	Notice notice(code);
}
