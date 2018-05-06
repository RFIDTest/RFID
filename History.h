/*
钱包操作历史类
将历史记录进行txt文件读写

HISTORYFILE="history.txt" 为跨源文件共享字符串常量，作为历史文件名

static bool write(int page,int block,WriteType type,int amount);
page 扇区	block 块	WriteType 为枚举类型，对应初始化、充值、消费3个类型	amount 金额，
此外还会记录操作时间和卡号

static CString read();
读取历史记录，返回CString
*/

#if !defined(AFX_HISTORY_H__C2A96995_EC9F_4973_A005_453834F70C6C__INCLUDED_)
#define AFX_HISTORY_H__C2A96995_EC9F_4973_A005_453834F70C6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// History.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// History window
enum WriteType
{
	INITIAL=0,RECHARGE,DEDUCTION
};

extern const CString HISTORYFILE;//跨源文件共享字符串常量，作为历史文件名

class History : public CWnd
{
// Construction
public:
	History();
	static bool write(int page,int block,WriteType type,int amount);
	//page 扇区	block 块	WriteType 为枚举类型，对应初始化、充值、消费3个类型	amount 金额，
	//此外还会记录操作时间和卡号

	static CString read();
	//读取历史记录，返回CString

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(History)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~History();

	// Generated message map functions
protected:
	//{{AFX_MSG(History)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORY_H__C2A96995_EC9F_4973_A005_453834F70C6C__INCLUDED_)
