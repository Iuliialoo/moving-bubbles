// CDialog2.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "afxdialogex.h"
#include "CDialog2.h"


// Диалоговое окно CDialog2

IMPLEMENT_DYNAMIC(CDialog2, CDialog)

CDialog2::CDialog2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CDialog2::~CDialog2()
{
}

void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog2, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CDialog2
