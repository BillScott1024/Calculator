// Aboutbox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "Aboutbox.h"
#include "afxdialogex.h"


// CAboutbox �Ի���

IMPLEMENT_DYNAMIC(CAboutbox, CDialogEx)

CAboutbox::CAboutbox(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAboutbox::~CAboutbox()
{
}

void CAboutbox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutbox, CDialogEx)
END_MESSAGE_MAP()


// CAboutbox ��Ϣ�������
