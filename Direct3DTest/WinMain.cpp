#include <Windows.h>
#include <sstream>
#include <string>

int a;

LRESULT CALLBACK WndProc(
	HWND	hWnd, 
	UINT	msg, 
	WPARAM	wParam, 
	LPARAM	lParam
)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostMessage(hWnd, WM_QUIT, 1, lParam);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			PostMessage(hWnd, WM_QUIT, 1, lParam);
		}
		break;

	case WM_CHAR:
		{
			static std::string title;
			title.push_back((char)wParam);
			SetWindowText(hWnd, title.c_str());
		}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_	 HINSTANCE	hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_	 LPSTR		lpCmdLine,
	_In_	 int		nCmdShow
)
{
	a = 0;

	const auto pClassName = "WINDOW";

	WNDCLASSEX WND = { 0 };
	WND.cbSize = sizeof(WND);
	WND.style = CS_OWNDC;
	WND.lpfnWndProc = WndProc;
	WND.hInstance = hInstance;
	WND.lpszClassName = pClassName;

	RegisterClassEx(&WND);

	HWND hWnd = CreateWindowEx(0, pClassName,
		"Sloppy Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 1080, 1080,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, NULL, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult <= 0)
		return -1;

	return msg.wParam;
}