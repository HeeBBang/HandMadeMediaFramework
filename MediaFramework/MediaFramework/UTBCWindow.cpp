#pragma once
#include "UTBCWindow.h"
#include "pch.h"



////생성자
//UTBCWin32BaseWindow::UTBCWin32BaseWindow()
//{
//	Init();
//}

//소멸자
UTBCWin32BaseWindow::~UTBCWin32BaseWindow(void)
{
	Release();
}

//초기화 함수.
HRESULT UTBCWin32BaseWindow::Init(HINSTANCE hInstance, WNDPROC wProc, int nCmdShow)
{
	// Register class
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = wProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = m_wClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);

	//클래스 등록
	if (!RegisterClassEx(&wcex))
	{
		MessageBoxA(NULL, "TestWindow.cpp : RegisterClassEx Error", "HanFW_Error", MB_OK);
		return E_FAIL;
	}

	///////////////////////////////////////
	// Create window
	///////////////////////////////////////
	m_hInst = hInstance;

	//윈도우 사이즈 계산.
	RECT rc = { startX, startY, wWidth + startX, wHeight + startY };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	//윈도우 생성
	m_hWnd = CreateWindow(m_wClassName, m_wName, WS_OVERLAPPEDWINDOW,
		rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
		NULL);
	if (!m_hWnd)
	{
		MessageBoxA(NULL, "TestWindow.cpp : Windows handle Error", "HanFW_Error", MB_OK);
		return E_FAIL;
	}

	//윈도우 보여주기
	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return S_OK;
}

void UTBCWin32BaseWindow::Release(void) 
{ 
	UnregisterClass(m_wClassName, m_hInst); 
}