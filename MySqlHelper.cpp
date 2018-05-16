// MySqlHelper.cpp: implementation of the MySqlHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo2.h"
#include "Notice.h"
#include "MySqlHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MySqlHelper::MySqlHelper()
{

}

MySqlHelper::~MySqlHelper()
{

}

bool MySqlHelper::Connect()
{
	// 初始化OLE/COM库环境
	CoInitialize(NULL);
	try{
		// 通过名字创建Connection对象
		HRESULT hr = this->m_pConnection.CreateInstance("ADODB.Connection");
		if (FAILED(hr)){
			NOTICE.notice(_T("创建_ConnectionPtr智能指针失败"));
			return false;
		}
		// 设置连接超时时间
		this->m_pConnection->ConnectionTimeout = 600;
		// 设置执行命令超时时间
		this->m_pConnection->CommandTimeout = 120;

		// 连接数据库
		this->m_pConnection->Open("DSN=RFID;Server=localhost;Database=rfid",
			"root",
			"83411601",
			adModeUnknown);
	}
	catch (_com_error &e){
		// 若连接打开，需要在异常处理中关闭和释放连接
		if ((NULL != this->m_pConnection) && this->m_pConnection->State){
			this->m_pConnection->Close();
			this->m_pConnection.Release();
			this->m_pConnection = NULL;
		}
		// 非CView和CDialog需要使用全局函数AfxMessageBox
		AfxMessageBox(e.Description());
	}
	return true;
}

void MySqlHelper::Close()
{
	if ((NULL != this->m_pConnection) && (this->m_pConnection->State)){
		this->m_pConnection->Close(); // 关闭连接
		this->m_pConnection.Release();// 释放连接
		this->m_pConnection = NULL;
	}
	// 访问完COM库后，卸载COM库
	CoUninitialize();
}