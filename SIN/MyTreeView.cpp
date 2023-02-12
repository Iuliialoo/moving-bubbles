// MyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "SIN.h"
#include "MyTreeView.h"
#include "SINDoc.h"
//#include "MainFrm.h"


// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView
void CMyTreeView::FillTree() {

	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_hColor = tree.InsertItem(L"Цвет", -1, -1, NULL, TVI_FIRST);

	m_blackColor = tree.InsertItem(L"Черный", -1, -1, m_hColor, TVI_FIRST);
	m_redColor = tree.InsertItem(L"Красный", -1, -1, m_hColor, TVI_LAST);
	m_blueColor = tree.InsertItem(L"Синий", -1, -1, m_hColor, TVI_LAST);
	m_greenColor = tree.InsertItem(L"Зеленый", -1, -1, m_hColor, TVI_LAST);

	hWidth = tree.InsertItem(L"Толщина", -1, -1, NULL, TVI_LAST);

	width0 = tree.InsertItem(L"0", -1, -1, hWidth, TVI_FIRST);
	width3 = tree.InsertItem(L"2", -1, -1, hWidth, TVI_LAST);
	width7 = tree.InsertItem(L"5", -1, -1, hWidth, TVI_LAST);
	width10 = tree.InsertItem(L"8", -1, -1, hWidth, TVI_LAST);

	randomColor = tree.InsertItem(L"Рандомный цвет", -1, -1, m_hColor, TVI_LAST);


	//tree.Expand(m_hLinesRoot, TVE_EXPAND);
}

int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;// | TVS_CHECKBOXES;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}



void CMyTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl& tree = GetTreeCtrl();

	CRect rc;		

	tree.GetItemRect(m_redColor, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].color = RGB(255, 0, 0);
		}
	}


	tree.GetItemRect(m_blueColor, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].color = RGB(0, 0, 255);
		}
	}


	tree.GetItemRect(m_greenColor, &rc, false);


	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].color = RGB(0, 255, 0);
		}
	}

	tree.GetItemRect(m_blackColor, &rc, false);


	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].color = RGB(0, 0, 0);
		}
	}


	tree.GetItemRect(width3, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].getWidth(2);
		}
	}

	tree.GetItemRect(width7, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].getWidth(5);
		}
	}

	tree.GetItemRect(width10, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].getWidth(8);
		}
	}

	tree.GetItemRect(width0, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			m_pDoc->circleList[i].getWidth(0);
		}
	}
	
	int r = 0, g = 0, b = 0;

	tree.GetItemRect(randomColor, &rc, false);

	if (rc.PtInRect(point)) {
		for (int i = 0; i < m_pDoc->circleList.size(); i++) {
			r = 0 + rand() % 256;
			g = 0 + rand() % 256;
			b = 0 + rand() % 256;
			m_pDoc->circleList[i].color = RGB(r, g, b);
		}
	}


	CTreeView::OnLButtonDblClk(nFlags, point);
}
