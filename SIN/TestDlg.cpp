// TestDlg.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "afxdialogex.h"
#include "TestDlg.h"


// Диалоговое окно TestDlg

IMPLEMENT_DYNAMIC(TestDlg, CDialog)

TestDlg::TestDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_TEST, pParent)
{

}

TestDlg::~TestDlg()
{
}

void TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений TestDlg
