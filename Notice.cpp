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
		//MessageBox("操作成功","Succeeded");
		data = (char*)"00";
		break;
	case -1:
		MessageBox("卡片类型不对","Error");
		data = (char*)"01";
		break;
	case -2:
		MessageBox("无卡","Error");
		data = (char*)"02";
		break;
	case -3:
		MessageBox("有卡未上电","Error");
		data = (char*)"03";
		break;
	case -4:
		MessageBox("卡片无应答","Error");
		data = (char*)"04";
		break;
	case -5:
		MessageBox("BCC 校验错误","Error");
		data = (char*)"05";
		break;
	case -6:
		MessageBox("接收超时","Error");
		data = (char*)"06";
		break;
	case -7:
		MessageBox("执行失败","Error");
		data = (char*)"07";
		break;
	case -8:
		MessageBox("卡片位置错误","Error");
		data = (char*)"08";
		break;
	case -9:
		MessageBox("设置失败","Error");
		data = (char*)"09";
		break;
	case -11:
		MessageBox("读卡器连接错","Error");
		data = (char*)"11";
		break;
	case -12:
		MessageBox("未建立连接(没有执行打开设备函数)","Error");
		data = (char*)"12";
		break;
	case -13:
		MessageBox("(动态库)不支持该命令","Error");
		data = (char*)"13";
		break;
	case -14:
		MessageBox("(发给动态库的)命令参数错","Error");
		data = (char*)"14";
		break;
	case -15:
		MessageBox("信息校验和出错","Error");
		data = (char*)"15";
		break;
	case -16:
		MessageBox("卡片上电失败 ","Error");
		data = (char*)"16";
		break;
	case -17:
		MessageBox("卡片复位失败 ","Error");
		data = (char*)"17";
		break;
	case -18:
		MessageBox("卡片下电失败 ","Error");
		data = (char*)"18";
		break;
	default:
		MessageBox("未知错误","Error");
		data = (char*)"10";
		break;
	}
	LED(data, data_len, point) ;
}

void Notice::notice(CString content,CString title)
{
	MessageBox(content,title);

	char *data=(char*)"16";//输入错误，自定义数字
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
