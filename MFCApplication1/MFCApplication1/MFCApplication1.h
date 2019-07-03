
// MFCApplication1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplication1App:
// See MFCApplication1.cpp for the implementation of this class
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

class CScrollHelper
{
public:
	CScrollHelper();
	~CScrollHelper();

	// Attach/detach a CWnd or CDialog.
	void   AttachWnd(CWnd* pWnd);
	void   DetachWnd();

	// Set/get the virtual display size.
	// When the dialog or window
	// size is smaller than the display
	// size, then that is when
	// scrollbars will appear. Set either
	// the display width or display
	// height to zero if you don't want to
	// enable the scrollbar in the
	// corresponding direction.
	void   SetDisplaySize(int displayWidth,
		int displayHeight);
	const CSize& GetDisplaySize() const;

	// Get current scroll position.
	// This is needed if you are scrolling
	// a custom CWnd which implements its
	// own drawing in OnPaint().
	const CSize& GetScrollPos() const;

	// Get current page size. Useful
	// for debugging purposes.
	const CSize& GetPageSize() const;

	// Scroll back to top, left, or
	// top-left corner of the window.
	void   ScrollToOrigin(bool scrollLeft,
		bool scrollTop);

	// Message handling.
	void   OnHScroll(UINT nSBCode, UINT nPos,
		CScrollBar* pScrollBar);
	void   OnVScroll(UINT nSBCode, UINT nPos,
		CScrollBar* pScrollBar);
	BOOL   OnMouseWheel(UINT nFlags,
		short zDelta, CPoint pt);
	void   OnSize(UINT nType, int cx, int cy);
};
extern CMFCApplication1App theApp;
