#pragma once
#include "afxdialogex.h"


// Диалоговое окно 

class CHealthDialog : public CDialogEx
{
	//DECLARE_DYNAMIC(CHealthDialog)

public:
	CHealthDialog();   // стандартный конструктор
	//virtual ~CHealthDialog();
	afx_msg void OnBnClickedButtonCancel();
	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HEALTH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSpritz();
};
