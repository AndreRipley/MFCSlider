
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_RedSliderEcho(_T(""))
	,m_BlueSliderEcho(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}


void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Red_EDIT, m_RedSliderEcho);
	DDX_Control(pDX, IDC_RED_SLIDER, m_RedSliderCtrl);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_RedScrollCtrl);

	DDX_Control(pDX, IDC_BLUE_SLIDER, m_BlueSliderCtrl);
	DDX_Text(pDX, IDC_Blue_EDIT, m_BlueSliderEcho);
	DDX_Control(pDX, IDC_BUTTON1, m_BlueButton);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonClick)
	ON_WM_LBUTTONUP()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_RedSliderCtrl.SetRange(0, 255, TRUE);
	m_RedSliderCtrl.SetPos(0);
	m_RedSliderEcho.Format(_T("%d"), 0);

	m_BlueSliderCtrl.SetRange(0, 70000, TRUE);
	m_BlueSliderCtrl.SetPos(0);
	m_BlueSliderEcho.Format(_T("%d"), 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CMFCApplication1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int FinalPosition = 0;
	bool flag = false;
	CSliderCtrl *sliderPtr;

	sliderPtr = (CSliderCtrl*)pScrollBar;
	
	if ((pScrollBar == (CScrollBar *)&m_RedSliderCtrl) || (pScrollBar == (CScrollBar *)&m_BlueSliderCtrl))
	{
		/*int nIndex;
		nIndex = m_RedSliderCtrl.GetPos();
		m_RedSliderEcho.Format(_T("%d"), nIndex);
		UpdateData(FALSE);*/

		int nIndex2;
		nIndex2 = m_BlueSliderCtrl.GetPos();
		
		m_BlueSliderEcho.Format(_T("%d"), nIndex2);
		UpdateData(TRUE);
		FinalPosition = nIndex2;

		
				if (FinalPosition == nIndex2) 
				{
					FinalPosition = sliderPtr->GetPos();
					m_RedSliderEcho.Format(_T("%d"), FinalPosition);
					UpdateData(FALSE);
				}
		
		
	}

	else
	{
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	}

}

void CMFCApplication1Dlg::OnButtonClick() {

	int Full_In = 3000; //FULL IN POSITION
	m_BlueSliderEcho.Format(_T("%d"), Full_In); //ECHO TO BOX
	m_BlueSliderCtrl.SetPos(Full_In);


	UpdateData(FALSE);
}

void CMFCApplication1Dlg::OnEditBox() {
	
}

BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	
	if ((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == VK_RETURN))
	{
		pMsg->wParam = VK_TAB;
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void CMFCApplication1Dlg::OnLButtonUp(UINT a, CPoint cPos)
{
	
}

