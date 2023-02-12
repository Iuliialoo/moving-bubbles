
// SINDoc.cpp: реализация класса CSINDoc 
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

#include <propkey.h>

#include "includes.h"
#include "MainFrm.h"

#include <random>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSINDoc

IMPLEMENT_DYNCREATE(CSINDoc, CDocument)

BEGIN_MESSAGE_MAP(CSINDoc, CDocument)
	ON_COMMAND(ID_SETTINGS_COLOR, &CSINDoc::OnSettingsColor)
	ON_COMMAND(ID_SETTINGS_THINKESS, &CSINDoc::OnSettingsThinkess)
	ON_UPDATE_COMMAND_UI(ID_SETTINGS_COLOR, &CSINDoc::OnUpdateSettingsColor)
	ON_COMMAND(ID_SETTINGS_HIDE, &CSINDoc::OnSettingsHide)
	ON_UPDATE_COMMAND_UI(ID_SETTINGS_HIDE, &CSINDoc::OnUpdateSettingsHide)
	ON_COMMAND(ID_SETTING_COLOR_RED, &CSINDoc::OnSettingColorRed)
	ON_UPDATE_COMMAND_UI(ID_SETTING_COLOR_RED, &CSINDoc::OnUpdateSettingColorRed)
	ON_COMMAND(ID_SETTING_COLOR_RANDOM, &CSINDoc::OnSettingColorRandom)
	ON_UPDATE_COMMAND_UI(ID_SETTING_COLOR_RANDOM, &CSINDoc::OnUpdateSettingColorRandom)
	ON_COMMAND(ID_SETTING_COLOR_GREEN, &CSINDoc::OnSettingColorGreen)
	ON_UPDATE_COMMAND_UI(ID_SETTING_COLOR_GREEN, &CSINDoc::OnUpdateSettingColorGreen)
	ON_COMMAND(ID_SETTING_COLOR_BLUE, &CSINDoc::OnSettingColorBlue)
	ON_UPDATE_COMMAND_UI(ID_SETTING_COLOR_BLUE, &CSINDoc::OnUpdateSettingColorBlue)
	ON_COMMAND(ID_SETTING_COLOR_BLACK, &CSINDoc::OnSettingColorBlack)
	ON_UPDATE_COMMAND_UI(ID_SETTING_COLOR_BLACK, &CSINDoc::OnUpdateSettingColorBlack)

	/*ON_COMMAND(ID_SETTING_THICKNESS_0, &CSINDoc::OnSettingThickness0)
	ON_COMMAND(ID_SETTING_THICKNESS_2, &CSINDoc::OnSettingThickness2)
	ON_COMMAND(ID_SETTING_THICKNESS_5, &CSINDoc::OnSettingThickness5)
	ON_COMMAND(ID_SETTING_THICKNESS_8, &CSINDoc::OnSettingThickness8)*/

	ON_COMMAND(ID_BUTTON_COLOR_RANDOM, &CSINDoc::OnButtonColorRandom)
END_MESSAGE_MAP()

CMyCircle::CMyCircle() {
	x = 0;
	y = 0;
	r = 0;
	dx = 0;
	dy = 0;
	maxHeight = 0;
	maxWidth = 0;
	rPenColor = gPenColor = bPenColor = 0;
	widthPen = 0;
	color = RGB(0, 0, 0);
	//hide = false;
}

void CMyCircle::create(int width, int height) {
	
	r = 25 + rand() % 40;
	x = (r + 5) + rand() % (width - 150);
	y = (r + 5) + rand() % (height - 150);

	

	while (dx == 0 || dy == 0) {
		dx = -5 + rand() % 11;
		dy = -5 + rand() % 11;
	}
	//1418 625

	maxHeight = height;
	maxWidth = width;

}

void CMyCircle::Draw(CDC* pDC) {
	if (hide) {
		CPen pen(PS_SOLID, widthPen, color);
		pDC->SelectObject(&pen);

		pDC->MoveTo(x + r, y);
		pDC->AngleArc(x, y, r, 0, 360);
		checkBorder();
	}

}

void CMyCircle::checkBorder() {
	if (x - r <= 0) dx *= -1;

	if (y - r <= 0) dy *= -1;

	if (x + r >= maxWidth) dx *= -1;

	if (y + r >= maxHeight) dy *= -1;
}

void CMyCircle::changeMaxSize(int newMaxWidth, int newMaxHeight) {
	maxWidth = newMaxWidth;
	maxHeight = newMaxHeight;

	if (x + r > maxWidth)
		x = maxWidth - r - 1;

	if (y + r > maxHeight)
		y = maxHeight - r - 1;

	if (x - r < 0)
		x = r + 1;

	if (y - r < 0)
		y = r + 1;
}
int o = 0;
void CMyCircle::move() {
	x += dx;
	y += dy;
}

void CMyCircle::getColor(COLORREF m_Color) {
	//color = m_Color;
}

void CMyCircle::getWidth(int widthPen) {
	this->widthPen = widthPen;
}

void CMyCircle::checkTouchCircle(CMyCircle& circle) {
	int deltaX = x - circle.x, deltaY = y - circle.y;
	double distance = sqrt(deltaX * deltaX + deltaY * deltaY);
	int dx1 = dx / abs(dx), dy1 = dy / abs(dy);
	int dx2 = circle.dx / abs(circle.dx), dy2 = circle.dy / abs(circle.dy);

	if (distance <= (r + circle.r)) {
		if (dx1 == dx2 && dy1 == dy2) {
			dy *= -1;
		}
		if (deltaY < 0) {
			if (dy1 < 0) dx *= -1;
			else dy *= -1;

			if (dy2 < 0)
				circle.dy *= -1;
			else circle.dx *= -1;
		}
	}
}




