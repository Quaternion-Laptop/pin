
// PIN_Code.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPINCodeApp:
// Сведения о реализации этого класса: PIN_Code.cpp


class CPINCodeApp : public CWinApp
{
public:
	CPINCodeApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPINCodeApp theApp;
