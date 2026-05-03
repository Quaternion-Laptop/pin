// CFoodDialog.cpp: файл реализации
//

#include "pch.h"
#include "PIN_Code.h"
#include "afxdialogex.h"
#include "CFoodDialog.h"
#include "playsoundapi.h"

// Диалоговое окно CFoodDialog

CFoodDialog::CFoodDialog() : CDialogEx(IDD_DIALOG_FOOD){}

void CFoodDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFoodDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CFoodDialog::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_NUT, &CFoodDialog::OnBnClickedButtonNut)
END_MESSAGE_MAP()


// Обработчики сообщений CFoodDialog

void CFoodDialog::OnBnClickedButtonCancel()
{
	EndDialog(IDD_DIALOG_FOOD);
}

void CFoodDialog::OnBnClickedButtonNut()
{
	PlaySound(TEXT("C:\\Users\\Жижабюте\\Documents\\Visual Studio 2022\\Projects\\PIN_Code\\sounds\\hrust.wav"), NULL, SND_FILENAME);
	int curr_pos = m_progress_bar_food->GetPos();
	m_progress_bar_food->SetPos(curr_pos + 10);
}
