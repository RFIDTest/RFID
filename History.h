/*
Ǯ��������ʷ��
����ʷ��¼����txt�ļ���д

HISTORYFILE="history.txt" Ϊ��Դ�ļ������ַ�����������Ϊ��ʷ�ļ���

static bool write(int page,int block,WriteType type,int amount);
page ����	block ��	WriteType Ϊö�����ͣ���Ӧ��ʼ������ֵ������3������	amount ��
���⻹���¼����ʱ��Ϳ���

static CString read();
��ȡ��ʷ��¼������CString
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

extern const CString HISTORYFILE;//��Դ�ļ������ַ�����������Ϊ��ʷ�ļ���

class History : public CWnd
{
// Construction
public:
	History();
	static bool write(int page,int block,WriteType type,int amount);
	//page ����	block ��	WriteType Ϊö�����ͣ���Ӧ��ʼ������ֵ������3������	amount ��
	//���⻹���¼����ʱ��Ϳ���

	static CString read();
	//��ȡ��ʷ��¼������CString

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
