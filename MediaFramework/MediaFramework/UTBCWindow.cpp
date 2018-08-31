#pragma once
#include "UTBCWindow.h"
#include "pch.h"



////������
//UTBCWin32BaseWindow::UTBCWin32BaseWindow()
//{
//	Init();
//}

//�Ҹ���
UTBCWin32BaseWindow::~UTBCWin32BaseWindow(void)
{
	Release();
}

//�ʱ�ȭ �Լ�.
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

	//Ŭ���� ���
	if (!RegisterClassEx(&wcex))
	{
		MessageBoxA(NULL, "TestWindow.cpp : RegisterClassEx Error", "HanFW_Error", MB_OK);
		return E_FAIL;
	}

	///////////////////////////////////////
	// Create window
	///////////////////////////////////////
	m_hInst = hInstance;

	//������ ������ ���.
	RECT rc = { startX, startY, wWidth + startX, wHeight + startY };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	//������ ����
	m_hWnd = CreateWindow(m_wClassName, m_wName, WS_OVERLAPPEDWINDOW,
		rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
		NULL);
	if (!m_hWnd)
	{
		MessageBoxA(NULL, "TestWindow.cpp : Windows handle Error", "HanFW_Error", MB_OK);
		return E_FAIL;
	}

	//������ �����ֱ�
	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return S_OK;
}

void UTBCWin32BaseWindow::Release(void) 
{ 
	UnregisterClass(m_wClassName, m_hInst); 
}