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
		MessageBox("�����ɹ�"," Succeeded");
	case -1:
		MessageBox("��Ƭ���Ͳ���","Error");
		break;
	case -2:
		MessageBox("�޿�","Error");
		break;
	case -3:
		MessageBox("�п�δ�ϵ�","Error");
		break;
	case -4:
		MessageBox("��Ƭ��Ӧ��","Error");
		break;
	case -5:
		MessageBox("BCC У�����","Error");
		break;
	case -6:
		MessageBox("���ճ�ʱ","Error");
		break;
	case -7:
		MessageBox("ִ��ʧ��","Error");
		break;
	case -8:
		MessageBox("��Ƭλ�ô���","Error");
		break;
	case -9:
		MessageBox("����ʧ��","Error");
		break;
	case -11:
		MessageBox("���������Ӵ�","Error");
		break;
	case -12:
		MessageBox("δ��������(û��ִ�д��豸����)","Error");
		break;
	case -13:
		MessageBox("(��̬��)��֧�ָ�����","Error");
		break;
	case -14:
		MessageBox("(������̬���)���������","Error");
		break;
	case -15:
		MessageBox("��ϢУ��ͳ���","Error");
		break;
	case -16:
		MessageBox("��Ƭ�ϵ�ʧ�� ","Error");
		break;
	case -17:
		MessageBox("��Ƭ��λʧ�� ","Error");
		break;
	case -18:
		MessageBox("��Ƭ�µ�ʧ�� ","Error");
		break;
	default:
		MessageBox("δ֪����","Error");
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
