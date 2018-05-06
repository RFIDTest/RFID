// Notice.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "Notice.h"
#include "ZM124U.h"
Notice NOTICE(0);
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Notice
Notice::Notice(int i)
{
	i++;
}
void Notice::notice(int code)
{
	char *data=NULL;
	int data_len=2;
	unsigned char  point=0x00;
	
	switch(code){
	case 0:
		//MessageBox("�����ɹ�","Succeeded");
		data = (char*)"00";
		break;
	case -1:
		MessageBox("��Ƭ���Ͳ���","Error");
		data = (char*)"01";
		break;
	case -2:
		MessageBox("�޿�","Error");
		data = (char*)"02";
		break;
	case -3:
		MessageBox("�п�δ�ϵ�","Error");
		data = (char*)"03";
		break;
	case -4:
		MessageBox("��Ƭ��Ӧ��","Error");
		data = (char*)"04";
		break;
	case -5:
		MessageBox("BCC У�����","Error");
		data = (char*)"05";
		break;
	case -6:
		MessageBox("���ճ�ʱ","Error");
		data = (char*)"06";
		break;
	case -7:
		MessageBox("ִ��ʧ��","Error");
		data = (char*)"07";
		break;
	case -8:
		MessageBox("��Ƭλ�ô���","Error");
		data = (char*)"08";
		break;
	case -9:
		MessageBox("����ʧ��","Error");
		data = (char*)"09";
		break;
	case -11:
		MessageBox("���������Ӵ�","Error");
		data = (char*)"11";
		break;
	case -12:
		MessageBox("δ��������(û��ִ�д��豸����)","Error");
		data = (char*)"12";
		break;
	case -13:
		MessageBox("(��̬��)��֧�ָ�����","Error");
		data = (char*)"13";
		break;
	case -14:
		MessageBox("(������̬���)���������","Error");
		data = (char*)"14";
		break;
	case -15:
		MessageBox("��ϢУ��ͳ���","Error");
		data = (char*)"15";
		break;
	case -16:
		MessageBox("��Ƭ�ϵ�ʧ�� ","Error");
		data = (char*)"16";
		break;
	case -17:
		MessageBox("��Ƭ��λʧ�� ","Error");
		data = (char*)"17";
		break;
	case -18:
		MessageBox("��Ƭ�µ�ʧ�� ","Error");
		data = (char*)"18";
		break;
	default:
		MessageBox("δ֪����","Error");
		data = (char*)"10";
		break;
	}
	LED(data, data_len, point) ;
}

void Notice::notice(CString content,CString title)
{
	MessageBox(content,title);

	char *data=(char*)"16";//��������Զ�������
	int data_len=2;
	unsigned char  point=0x00;
	LED(data, data_len, point) ;
}

Notice::~Notice()
{
}


BEGIN_MESSAGE_MAP(Notice, CWnd)
	//{{AFX_MSG_MAP(Notice)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Notice message handlers
