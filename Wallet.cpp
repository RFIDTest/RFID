// Wallet.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "Wallet.h"
#include "History.h" 
extern const CString HISTORYFILE;
#include "StringHelper.h"
#include "ZM124U.h"


#include "Notice.h"
extern Notice NOTICE;

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
	ON_BN_CLICKED(IDC_BUTTON_cleraRecord, OnBUTTONcleraRecord)
	ON_BN_CLICKED(IDC_BUTTON_historyIquiry, OnBUTTONhistoryIquiry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWallet message handlers

//��ȡ4����ͬ�Ĳ���
void CWallet::GetParameters( int& page,int& block,unsigned char& pwdType,unsigned char* pwdCH)
{
	//��ȡpage��block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletBlock)->GetWindowText(tmp);
	block = _ttoi(tmp);
	//��ȡpage��block

	//�������ʹ���
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//�������ʹ���

	//��ȡ����
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	StringHelper::CString2UnsigedChar(pwdCStr,pwdCH);
	//��ȡ����
}

//��ʼ������
void CWallet::OnBUTTONwalletInit() 
{
	// TODO: Add your control notification handler code here

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_balance)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		NOTICE.notice("�������ʼ����","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ʼ��Ǯ��ʧ�ܣ�");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		NOTICE.notice("��ʼ������С��0��","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ʼ��Ǯ��ʧ�ܣ�");
		return;
	}
	//������

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);

	int code = write_account(page, block, pwdType, pwdCH, amount);

	NOTICE.notice(code);

	if(code==0)
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ʼ��Ǯ���ɹ���");
		WriteType writetype=INITIAL;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("���ļ�ʧ�ܣ�");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("��ʼ��Ǯ��ʧ�ܣ�");
	

}

//Ĭ������
void CWallet::OnBUTTONdefualtKey() 
{
	// TODO: Add your control notification handler code here
	m_walletKey.SetWindowText("FFFFFFFFFFFF");
	return ;
}

//��ѯ
void CWallet::OnBUTTONbalanceInquiry() 
{
	// TODO: Add your control notification handler code here

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);

	long balance=0;

	int code = read_account(page, block, pwdType, pwdCH, &balance); 
	NOTICE.notice(code);
	CString balanceCStr;
	balanceCStr.Format(_T("%d"), balance);
	if(code==0) 
	{
		GetDlgItem(IDC_EDIT_balance)->SetWindowText(balanceCStr);
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ѯ�ɹ���");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("��ѯʧ�ܣ�");

}

//��ֵ
void CWallet::OnBUTTONrechange() 
{
	// TODO: Add your control notification handler code here

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_rechange)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		NOTICE.notice("�������ֵ��","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ֵʧ�ܣ�");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		NOTICE.notice("��ֵ����С��0��","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ֵʧ�ܣ�");
		return;
	}
	//������

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);


	int code = add_account(page, block, pwdType, pwdCH, amount);
	NOTICE.notice(code);
	if(code==0) 
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("��ֵ�ɹ���");
		WriteType writetype=RECHARGE;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("���ļ�ʧ�ܣ�");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("��ֵʧ�ܣ�");
}

//����
void CWallet::OnBUTTONdeduction() 
{
	// TODO: Add your control notification handler code here

	//������
	CString amountCStr;
	GetDlgItem(IDC_EDIT_deduction)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// ����Ϊ��
		NOTICE.notice("���������ѽ�","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("����ʧ�ܣ�");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// ����С��0
		NOTICE.notice("���ѽ���С��0��","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("����ʧ�ܣ�");
		return;
	}
	//������

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);

	long balance=0;
	read_account(page, block, pwdType, pwdCH, &balance);
	if(balance<amount)
	{
		NOTICE.notice("���㣬���ֵ��","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("����ʧ�ܣ�");
		return ;
	}
	int code = sub_account(page, block, pwdType, pwdCH, amount);
	NOTICE.notice(code);
	if(code==0) 
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("���ѳɹ���");
		WriteType writetype=DEDUCTION;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("���ļ�ʧ�ܣ�");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("����ʧ�ܣ�");
}

void CWallet::OnBUTTONcleraRecord() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_history)->SetWindowText("");
	if(DeleteFile(HISTORYFILE)==0) NOTICE.notice("ɾ���ļ�ʧ�ܣ�");//DeleteFile����ɾ����ʷ�ļ�
}

void CWallet::OnBUTTONhistoryIquiry() 
{
	// TODO: Add your control notification handler code here
	CString s=History::read();
	GetDlgItem(IDC_EDIT_history)->SetWindowText(s);
}

