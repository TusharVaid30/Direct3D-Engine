#include <Windows.h>

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	const auto pClassName = "WINDOW";

	WNDCLASSEX WND = { 0 };
	WND.cbSize = sizeof(WND);
	WND.style = CS_OWNDC;
	WND.lpfnWndProc = DefWindowProc;
	WND.hInstance = hInstance;
	WND.lpszClassName = pClassName;

	RegisterClassEx(&WND);

	HWND hWnd = CreateWindowEx(0, pClassName,
		"Sloppy Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 1080, 1080,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);

	while (true);

	return 0;
}