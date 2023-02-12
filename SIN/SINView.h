
// SINView.h: интерфейс класса CSINView
//

#pragma once
#include "SINDoc.h"


class CSINView : public CView
{
protected: // создать только из сериализации
	CSINView() noexcept;
	DECLARE_DYNCREATE(CSINView)

// Атрибуты
public:
	CSINDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSINView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в SINView.cpp
inline CSINDoc* CSINView::GetDocument() const
   { return reinterpret_cast<CSINDoc*>(m_pDocument); }
#endif

