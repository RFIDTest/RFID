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
	// ��ʼ��OLE/COM�⻷��
	CoInitialize(NULL);
	try{
		// ͨ�����ִ���Connection����
		HRESULT hr = this->m_pConnection.CreateInstance("ADODB.Connection");
		if (FAILED(hr)){
			NOTICE.notice(_T("����_ConnectionPtr����ָ��ʧ��"));
			return false;
		}
		// �������ӳ�ʱʱ��
		this->m_pConnection->ConnectionTimeout = 600;
		// ����ִ�����ʱʱ��
		this->m_pConnection->CommandTimeout = 120;

		// �������ݿ�
		this->m_pConnection->Open("DSN=RFID;Server=localhost;Database=rfid",
			"root",
			"83411601",
			adModeUnknown);
	}
	catch (_com_error &e){
		// �����Ӵ򿪣���Ҫ���쳣�����йرպ��ͷ�����
		if ((NULL != this->m_pConnection) && this->m_pConnection->State){
			this->m_pConnection->Close();
			this->m_pConnection.Release();
			this->m_pConnection = NULL;
		}
		// ��CView��CDialog��Ҫʹ��ȫ�ֺ���AfxMessageBox
		AfxMessageBox(e.Description());
	}
	return true;
}

void MySqlHelper::Close()
{
	if ((NULL != this->m_pConnection) && (this->m_pConnection->State)){
		this->m_pConnection->Close(); // �ر�����
		this->m_pConnection.Release();// �ͷ�����
		this->m_pConnection = NULL;
	}
	// ������COM���ж��COM��
	CoUninitialize();
}