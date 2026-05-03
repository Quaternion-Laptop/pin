#pragma once
#include "afxdialogex.h"


// Диалоговое окно CFoodDialog

class CFoodDialog : public CDialogEx
{
	//DECLARE_DYNAMIC(CFoodDialog)

public:
	CFoodDialog();   // стандартный конструктор
	//virtual ~CFoodDialog();
	afx_msg void OnBnClickedButtonCancel();
	CProgressCtrl* m_progress_bar_food;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FOOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNut();
};
