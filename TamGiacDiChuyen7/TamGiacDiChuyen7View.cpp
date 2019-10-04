
// TamGiacDiChuyen7View.cpp : implementation of the CTamGiacDiChuyen7View class
//
//Câu 28:  vẽ hình tam giác. Cho phép di chuyển hình tam giác sau khi vẽ và  khi bấm vào hình và kéo tha trên màn hình.
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TamGiacDiChuyen7.h"
#endif

#include "TamGiacDiChuyen7Doc.h"
#include "TamGiacDiChuyen7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTamGiacDiChuyen7View

IMPLEMENT_DYNCREATE(CTamGiacDiChuyen7View, CView)

BEGIN_MESSAGE_MAP(CTamGiacDiChuyen7View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTamGiacDiChuyen7View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CTamGiacDiChuyen7View construction/destruction

CTamGiacDiChuyen7View::CTamGiacDiChuyen7View() noexcept
{
	// TODO: add construction code here
	b2.thietlap(100, 50, 280, 100);
	b2.chu = CString("Ve Tam Giac");
	b4.thietlap(300, 50, 480, 100);
	b4.chu = CString("Di Chuyen");
	control = 1;
	n = 0;
}

CTamGiacDiChuyen7View::~CTamGiacDiChuyen7View()
{
}

BOOL CTamGiacDiChuyen7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTamGiacDiChuyen7View drawing

void CTamGiacDiChuyen7View::OnDraw(CDC* /*pDC*/)
{
	CTamGiacDiChuyen7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);
	b2.draw(pdc);
	b4.draw(pdc);


	// TODO: add draw code for native data here
}


// CTamGiacDiChuyen7View printing


void CTamGiacDiChuyen7View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTamGiacDiChuyen7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTamGiacDiChuyen7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTamGiacDiChuyen7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTamGiacDiChuyen7View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTamGiacDiChuyen7View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTamGiacDiChuyen7View diagnostics

#ifdef _DEBUG
void CTamGiacDiChuyen7View::AssertValid() const
{
	CView::AssertValid();
}

void CTamGiacDiChuyen7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTamGiacDiChuyen7Doc* CTamGiacDiChuyen7View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTamGiacDiChuyen7Doc)));
	return (CTamGiacDiChuyen7Doc*)m_pDocument;
}
#endif //_DEBUG


// CTamGiacDiChuyen7View message handlers


void CTamGiacDiChuyen7View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	pdc = new CClientDC(this);
	CPen *oldP, * pen1, * pen2;//Set 2pen
	pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
	pen2 = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CBrush* oldB, * B1, * B2;
	B1 = new CBrush(RGB(0, 0, 0));
	B2 = new CBrush(RGB(255, 255, 255));//
	if (b2.tronghinh(point) == 1)
			control = 2;
		else
			if (b4.tronghinh(point) == 1)
				control = 4;
			else
				if (control == 2)//tamgiac
				{
					ph[n] = new Tamgiac(p1, p2);
					ph[n]->draw(pdc);
					n++;
				}

				else//dichuyenhinh
				{
					int i = 0;
					for (i = 0; i < n; i++)
					{
						if (ph[i]->tronghinh(p1) == 1)
						{
							oldP = pdc->SelectObject(pen2);//Chọn Pen Và ghi đè lên hình cũ lúc kéo thả
							oldB = pdc->SelectObject(B2);//
							ph[i]->draw(pdc);
							ph[i]->dichuyen(p2.x - p1.x, p2.y - p1.y);
							oldP = pdc->SelectObject(pen1);
							oldB = pdc->SelectObject(B2);
							ph[i]->draw(pdc);

						}

					}
				}
	CView::OnLButtonUp(nFlags, point);
}


void CTamGiacDiChuyen7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}