void CSINDoc::drawCircles(CDC* pDC) {
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].Draw(pDC);
	}
}

void CSINDoc::setNewSizeToAllCircles(int width, int height) {
	for (int i = 0; i < circleList.size(); i++)
		circleList[i].changeMaxSize(width, height);
}

void CSINDoc::moveCircles() {
	for (int i = 0; i < circleList.size(); i++) {
		if (!circleList[i].hide) break;
		circleList[i].move();
		for (int j = 0; j < circleList.size(); j++) {
			if (j != i)
				circleList[i].checkTouchCircle(circleList[j]);
		}
	}
}



bool CSINDoc::checkCreat(int x, int y, int r) {
	//TRACE("\n\n%d\n\n", circleList[0].r);
	/*if (circleList.size() != 0)
		for (int i = 0; i < circleList.size() - 1; i++) {
			if (circleList[i + 1].x + circleList[i + 1].r >= circleList[i].x - circleList[i].r && circleList[i + 1].x - circleList[i + 1].r <= circleList[i].x + circleList[i].r &&
				circleList[i + 1].y + circleList[i + 1].y >= circleList[i].y - circleList[i].y && circleList[i + 1].y - circleList[i + 1].r <= circleList[i].y + circleList[i].y)
				return true;
		}
	return false;*/
	int countCirclesDontTouch = 0;
	for (int i = 0; i < circleList.size() - 1; i++) {
		if (sqrt(pow(circleList[i].x - x, 2) + pow(circleList[i].y - y, 2)) > circleList[i].r + r)
			countCirclesDontTouch++;
	}

	if (countCirclesDontTouch == circleList.size() - 1)
		return true;
	else return false;
}


// Создание или уничтожение CSINDoc

CSINDoc::CSINDoc() noexcept
{

}

CSINDoc::~CSINDoc()
{
}

BOOL CSINDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_pTreeView->FillTree();



	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CSINDoc

void CSINDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSINDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSINDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSINDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSINDoc

#ifdef _DEBUG
void CSINDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSINDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSINDoc


void CSINDoc::OnSettingsColor()
{
	// TODO: добавьте свой код обработчика команд
	
	//if (!m_ColorDlg) m_ColorDlg.Create(IDD_DLG_COLOR, AfxGetMainWnd())
	// m_Coloe.pDoc = this;
	// m_Color.m_Color.SetColor(m_Color);
	// 
	//m_ColorDlg.ShowWindow(SW_SHOW):
}


void CSINDoc::OnSettingsThinkess()
{
	// TODO: добавьте свой код обработчика команд
	//CThicknessDlg dlg;

	/*dlg.m_iValue = m_iThickness; 
	if (dlg.doModal() == IDOK);
		m_iThickness = dlg.m_iValue;*/

}



void CSINDoc::OnUpdateSettingsColor(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}




void CSINDoc::OnSettingsHide()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].hide = !circleList[i].hide;
	}
}


void CSINDoc::OnUpdateSettingsHide(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(!circleList[0].hide);
}




void CSINDoc::OnSettingColorRed()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].color = RGB(255, 0, 0);
	}
}


void CSINDoc::OnUpdateSettingColorRed(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}



void CSINDoc::OnSettingColorRandom()
{
	// TODO: добавьте свой код обработчика команд
	int r = 0, g = 0, b = 0;

	for (int i = 0; i < circleList.size(); i++) {
		r = 0 + rand() % 256;
		g = 0 + rand() % 256;
		b = 0 + rand() % 256;
		circleList[i].color = RGB(r, g, b);
	}
}


void CSINDoc::OnUpdateSettingColorRandom(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}




void CSINDoc::OnSettingColorGreen()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].color = RGB(0, 255, 0);
	}
}


void CSINDoc::OnUpdateSettingColorGreen(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}




void CSINDoc::OnSettingColorBlue()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].color = RGB(0, 0, 255);
	}
}

void CSINDoc::OnUpdateSettingColorBlue(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}




void CSINDoc::OnSettingColorBlack()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].color = RGB(0, 0, 0);
	}
}


void CSINDoc::OnUpdateSettingColorBlack(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
}



//void CSINDoc::OnSettingThickness0()
//{
//	// TODO: добавьте свой код обработчика команд
//	for (int i = 0; i < circleList.size(); i++) {
//		circleList[i].widthPen = 0;
//	}
//}
//
//
//void CSINDoc::OnSettingThickness2()
//{
//	// TODO: добавьте свой код обработчика команд
//	for (int i = 0; i < circleList.size(); i++) {
//		circleList[i].widthPen = 2;
//	}
//}
//
//
//void CSINDoc::OnSettingThickness5()
//{
//	// TODO: добавьте свой код обработчика команд
//	for (int i = 0; i < circleList.size(); i++) {
//		circleList[i].widthPen = 5;
//	}
//}
//
//
//void CSINDoc::OnSettingThickness8()
//{
//	// TODO: добавьте свой код обработчика команд
//	for (int i = 0; i < circleList.size(); i++) {
//		circleList[i].widthPen = 8;
//	}
//}


void CSINDoc::OnButtonColorRandom()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < circleList.size(); i++) {
		circleList[i].color = RGB(0, 0, 0);
	}
}
