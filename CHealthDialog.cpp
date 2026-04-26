

#include "pch.h"
#include "PIN_Code.h"
#include "afxdialogex.h"
#include "CHealthDialog.h"
#include "playsoundapi.h"

// Диалоговое окно 

CHealthDialog::CHealthDialog() : CDialogEx(IDD_DIALOG_HEALTH) {}

void CHealthDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHealthDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CHealthDialog::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_SPRITZ, &CHealthDialog::OnBnClickedButtonSpritz)
END_MESSAGE_MAP()


// Обработчики сообщений CFoodDialog

void CHealthDialog::OnBnClickedButtonCancel()
{
	EndDialog(IDD_DIALOG_FOOD);
}

void CHealthDialog::OnBnClickedButtonSpritz()
{
	PlaySound(TEXT("C:\\Users\\Жижабюте\\Documents\\Visual Studio 2022\\Projects\\PIN_Code\\sounds\\health.wav"), NULL, SND_FILENAME);
}

