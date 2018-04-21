// Error.cpp : implementation file
//

#include "stdafx.h"
#include "Demo2.h"
#include "Error.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Error

IMPLEMENT_DYNCREATE(Error, CView)

Error::Error(int i)
{
	switch(i){
	case 0:
		MessageBox("操作成功"," Succeeded");
	case -1:
		MessageBox("卡片类型不对","Error");
		break;
	case -2:
		MessageBox("无卡","Error");
		break;
	case -3:
		MessageBox("有卡未上电","Error");
		break;
	case -4:
		MessageBox("卡片无应答","Error");
		break;
	case -5:
		MessageBox("BCC 校验错误","Error");
		break;
	case -6:
		MessageBox("接收超时","Error");
		break;
	case -7:
		MessageBox("执行失败","Error");
		break;
	case -8:
		MessageBox("卡片位置错误","Error");
		break;
	case -9:
		MessageBox("设置失败","Error");
		break;
	case -11:
		MessageBox("读卡器连接错","Error");
		break;
	case -12:
		MessageBox("未建立连接(没有执行打开设备函数)","Error");
		break;
	case -13:
		MessageBox("(动态库)不支持该命令","Error");
		break;
	case -14:
		MessageBox("(发给动态库的)命令参数错","Error");
		break;
	case -15:
		MessageBox("信息校验和出错","Error");
		break;
	case -16:
		MessageBox("卡片上电失败 ","Error");
		break;
	case -17:
		MessageBox("卡片复位失败 ","Error");
		break;
	case -18:
		MessageBox("卡片下电失败 ","Error");
		break;
	default:
		MessageBox("未知错误","Error");
		break;
	}
}

Error::~Error()
{
}


BEGIN_MESSAGE_MAP(Error, CView)
	//{{AFX_MSG_MAP(Error)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Error drawing

void Error::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// Error diagnostics

#ifdef _DEBUG
void Error::AssertValid() const
{
	CView::AssertValid();
}

void Error::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Error message handlers
