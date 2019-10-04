
// TamGiacDiChuyen7Doc.h : interface of the CTamGiacDiChuyen7Doc class
//


#pragma once


class CTamGiacDiChuyen7Doc : public CDocument
{
protected: // create from serialization only
	CTamGiacDiChuyen7Doc() noexcept;
	DECLARE_DYNCREATE(CTamGiacDiChuyen7Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTamGiacDiChuyen7Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
