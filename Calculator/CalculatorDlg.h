
// CalculatorDlg.h : 头文件
//

#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit7();
	CString m_num1;
	CString m_num2;
	double m_result;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnEnChangeEditNum1();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonCount();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonPower();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonRoot();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonAbout();
	afx_msg void OnBnClickedButtonAboutbox();
	afx_msg void OnEnChangeEditNum2();
	afx_msg void OnEnChangeEditResult();
	double m_show;
	afx_msg void OnEnChangeEdit1();
};
