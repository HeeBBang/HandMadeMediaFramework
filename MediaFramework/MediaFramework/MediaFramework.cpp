// MediaFramework.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#pragma once

#include "pch.h"
#include <iostream>
#include <gl/gl.h>


extern "C" {
#include <libavutil/log.h>
#include <libavformat/avformat.h>
}

#pragma comment ( lib, "avcodec.lib" )
#pragma comment ( lib, "avdevice.lib")
#pragma comment ( lib, "avfilter.lib")
#pragma comment ( lib, "avformat.lib")
#pragma comment ( lib, "avutil.lib")
#pragma comment ( lib, "postproc.lib")
#pragma comment ( lib, "swresample.lib")
#pragma comment ( lib, "swscale.lib")

//int main()
//{
//    std::cout << "Hello World!\n"; 
//	
//	//av_log(NULL, 0, "Hello FFmpeg\n");
//	//av_calloc(0, 0);
//
//	return 0;
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


//--------------------------------------------------------------------------------------
//윈도우 프로시져
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void f_MessageLoop()
{
	// Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		//Peek로 수행해서 wait따위 하지 않는다
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//렌더단이 들어갈곳
			
		}
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//파라메터 초기화 관련 warning 막아줌
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//윈도우 객체 생성
	UTBCWin32BaseWindow *wnd = new UTBCWin32BaseWindow("Hanneoul Window Class", "Hanneoul Game Framework 2.0", hInstance, WndProc, nCmdShow, 100, 100, 1024, 768);
	
	// Main message loop
	f_MessageLoop();
		
	SAFE_DELETE(wnd); //동적할당 해제

	return 0;// (int)msg.wParam을 보통 리턴하는데 그럴 필요 없음;

}