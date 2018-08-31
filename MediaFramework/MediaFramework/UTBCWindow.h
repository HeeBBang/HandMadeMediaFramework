#pragma once
#include <Windows.h>


//�޸� new����
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
	HWND m_hWnd;		//������ �ڵ鷯
	HINSTANCE m_hInst;	//�ν��Ͻ�

	LPCSTR m_wClassName;//���� Ŭ���� �̸�
	LPCSTR m_wName;//������ Ÿ��Ʋ�� �̸�

				   //������ ��������Ʈ
	int startX;
	int startY;

	//������ ũ��
	int wWidth;
	int wHeight;



public:
	//������ �Ҹ���
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


	//�ʱ�ȭ �Լ�.
	HRESULT Init(HINSTANCE hInstance, WNDPROC wProc, int nCmdShow);
	//�޸� ����
	void Release(void);

	HWND GetHandle(void) { return m_hWnd; };
	int GetViewSizeX(void) { return wWidth; };
	int GetViewSizeY(void) { return wHeight; };
};