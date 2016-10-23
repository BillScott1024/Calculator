
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include"math.h"
#include"Aboutbox.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_num1(_T(" "))
	, m_num2(_T(" "))
	, m_result()
	, m_show(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM1, m_num1);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_num2);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Text(pDX, IDC_EDIT1, m_show);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_EN_CHANGE(IDC_EDIT_NUM1, &CCalculatorDlg::OnEnChangeEditNum1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_COUNT, &CCalculatorDlg::OnBnClickedButtonCount)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_POWER, &CCalculatorDlg::OnBnClickedButtonPower)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_ROOT, &CCalculatorDlg::OnBnClickedButtonRoot)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalculatorDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDD_ABOUTBOX, &CCalculatorDlg::OnBnClickedButtonAboutbox)
	ON_EN_CHANGE(IDC_EDIT_NUM2, &CCalculatorDlg::OnEnChangeEditNum2)
	ON_EN_CHANGE(IDC_EDIT_RESULT, &CCalculatorDlg::OnEnChangeEditResult)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	
	}
	else
	{
	//	CDialogEx::OnPaint();
			CPaintDC dc(this);
		CBitmap   bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);    //IDB_BITMAP1自己添加
		CBrush   brush;
		brush.CreatePatternBrush(&bitmap);
		CBrush*   pOldBrush = dc.SelectObject(&brush);
		dc.Rectangle(0, 0, 600, 450);   // 调整图片添加位置和大小
		dc.SelectObject(pOldBrush);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
int flag = 0;

void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "2";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "2";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 2;
	
}


void CCalculatorDlg::OnEnChangeEditNum1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 1;
}


void CCalculatorDlg::OnBnClickedButtonCount()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	switch (flag)
	{
	case 1:
		m_result = atof(m_num1.GetBuffer()) + atof(m_num2.GetBuffer());
		m_show = atof(m_num1.GetBuffer()) + atof(m_num2.GetBuffer());
		break;
	case 2:
		m_result = atof(m_num1.GetBuffer()) * atof(m_num2.GetBuffer());
		m_show = atof(m_num1.GetBuffer()) * atof(m_num2.GetBuffer());
		break;
	case 3:
		m_result = atof(m_num1.GetBuffer()) - atof(m_num2.GetBuffer());
		m_show = atof(m_num1.GetBuffer()) - atof(m_num2.GetBuffer());
		break;
	case 4:
		m_result = pow(atof(m_num1.GetBuffer()), atof(m_num2.GetBuffer()));
		m_show = pow(atof(m_num1.GetBuffer()), atof(m_num2.GetBuffer()));
		break;
	case 5:
		m_result = atof(m_num1.GetBuffer()) / atof(m_num2.GetBuffer());
		m_show = atof(m_num1.GetBuffer()) / atof(m_num2.GetBuffer());
		break;
	case 6:
		m_result = pow(atof(m_num1.GetBuffer()), 1.0 / atof(m_num2.GetBuffer()));
		m_show = pow(atof(m_num1.GetBuffer()), 1.0 / atof(m_num2.GetBuffer()));
		break;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 3;
}


void CCalculatorDlg::OnBnClickedButtonPower()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 4;
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 5;
}


void CCalculatorDlg::OnBnClickedButtonRoot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	flag = 6;
	
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "1";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "1";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "3";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "3";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "4";
		m_show = atof(m_num2);
	}
	else{
		m_num1 += "4";
		m_show = atof(m_num1);
}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "5";
		m_show = atof(m_num2);
	}
	else{
		m_num1 += "5";
		m_show = atof(m_num1);
}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "6";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "6";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "7";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "7";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "8";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "8";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "9";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "9";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += "0";
		m_show = atof(m_num2);
	}
	else {
		m_num1 += "0";
		m_show = atof(m_num1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonCe()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_num1 = " ";
	m_num2 = " ";
	m_show = atof(m_num1);
	m_result = NULL;
	flag = 0;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonC()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0){
		m_num2 = m_num2.Left(m_num2.GetLength() - 1);
		m_show = atof(m_num2);
}
	else {
		m_num1 = m_num1.Left(m_num1.GetLength() - 1);
		m_show = atof(m_num1);
	}
	
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (flag > 0) {
		m_num2 += ".";
		m_show = atof(m_num2);
	}
	else{
		m_num1 += ".";
		m_show = atof(m_num1);
}
	UpdateData(FALSE);

}


void CCalculatorDlg::OnBnClickedButtonAboutbox()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutbox m_CalculatorDlg;
	m_CalculatorDlg.DoModal();
}


void CCalculatorDlg::OnEnChangeEditNum2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnChangeEditResult()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
