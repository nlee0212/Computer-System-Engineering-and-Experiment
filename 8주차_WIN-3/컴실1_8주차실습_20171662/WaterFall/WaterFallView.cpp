
// WaterFallView.cpp : CWaterFallView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "WaterFall.h"
#include "Waterfallsolver.h"
#endif

#include "WaterFallDoc.h"
#include "WaterFallView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWaterFallView

IMPLEMENT_DYNCREATE(CWaterFallView, CView)

BEGIN_MESSAGE_MAP(CWaterFallView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWaterFallView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWaterFallView ����/�Ҹ�

CWaterFallView::CWaterFallView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWaterFallView::~CWaterFallView()
{
}

BOOL CWaterFallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWaterFallView �׸���

void CWaterFallView::OnDraw(CDC* pDC)
{
	CWaterFallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc){
		return;
	}
	
	F4(pDC);
	F5(pDC);
	F6(pDC);
	F1();	
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWaterFallView �μ�


void CWaterFallView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif

}

BOOL CWaterFallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CWaterFallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CWaterFallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CWaterFallView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWaterFallView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWaterFallView ����

#ifdef _DEBUG
void CWaterFallView::AssertValid() const
{
	CView::AssertValid();
}

void CWaterFallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWaterFallDoc* CWaterFallView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWaterFallDoc)));
	return (CWaterFallDoc*)m_pDocument;
}
#endif //_DEBUG


// CWaterFallView �޽��� ó����
