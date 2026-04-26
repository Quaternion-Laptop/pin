// PIN_CodeDlg.h: файл заголовка
#pragma once
#pragma comment(lib, "winmm.lib")

#include <atomic>
#include <thread>
#include <chrono>
#include <Mmsystem.h>
#include <windows.h>
#include <iostream>
#include "CFoodDialog.h"
#include "CHealthDialog.h"

/* infinte loop in separate thread */
struct active_object
{
	template <typename FN> active_object(FN fn) : thread([this, fn] {   while (alive) { fn(); }   }) {}

	~active_object() { alive = false; thread.join(); }
	/*
	active_object(const active_object&) = delete;
	active_object(active_object&&) = delete;
	active_object& operator= (active_object) = delete;

	*/
	std::atomic<bool> alive{ true };
	std::thread thread;
};

template <typename T, INT_PTR(T::* P)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)>
INT_PTR DialogBoxThis(T* pThis, HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent)
{
	return ::DialogBoxParam(hInstance, lpTemplateName, hWndParent, [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> INT_PTR {
		if (uMsg == WM_INITDIALOG) SetWindowLongPtr(hWnd, DWLP_USER, lParam);
		T* pThis = reinterpret_cast<T*>(GetWindowLongPtr(hWnd, DWLP_USER));
		return pThis ? (pThis->*P)(hWnd, uMsg, wParam, lParam) : FALSE;
		}, reinterpret_cast<LPARAM>(pThis));
}

// Диалоговое окно CPINCodeDlg
class CPINCodeDlg : public CDialogEx
{
	INT_PTR MyDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	CProgressCtrl m_ProgressBarFood;
	CProgressCtrl m_ProgressBarGame;
	CProgressCtrl m_ProgressBarWC;
	CProgressCtrl m_ProgressBarHealth;
	CPINCodeDlg(CWnd* pParent = nullptr);	// стандартный конструктор

	void DecreaseProgressBar();
	
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIN_CODE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonMail();
	afx_msg void OnBnClickedButtonFood();
	afx_msg void OnBnClickedButtonHealth();
};
