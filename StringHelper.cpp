// StringHelper.cpp: implementation of the StringHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo2.h"
#include "StringHelper.h"
#include "ZM124U.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StringHelper::StringHelper()
{

}

StringHelper::~StringHelper()
{

}

bool StringHelper::GetUIDCStr(CString& UID)
{
	unsigned char buff[32];
	int buff_len;

	if (find_14443(buff, &buff_len) == 0)
	{
		UID.Empty();
		for(int i = 0; i <buff_len; i++) 
		{
		  // 将获得的UID数据（1 byte）转为16进制
			CString temp;
	 		temp.Format(_T("%02x"), buff[i]);
    		UID += temp;
		}
		return true;
	}
	else 
	{
		UID="UnknowUID";
		return false;
	}
}
void StringHelper::CString2UnsigedChar(CString pwdCStr, unsigned char* pwdCH)
{
	pwdCStr.MakeUpper();
	
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

	for(int j=0;j<len/2;j++)
	{
		pwdCH[j]=(unsigned char)(pwdCH[2*j]<<4)+(unsigned char)(pwdCH[2*j+1]);
	}
}