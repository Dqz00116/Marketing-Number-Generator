
// Marketing Number GeneratorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Marketing Number Generator.h"
#include "Marketing Number GeneratorDlg.h"
#include "afxdialogex.h"

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


// CMarketingNumberGeneratorDlg 对话框



CMarketingNumberGeneratorDlg::CMarketingNumberGeneratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MARKETINGNUMBERGENERATOR_DIALOG, pParent)
	, keyWord(_T(""))
	, event(_T(""))
	, cause(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMarketingNumberGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_KW, keyWord);
	DDX_Text(pDX, IDC_EDIT_E, event);
	DDX_Text(pDX, IDC_EDIT_C, cause);
	//  DDX_Text(pDX, IDC_EDIT4, output);
	DDX_Control(pDX, IDC_EDIT_OUT, output);
}

BEGIN_MESSAGE_MAP(CMarketingNumberGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DO, &CMarketingNumberGeneratorDlg::OnBnClickedButtonDo)
END_MESSAGE_MAP()


// CMarketingNumberGeneratorDlg 消息处理程序

BOOL CMarketingNumberGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMarketingNumberGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMarketingNumberGeneratorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMarketingNumberGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMarketingNumberGeneratorDlg::OnBnClickedButtonDo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	CString  op;
	CString comb;
	
	comb = keyWord + event; // 复用的词组
	
	op = comb + _T("是怎么回事呢？") + \
	keyWord + _T("相信大家都很熟悉，但是") + \
	comb + _T("是怎么回事呢？下面就让小编带大家一起了解吧.")\
	_T("为何") + comb + _T("其实就是") + cause + \
	_T(",大家可能会很惊讶") + keyWord +_T("怎么会") + event + \
	+ _T("但事实就是如此，小编也感到十分惊讶.")+ \
	_T("这就是关于") + comb + _T("的事情了,大家有什么想法呢，欢迎在评论区告诉小编一起讨论哦！");
	
	output.SetWindowTextW(op); // 设置生成编辑框的内容

	UpdateData(false);
}
