// CDialog21.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "afxdialogex.h"
#include "CDialog21.h"


// Диалоговое окно CDialog21

IMPLEMENT_DYNAMIC(CDialog21, CDialog)

CDialog21::CDialog21(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CDialog21::~CDialog21()
{
}

void CDialog21::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog21, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CDialog21
