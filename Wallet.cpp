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

//获取4个相同的参数
void CWallet::GetParameters( int& page,int& block,unsigned char& pwdType,unsigned char* pwdCH)
{
	//获取page和block
	CString tmp;
	GetDlgItem(IDC_COMBO_walletSector)->GetWindowText(tmp);
	page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_walletBlock)->GetWindowText(tmp);
	block = _ttoi(tmp);
	//获取page和block

	//密码类型处理
	if(((CButton *)GetDlgItem(IDC_RADIO1_wallet))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//密码类型处理

	//获取密码
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_key)->GetWindowText(pwdCStr);
	StringHelper::CString2UnsigedChar(pwdCStr,pwdCH);
	//获取密码
}

//初始化函数
void CWallet::OnBUTTONwalletInit() 
{
	// TODO: Add your control notification handler code here

	//输入检查
	CString amountCStr;
	GetDlgItem(IDC_EDIT_balance)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// 输入为空
		NOTICE.notice("请输入初始化金额！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("初始化钱包失败！");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// 输入小于0
		NOTICE.notice("初始化金额不能小于0！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("初始化钱包失败！");
		return;
	}
	//输入检查

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);

	int code = write_account(page, block, pwdType, pwdCH, amount);

	NOTICE.notice(code);

	if(code==0)
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("初始化钱包成功！");
		WriteType writetype=INITIAL;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("打开文件失败！");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("初始化钱包失败！");
	

}

//默认密码
void CWallet::OnBUTTONdefualtKey() 
{
	// TODO: Add your control notification handler code here
	m_walletKey.SetWindowText("FFFFFFFFFFFF");
	return ;
}

//查询
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
		GetDlgItem(IDC_EDIT_state)->SetWindowText("查询成功！");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("查询失败！");

}

//充值
void CWallet::OnBUTTONrechange() 
{
	// TODO: Add your control notification handler code here

	//输入检查
	CString amountCStr;
	GetDlgItem(IDC_EDIT_rechange)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// 输入为空
		NOTICE.notice("请输入充值金额！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("充值失败！");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// 输入小于0
		NOTICE.notice("充值金额不能小于0！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("充值失败！");
		return;
	}
	//输入检查

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);


	int code = add_account(page, block, pwdType, pwdCH, amount);
	NOTICE.notice(code);
	if(code==0) 
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("充值成功！");
		WriteType writetype=RECHARGE;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("打开文件失败！");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("充值失败！");
}

//消费
void CWallet::OnBUTTONdeduction() 
{
	// TODO: Add your control notification handler code here

	//输入检查
	CString amountCStr;
	GetDlgItem(IDC_EDIT_deduction)->GetWindowText(amountCStr);
	if(amountCStr.IsEmpty()) {
		// 输入为空
		NOTICE.notice("请输入消费金额！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("消费失败！");
		return;
	}
	long amount = _ttol(amountCStr);
	if(amount < 0) {
		// 输入小于0
		NOTICE.notice("消费金额不能小于0！","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("消费失败！");
		return;
	}
	//输入检查

	int page=0;
	int block=0;
	unsigned char pwdType;
	unsigned char pwdCH[12];
	GetParameters(page,block,pwdType,pwdCH);

	long balance=0;
	read_account(page, block, pwdType, pwdCH, &balance);
	if(balance<amount)
	{
		NOTICE.notice("余额不足，请充值。","Warnning!");
		GetDlgItem(IDC_EDIT_state)->SetWindowText("消费失败！");
		return ;
	}
	int code = sub_account(page, block, pwdType, pwdCH, amount);
	NOTICE.notice(code);
	if(code==0) 
	{
		GetDlgItem(IDC_EDIT_state)->SetWindowText("消费成功！");
		WriteType writetype=DEDUCTION;
		if(History::write(page, block, writetype, amount)==false) NOTICE.notice("打开文件失败！");
	}
	else GetDlgItem(IDC_EDIT_state)->SetWindowText("消费失败！");
}

void CWallet::OnBUTTONcleraRecord() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_history)->SetWindowText("");
	if(DeleteFile(HISTORYFILE)==0) NOTICE.notice("删除文件失败！");//DeleteFile函数删除历史文件
}

void CWallet::OnBUTTONhistoryIquiry() 
{
	// TODO: Add your control notification handler code here
	CString s=History::read();
	GetDlgItem(IDC_EDIT_history)->SetWindowText(s);
}

