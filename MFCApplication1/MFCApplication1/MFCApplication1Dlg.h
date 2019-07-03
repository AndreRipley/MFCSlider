
// MFCApplication1Dlg.h : header file
//

#pragma once


// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButtonClick();
	afx_msg void OnEditBox();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonUp(UINT a, CPoint b);
	afx_msg void pollEvents();
private:
	CString m_RedSliderEcho;
	CSliderCtrl m_RedSliderCtrl;
	CScrollBar m_RedScrollCtrl;
 
	CSliderCtrl m_BlueSliderCtrl;
	CString m_BlueSliderEcho;
	CButton m_BlueButton;
};
