
// WaterFallView.h : CWaterFallView Ŭ������ �������̽�
//

#pragma once


class CWaterFallView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWaterFallView();
	DECLARE_DYNCREATE(CWaterFallView)

// Ư���Դϴ�.
public:
	CWaterFallDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CWaterFallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WaterFallView.cpp�� ����� ����
inline CWaterFallDoc* CWaterFallView::GetDocument() const
   { return reinterpret_cast<CWaterFallDoc*>(m_pDocument); }
#endif

