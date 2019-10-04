
// TamGiacDiChuyen7.h : main header file for the TamGiacDiChuyen7 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTamGiacDiChuyen7App:
// See TamGiacDiChuyen7.cpp for the implementation of this class
//

class CTamGiacDiChuyen7App : public CWinAppEx
{
public:
	CTamGiacDiChuyen7App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTamGiacDiChuyen7App theApp;
