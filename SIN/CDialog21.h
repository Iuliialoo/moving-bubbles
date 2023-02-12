#pragma once
#include "afxdialogex.h"


// Диалоговое окно CDialog21

class CDialog21 : public CDialog
{
	DECLARE_DYNAMIC(CDialog21)

public:
	CDialog21(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDialog21();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
