
// SINView.cpp: реализация класса CSINView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SIN.h"
#endif

#include "SINDoc.h"
#include "SINView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSINView

IMPLEMENT_DYNCREATE(CSINView, CView)

BEGIN_MESSAGE_MAP(CSINView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_RBUTTONUP()

END_MESSAGE_MAP()

// Создание или уничтожение CSINView

CSINView::CSINView() noexcept
{
	// TODO: добавьте код создания

}

CSINView::~CSINView() 
{
}

BOOL CSINView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CSINView

void CSINView::OnDraw(CDC* pDC)
{
	CSINDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	/*CPen pen;
	pen.CreatePen(PS_SOLID, pDoc->m_Thickness, pDoc->m_Color);
	CPen *oldPen = pDC->SelectObject(&pen);*/

	/*pDC->LineTo(200, 200);
	pDC->SelectObject(oldPen);*/

	pDoc->drawCircles(pDC);
	
}


// Печать CSINView

BOOL CSINView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSINView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSINView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CSINView

#ifdef _DEBUG
void CSINView::AssertValid() const
{
	CView::AssertValid();
}

void CSINView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSINDoc* CSINView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSINDoc)));
	return (CSINDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSINView


void CSINView::OnInitialUpdate()
{
	TRACE("\n\nHHHHHHHHHHHHHHHHHHHHHH\n\n");
	srand(time(NULL));
	CView::OnInitialUpdate();

	CRect rect;
	GetClientRect(&rect);

	CSINDoc* pDoc = GetDocument();

	int circleCount = 15;
	pDoc->circleList.resize(0);

	//TRACE("\n\n %d \n\n", pDoc->circleList.size());

	//pDoc->circleList = new CMyCircle[circleCount];

	for (int i = 0; i < circleCount; i++) {
		pDoc->circleList.resize(i+1);
		//pDoc->circleList[i].create(rect.Width(), rect.Height());
		do {
			pDoc->circleList[i].create(rect.Width(), rect.Height());
		} while (!pDoc->checkCreat(pDoc->circleList[i].x, pDoc->circleList[i].y, pDoc->circleList[i].r));
	}

	SetTimer(0, 10, NULL);

	// TODO: добавьте специализированный код или вызов базового класса
}


void CSINView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	
	CSINDoc* pDoc = GetDocument();

	CRect rect;
	GetClientRect(&rect);


	if (pDoc->currentRect.Width() != rect.Width() || pDoc->currentRect.Height() != rect.Height()) {
		pDoc->setNewSizeToAllCircles(rect.Width(), rect.Height());
		pDoc->currentRect = rect;
	}

	pDoc->moveCircles();
	Invalidate();
	CView::OnTimer(nIDEvent);
}




void CSINView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CMenu MainMenu;
	MainMenu.LoadMenuW(IDR_MAINFRAME);
	CMenu* SubMenu = MainMenu.GetSubMenu(3);

	ClientToScreen(&point);

	SubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CView::OnRButtonUp(nFlags, point);
}



