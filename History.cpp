// History.cpp : implementation file
//

#include "stdafx.h"
#include "ZM124U.h"
#include "Demo2.h"
#include "History.h"
#include "StringHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// History

const CString HISTORYFILE="history.txt";
History::History()
{
}

History::~History()
{
}
bool History::write(int page,int block,WriteType type,int amount)
{
	CFile file;
	if(file.Open(HISTORYFILE, CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite) == 0) 
		return false;//���ļ�ʧ��

	CTime tm=CTime::GetCurrentTime(); 
	CString s=tm.Format("%Y-%m-%d %H:%M:%S");//system time

	CString uid;
	StringHelper::GetUIDCStr(uid);//��ȡuid
	s+=" UID:"+uid+"\r\n";

	CString tmp;
	tmp.Format(_T("%d"),page);
	s+=" page:"+tmp;
	tmp.Format(_T("%d"),block);//page and block
	s+=" block:"+tmp;

	//��������
	switch(type){
	case INITIAL:
		s+=" initial ";
		break;
	case RECHARGE:
		s+=" recharge ";
		break;
	case DEDUCTION:
		s+=" deducate ";
		break;
	}

	//���
	tmp.Format(_T("%d"),amount);
	s+=tmp+" yuan\r\n";

	file.SeekToEnd();
	file.Write(s,s.GetLength());
	file.Close();

	return true;
}
CString History::read()
{
	CFile file;
	if(file.Open(HISTORYFILE, CFile::modeCreate|CFile::modeNoTruncate|CFile::modeRead)==0)
	{
		CString s="���ļ�ʧ�ܣ�";
		return s;
	}
	else 
	{
		DWORD len=file.GetLength();   
		char *cp = new char[len+1];
		cp[len]=0;//char������β��־
		file.Read(cp,len);
		CString s(cp);//��char�����ʼ��CString
		delete []cp;
		file.Close();
		return s;
	}
	
}

BEGIN_MESSAGE_MAP(History, CWnd)
	//{{AFX_MSG_MAP(History)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// History message handlers
