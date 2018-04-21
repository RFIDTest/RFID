; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWallet
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Demo2.h"

ClassCount=9
Class1=CDemo2App
Class2=CDemo2Dlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_Wallet
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CReadCard
Resource4=IDD_DEMO2_DIALOG
Class5=CWallet
Resource5=IDD_ReadCard
Class6=CBlockEdit
Resource6=IDD_BlockEdit
Class7=ErrorTable
Class8=Error
Class9=Notice
Resource7=IDD_DIALOG1

[CLS:CDemo2App]
Type=0
HeaderFile=Demo2.h
ImplementationFile=Demo2.cpp
Filter=N

[CLS:CDemo2Dlg]
Type=0
HeaderFile=Demo2Dlg.h
ImplementationFile=Demo2Dlg.cpp
Filter=D
LastObject=CDemo2Dlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Demo2Dlg.h
ImplementationFile=Demo2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DEMO2_DIALOG]
Type=1
Class=CDemo2Dlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_ReadCard]
Type=1
Class=CReadCard
ControlCount=7
Control1=IDC_STATIC,button,1342177543
Control2=IDC_EDIT1,edit,1484849280
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1484849280
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1342242816

[CLS:CReadCard]
Type=0
HeaderFile=ReadCard.h
ImplementationFile=ReadCard.cpp
BaseClass=CDialog
Filter=D
LastObject=CReadCard
VirtualFilter=dWC

[CLS:CWallet]
Type=0
HeaderFile=Wallet.h
ImplementationFile=Wallet.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_key
VirtualFilter=dWC

[DLG:IDD_BlockEdit]
Type=1
Class=CBlockEdit
ControlCount=24
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342177289
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_COMBO1,combobox,1344340226
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO3,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT2,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT7,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT8,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT9,edit,1350631552
Control20=IDC_EDIT10,edit,1350631552
Control21=IDC_EDIT11,edit,1350631552
Control22=IDC_BUTTON2,button,1342242816
Control23=IDC_BUTTON9,button,1342242816
Control24=IDC_BUTTON10,button,1342242816

[CLS:CBlockEdit]
Type=0
HeaderFile=BlockEdit.h
ImplementationFile=BlockEdit.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO2

[DLG:IDD_Wallet]
Type=1
Class=CWallet
ControlCount=27
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1_wallet,button,1342177289
Control3=IDC_RADIO2_wallet,button,1342177289
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_key,edit,1350631552
Control6=IDC_BUTTON_defualtKey,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_COMBO_walletSector,combobox,1344339971
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO_walletBlock,combobox,1344339971
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_balance,edit,1350631552
Control14=IDC_BUTTON_walletInit,button,1342242816
Control15=IDC_BUTTON_rechange,button,1342242816
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_rechange,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_deduction,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_EDIT_state,edit,1484849280
Control22=IDC_BUTTON_balanceInquiry,button,1342242816
Control23=IDC_BUTTON_deduction,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_EDIT2,edit,1352728644
Control26=IDC_BUTTON7,button,1342242816
Control27=IDC_BUTTON8,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:ErrorTable]
Type=0
HeaderFile=ErrorTable.h
ImplementationFile=ErrorTable.cpp
BaseClass=generic CWnd
Filter=W

[CLS:Error]
Type=0
HeaderFile=Error.h
ImplementationFile=Error.cpp
BaseClass=CView
Filter=C

[CLS:Notice]
Type=0
HeaderFile=Notice.h
ImplementationFile=Notice.cpp
BaseClass=generic CWnd
Filter=W

