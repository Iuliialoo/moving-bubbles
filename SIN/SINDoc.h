
// SINDoc.h: интерфейс класса CSINDoc 
//
#include "MyTreeView.h"
#include "ColorDlg.h"
#include <vector>

#pragma once

class CMyCircle {

public:
	int x, y, r, dx, dy, maxWidth, maxHeight, rPenColor, gPenColor, bPenColor, widthPen;
	void checkBorder();
	CMyCircle();
	void create(int width, int height);
	void Draw(CDC *pDC);
	void changeMaxSize(int newMaxWidth, int newMaxHeight);
	void move();
	void getColor(COLORREF color);
	void getWidth(int widthPen);
	void checkTouchCircle(CMyCircle&);

	COLORREF color;

	bool hide = true;
};


class CSINDoc : public CDocument
{
protected: // создать только из сериализации
	CSINDoc() noexcept;
	DECLARE_DYNCREATE(CSINDoc)

// Атрибуты
public:
	std::vector<CMyCircle> circleList;
	//CColorDlg m_ColorDlg;

	CMyTreeView* m_pTreeView; 

	CRect currentRect;

	//COLORREF m_ColorDlg;
	//int m_Thickness = 1;

// Операции
public:
	void drawCircles(CDC* pDC);
	void setNewSizeToAllCircles(int width, int height);
	void moveCircles();

	bool checkCreat(int, int, int);
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSINDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSettingsColor();
	afx_msg void OnSettingsThinkess();
	afx_msg void OnUpdateSettingsColor(CCmdUI* pCmdUI);
	afx_msg void OnSettingsHide();
	afx_msg void OnUpdateSettingsHide(CCmdUI* pCmdUI);
	afx_msg void OnSettingColorRed();
	afx_msg void OnUpdateSettingColorRed(CCmdUI* pCmdUI);
	afx_msg void OnSettingColorRandom();
	afx_msg void OnUpdateSettingColorRandom(CCmdUI* pCmdUI);
	afx_msg void OnSettingColorGreen();
	afx_msg void OnUpdateSettingColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnSettingColorBlue();
	afx_msg void OnUpdateSettingColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnSettingColorBlack();
	afx_msg void OnUpdateSettingColorBlack(CCmdUI* pCmdUI);
	/*afx_msg void OnSettingThickness0();
	afx_msg void OnSettingThickness2();
	afx_msg void OnSettingThickness5();
	afx_msg void OnSettingThickness8();*/
	afx_msg void OnButtonColorRandom();
};
