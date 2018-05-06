// BlockEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "BlockEdit.h"
#include "ZM124U.h"

#include "Notice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlockEdit dialog


CBlockEdit::CBlockEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CBlockEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBlockEdit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBlockEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlockEdit)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBlockEdit, CDialog)
	//{{AFX_MSG_MAP(CBlockEdit)
	ON_BN_CLICKED(IDC_BUTTON_defualtKeyB, OnBUTTONdefualtKeyB)
	ON_BN_CLICKED(IDC_BUTTON_readBlock, OnBUTTONreadBlock)
	ON_BN_CLICKED(IDC_BUTTON_readPage, OnBUTTONreadPage)
	ON_BN_CLICKED(IDC_BUTTON_writeBlock, OnBUTTONwriteBlock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlockEdit message handlers

void CBlockEdit::OnBUTTONdefualtKeyB() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_keyB)->SetWindowText("FFFFFFFFFFFF");
}

//读块
void CBlockEdit::OnBUTTONreadBlock() 
{
	// TODO: Add your control notification handler code here
	//获取page和block
	CString tmp;
	GetDlgItem(IDC_COMBO_Sector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_Block)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//获取page和block

	//密码类型处理
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//密码类型处理

	//获取密码
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_keyB)->GetWindowText(pwdCStr);
	pwdCStr.MakeUpper();
	unsigned char pwdCH[12];

	int len=pwdCStr.GetLength();

	for(int i=0;i<len;i++)
	{
		if(pwdCStr[i]>0x40) pwdCH[i]=(unsigned char)pwdCStr[i]-0x37;
		else 
		{
			char x=pwdCStr[i];
			pwdCH[i]=(unsigned char)atoi(&x);
		}
	}

	for(int j=0;j<(len+1)/2;j++)
	{
		pwdCH[j]=(unsigned char)(pwdCH[2*j]<<4)+(unsigned char)(pwdCH[2*j+1]);
	}
	//获取密码

	unsigned char des_data[12];
	int des_len=0;
	int code = read_block(page,block, pwdType, pwdCH,des_data, &des_len);
	Notice n(code);
	if(code!=0) return ;
	CString str,temp;
	for(int k = 0; k <des_len; k++) {
	 		temp.Format(_T("%02x"), des_data[k]);
    		str += temp;
		}
	switch(block)
	{
	case 0:
		GetDlgItem(IDC_EDIT_block0)->SetWindowText(str);
		GetDlgItem(IDC_EDIT_block1)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block2)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3a)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3b)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3c)->SetWindowText("");
		break;
	case 1:
		GetDlgItem(IDC_EDIT_block0)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block1)->SetWindowText(str);
		GetDlgItem(IDC_EDIT_block2)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3a)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3b)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3c)->SetWindowText("");
		break;
	case 2:
		GetDlgItem(IDC_EDIT_block0)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block1)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block2)->SetWindowText(str);
		GetDlgItem(IDC_EDIT_block3a)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3b)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block3c)->SetWindowText("");
		break;
	case 3:
		GetDlgItem(IDC_EDIT_block0)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block1)->SetWindowText("");
		GetDlgItem(IDC_EDIT_block2)->SetWindowText("");

		GetDlgItem(IDC_EDIT_block3a)->SetWindowText(str.Left(12));
		GetDlgItem(IDC_EDIT_block3b)->SetWindowText(str.Mid(12,8));
		GetDlgItem(IDC_EDIT_block3c)->SetWindowText(str.Right(12));
		break;
	}
 
}

void CBlockEdit::OnBUTTONreadPage() 
{
	// TODO: Add your control notification handler code here
	//获取page和block
	CString tmp;
	GetDlgItem(IDC_COMBO_Sector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	//GetDlgItem(IDC_COMBO_Block)->GetWindowText(tmp);
	int block = 0;
	//获取page和block

	//密码类型处理
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//密码类型处理

	//获取密码
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_keyB)->GetWindowText(pwdCStr);
	pwdCStr.MakeUpper();
	unsigned char pwdCH[12];

	int len=pwdCStr.GetLength();

	for(int i=0;i<len;i++)
	{
		if(pwdCStr[i]>0x40) pwdCH[i]=(unsigned char)pwdCStr[i]-0x37;
		else 
		{
			char x=pwdCStr[i];
			pwdCH[i]=(unsigned char)atoi(&x);
		}
	}

	for(int j=0;j<(len+1)/2;j++)
	{
		pwdCH[j]=(unsigned char)(pwdCH[2*j]<<4)+(unsigned char)(pwdCH[2*j+1]);
	}
	//获取密码

	
	for(block=0;block<4;block++)
	{
		unsigned char des_data[16];
		int des_len=0;
		int code = read_block(page,block, pwdType, pwdCH,des_data, &des_len);
		if(code!=0)
		{
			Notice notice(code);
			return ;
		}
		CString str,temp;
		for(int k = 0; k <des_len; k++) {
	 		temp.Format(_T("%02x"), des_data[k]);
    		str += temp;
		}
		switch(block)
		{
		case 0:
			GetDlgItem(IDC_EDIT_block0)->SetWindowText(str);
			break;
		case 1:
			GetDlgItem(IDC_EDIT_block1)->SetWindowText(str);
			break;
		case 2:
			GetDlgItem(IDC_EDIT_block2)->SetWindowText(str);
			break;
		case 3:
			GetDlgItem(IDC_EDIT_block3a)->SetWindowText(str.Left(12));
			GetDlgItem(IDC_EDIT_block3b)->SetWindowText(str.Mid(12,8));
			GetDlgItem(IDC_EDIT_block3c)->SetWindowText(str.Right(12));
			break;
		}
	}
	
	
}

