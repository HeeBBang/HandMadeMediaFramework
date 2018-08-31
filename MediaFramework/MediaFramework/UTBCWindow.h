#pragma once
#include <Windows.h>


//메모리 new해제
#ifndef SAFE_DELETE
#define SAFE_DELETE(p)\
if (p != NULL) \
{\
	delete (p); \
	(p) = NULL; \
}
#endif   


class UTBCWin32BaseWindow
{

private:
	HWND m_hWnd;		//윈도우 핸들러
	HINSTANCE m_hInst;	//인스턴스

	LPCSTR m_wClassName;//윈도 클래스 이름
	LPCSTR m_wName;//윈도우 타이틀바 이름

				   //윈도우 시작포인트
	int startX;
	int startY;

	//윈도우 크기
	int wWidth;
	int wHeight;



public:
	//생성자 소멸자
	UTBCWin32BaseWindow(LPCSTR wName, LPCSTR wClassName, HINSTANCE hInstance, WNDPROC wProc, int nCmdShow, UINT startPosX, UINT startPosY, UINT width, UINT height)
		: m_hWnd(NULL),
		m_hInst(NULL),
		m_wClassName(wClassName),
		m_wName(wName),
		startX(startPosX),
		startY(startPosY),
		wWidth(width),
		wHeight(height)
	{
		Init(hInstance, wProc, nCmdShow);
	};
	~UTBCWin32BaseWindow(void);


	//초기화 함수.
	HRESULT Init(HINSTANCE hInstance, WNDPROC wProc, int nCmdShow);
	//메모리 해제
	void Release(void);

	HWND GetHandle(void) { return m_hWnd; };
	int GetViewSizeX(void) { return wWidth; };
	int GetViewSizeY(void) { return wHeight; };
};