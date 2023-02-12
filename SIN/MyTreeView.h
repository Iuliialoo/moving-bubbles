#pragma once
#include "afxcview.h"
//#include "SINDoc.h"

class CSINDoc; //forward declaration

// Просмотр CMyTreeView

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:
	HTREEITEM m_hColor, hWidth, m_blueColor, m_redColor, m_greenColor, m_blackColor, width3, width7, width10, width0, randomColor;

	void FillTree();

	CSINDoc* m_pDoc;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