void CBlockEdit::OnBUTTONwriteBlock() 
{
	// TODO: Add your control notification handler code here

	//获取page和block
	CString tmp;
	GetDlgItem(IDC_COMBO_Sector)->GetWindowText(tmp);
	int page = _ttoi(tmp);
	GetDlgItem(IDC_COMBO_Block)->GetWindowText(tmp);
	int block = _ttoi(tmp);
	//获取page和block

	//密码类型处理
	unsigned char pwdType;
	if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) pwdType = 0x0A;
	else pwdType = 0x0B;
	//密码类型处理

	//获取密码
	CString pwdCStr;
	GetDlgItem(IDC_EDIT_keyB)->GetWindowText(pwdCStr);
	pwdCStr.MakeUpper();
	unsigned char pwdCH[12];

	int len=pwdCStr.GetLength();

	for(int i=0;i<len;i++)
	{
		if(pwdCStr[i]>0x40) pwdCH[i]=(unsigned char)pwdCStr[i]-0x37;
		else 
		{
			char x=pwdCStr[i];
			pwdCH[i]=(unsigned char)atoi(&x);
		}
	}

	for(int j=0;j<(len+1)/2;j++)
	{
		pwdCH[j]=(unsigned char)(pwdCH[2*j]<<4)+(unsigned char)(pwdCH[2*j+1]);
	}
	//获取密码


	
	//获取写入内容和长度
	CString src_dataCStr;
	switch(block)
	{
	case 0:
		GetDlgItem(IDC_EDIT_block0)->GetWindowText(src_dataCStr);
		break;
	case 1:
		GetDlgItem(IDC_EDIT_block1)->GetWindowText(src_dataCStr);
		break;
	case 2:
		GetDlgItem(IDC_EDIT_block2)->GetWindowText(src_dataCStr);
		break;
	case 3:
		GetDlgItem(IDC_EDIT_block3a)->GetWindowText(src_dataCStr);
		break ;
		
	}

	src_dataCStr.MakeUpper();
	
	unsigned char src_data[32];
	int len_src_CStr=src_dataCStr.GetLength();
	int src_len=(len_src_CStr+1)/2;
	if(block==3)
	{

		int des_len=0;	
		read_block(page,block, pwdType, pwdCH,src_data, &des_len);
		
		unsigned char tmp[12];
		for(int a=0;a<len_src_CStr;a++)
		{
			if(src_dataCStr[a]>0x40) tmp[a]=(unsigned char)src_dataCStr[a]-0x37;
			else 
			{
				char y=src_dataCStr[a];
				tmp[a]=(unsigned char)atoi(&y);
			}
		}

		int b=0;
		for( ;b<src_len;b++)
		{
			src_data[b]=(unsigned char)(tmp[2*b]<<4)+(unsigned char)(tmp[2*b+1]);
		}
		src_len+=10;
		for( ;b<6;b++) src_data[b]=' ';
	}
	else
	{
		for(int ii=0;ii<len_src_CStr;ii++)
		{
			if(src_dataCStr[ii]>0x40) src_data[ii]=(unsigned char)src_dataCStr[ii]-0x37;
			else 
			{
				char x=src_dataCStr[ii];
				src_data[ii]=(unsigned char)atoi(&x);
			}
		}

		for(int jj=0;jj<(len_src_CStr+1)/2;jj++)
		{
			src_data[jj]=(unsigned char)(src_data[2*jj]<<4)+(unsigned char)(src_data[2*jj+1]);
		}
	}
	//获取写入内容和长度

	int code = write_block(block,page,pwdType,pwdCH,src_data,src_len); 
	Notice n(code);
}
