// History.cpp : implementation file
//

#include "stdafx.h"
#include "ZM124U.h"
#include "Demo2.h"
#include "History.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// History

History::History()
{
}

History::~History()
{
}
bool History::write(int page,int block,WriteType type,int amount)
{
	CFile file;
	int i = file.Open("history.txt", CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	if(i==0) return false;

	CTime tm=CTime::GetCurrentTime(); 
	CString s=tm.Format("%Y-%m-%d %H:%M:%S");//system time

	CString temp, uid;
	unsigned char buff[32];
	int buff_len;

	if (find_14443(buff, &buff_len) == 0){
		uid.Empty();
		for(int i = 0; i <buff_len; i++) {
		  // 将获得的UID数据（1 byte）转为16进制
	 		temp.Format(_T("%02x"), buff[i]);
    		uid += temp;
		}
	}
	s+=" UID:"+uid+"\r\n";
	file.SeekToEnd();
	CString tmp;
	tmp.Format(_T("%d"),page);
	s+=" page:"+tmp;
	tmp.Format(_T("%d"),block);
	s+=" block:"+tmp;
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
	tmp.Format(_T("%d"),amount);
	s+=tmp+" yuan\r\n";
	file.Write(s,s.GetLength());
	file.Close();
	return true;
}
CString History::read()
{
	CFile file;
	int i = file.Open("history.txt", CFile::modeCreate|CFile::modeNoTruncate|CFile::modeRead);
	if(i==0)
	{
		CString s="打开文件失败！";
		return s;
	}
	else 
	{
		DWORD len=file.GetLength();   
		char *cp = new char[len+1];
		cp[len]=0;
		file.Read(cp,len);
		CString s(cp);
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
