// ColorDlg.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "ColorDlg.h"
#include "afxdialogex.h"
#include "SINDoc.h"


// Диалоговое окно CColorDlg

IMPLEMENT_DYNAMIC(CColorDlg, CDialogEx)

CColorDlg::CColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_COLOR, pParent)
{

}

CColorDlg::~CColorDlg()
{
}

void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CColorDlg
