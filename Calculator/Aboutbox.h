#pragma once


// CAboutbox 对话框

class CAboutbox : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutbox)

public:
	CAboutbox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAboutbox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
