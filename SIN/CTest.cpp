// CTest.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "afxdialogex.h"
#include "CTest.h"


// Диалоговое окно CTest

IMPLEMENT_DYNAMIC(CTest, CDialog)

CTest::CTest(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_TEST, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTest, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CTest
