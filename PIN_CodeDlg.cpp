// PIN_CodeDlg.cpp: файл реализации

#include "pch.h"
#include "framework.h"
#include "PIN_Code.h"
#include "PIN_CodeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX){}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Диалоговое окно CPINCodeDlg

INT_PTR CPINCodeDlg::MyDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		// Initialize dialog controls
		return (INT_PTR)TRUE;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			EndDialog(0);
			return (INT_PTR)TRUE;
		}
	}
	case WM_COMMAND:
		// Handle control notifications (e.g., button clicks)
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(0);
			return (INT_PTR)TRUE;
		case IDCANCEL:
			EndDialog(0);
			return (INT_PTR)TRUE;
		}
		break;
	}

}
	return INT_PTR();
}

CPINCodeDlg::CPINCodeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PIN_CODE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPINCodeDlg::DecreaseProgressBar()
{
	auto ts = std::chrono::system_clock::now() + std::chrono::seconds(1);
	auto fiveseconds = std::chrono::system_clock::now() + std::chrono::seconds(5);

	while (true)
	{
		if (ts <= std::chrono::system_clock::now())
		{
			if (fiveseconds <= std::chrono::system_clock::now())
			{
				int currPos = m_ProgressBarFood.GetPos();
				m_ProgressBarFood.SetPos(currPos - 10);
				m_ProgressBarWC.SetPos(currPos - 1);
				fiveseconds = std::chrono::system_clock::now() + std::chrono::seconds(5);
			}
			ts += std::chrono::seconds(1);
		}
	}
}

void CPINCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_FOOD,   m_ProgressBarFood);
	DDX_Control(pDX, IDC_PROGRESS_GAME,   m_ProgressBarGame);
	DDX_Control(pDX, IDC_PROGRESS_WC,     m_ProgressBarWC);
	DDX_Control(pDX, IDC_PROGRESS_HEALTH, m_ProgressBarHealth);
}

BEGIN_MESSAGE_MAP(CPINCodeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON_MAIL, &CPINCodeDlg::OnBnClickedButtonMail)
	ON_BN_CLICKED(IDC_BUTTON_FOOD, &CPINCodeDlg::OnBnClickedButtonFood)
	ON_BN_CLICKED(IDC_BUTTON_HEALTH, &CPINCodeDlg::OnBnClickedButtonHealth)
END_MESSAGE_MAP()


// Обработчики сообщений CPINCodeDlg

BOOL CPINCodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	m_ProgressBarFood.SetRange(0, 100);
	m_ProgressBarFood.SetPos(100);

	m_ProgressBarGame.SetRange(0, 100);
	m_ProgressBarGame.SetPos(100);

	m_ProgressBarWC.SetRange(0, 100);
	m_ProgressBarWC.SetPos(100);

	m_ProgressBarHealth.SetRange(0, 100);
	m_ProgressBarHealth.SetPos(100);

	std::thread th(&CPINCodeDlg::DecreaseProgressBar, this);
	th.detach();
	//AfxBeginThread(IncreaseProgressBar, m_ProgressBarFood, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CPINCodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPINCodeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CPINCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPINCodeDlg::OnBnClickedButtonMail()
{
	PlaySound(TEXT("C:\\Users\\Жижабюте\\Documents\\Visual Studio 2022\\Projects\\PIN_Code\\sounds\\gott.wav"), NULL, SND_FILENAME);
}

void CPINCodeDlg::OnBnClickedButtonFood()
{
	CFoodDialog dlgFood;
	dlgFood.m_progress_bar_food = &m_ProgressBarFood;
	
	dlgFood.DoModal();
	/*DialogBoxThis<CPINCodeDlg, &CPINCodeDlg::MyDlgProc>(this, GetModuleHandle(NULL),
		MAKEINTRESOURCE(IDD_DIALOG_FOOD), this->m_hWnd); */
}

void CPINCodeDlg::OnBnClickedButtonHealth()
{
	CHealthDialog dlgHealth;
	dlgHealth.DoModal();
}
