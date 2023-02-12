
// SIN.h: основной файл заголовка для приложения SIN
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSINApp:
// Сведения о реализации этого класса: SIN.cpp
//

class CSINApp : public CWinApp
{
public:
	CSINApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSINApp theApp;
