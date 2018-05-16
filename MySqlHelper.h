// MySqlHelper.h: interface for the MySqlHelper class.
//
//////////////////////////////////////////////////////////////////////
#import "./libs/msado15.dll" no_namespace rename("EOF","ADOEOF") rename("BOF","ADOBOF")
#if !defined(AFX_MYSQLHELPER_H__D46827E8_FC76_45A9_AAD4_2B5F1A5B929D__INCLUDED_)
#define AFX_MYSQLHELPER_H__D46827E8_FC76_45A9_AAD4_2B5F1A5B929D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MySqlHelper  
{
public:
	MySqlHelper();
	virtual ~MySqlHelper();
	bool Connect();
	void Close();
private:
	_ConnectionPtr m_pConnection;

};

#endif // !defined(AFX_MYSQLHELPER_H__D46827E8_FC76_45A9_AAD4_2B5F1A5B929D__INCLUDED_)
