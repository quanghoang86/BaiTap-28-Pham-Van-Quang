
// TamGiacDiChuyen7View.h : interface of the CTamGiacDiChuyen7View class
//

#pragma once
#include "PhimBam.h"
#include "HCN.h"
#include "VeHinh.h"
#include "Tamgiac.h"


class CTamGiacDiChuyen7View : public CView
{
protected: // create from serialization only
	CTamGiacDiChuyen7View() noexcept;
	DECLARE_DYNCREATE(CTamGiacDiChuyen7View)

// Attributes
public:
public:
	PhimBam b2, b4;
	CClientDC* pdc;
	CPoint p1, p2;
	CTamGiacDiChuyen7Doc* GetDocument() const;
	int control;
	VeHinh* ph[20];
	int n;
	

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTamGiacDiChuyen7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in TamGiacDiChuyen7View.cpp
inline CTamGiacDiChuyen7Doc* CTamGiacDiChuyen7View::GetDocument() const
   { return reinterpret_cast<CTamGiacDiChuyen7Doc*>(m_pDocument); }
#endif

