// StringHelper.h: interface for the StringHelper class.
//
//////////////////////////////////////////////////////////////////////
/*
字符协助类，实现各种字符获取与转换
static bool GetUIDCStr(CString& UID);//获取uid，成功返回true，失败返回false
*/
#if !defined(AFX_STRINGHELPER_H__B64752E9_82A2_4775_AF57_7466BC46868D__INCLUDED_)
#define AFX_STRINGHELPER_H__B64752E9_82A2_4775_AF57_7466BC46868D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StringHelper  
{
public:
	StringHelper();
	virtual ~StringHelper();
	static bool GetUIDCStr(CString& UID);//获取uid，成功返回true，失败返回false
	static void CString2UnsigedChar(CString , unsigned char*);

};

#endif // !defined(AFX_STRINGHELPER_H__B64752E9_82A2_4775_AF57_7466BC46868D__INCLUDED_)
