#include "Window.h"
#include "Windowsx.h"

#include <stdexcept>
LRESULT CALLBACK Window::CallBackHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	auto pWin = (WindowProcedure)GetWindowLongPtr(hWnd, GWLP_USERDATA) ;
	switch (message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	if(pWin) {
		return pWin(hWnd, message, wParam, lParam) ;
	}
	return DefWindowProcA(hWnd, message, wParam, lParam) ;
}


HWND Window::GetWindowHandle() {
	return m_hWnd ;
}

void Window::SetWindowProcedure(WindowProcedure wndProc) {
	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG)wndProc) ;
}

Window::Window()
{
	const char *className = "windowclass" ;
	WNDCLASSA wndclass{};
	wndclass.hInstance = GetModuleHandleA(nullptr);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = CallBackHandler;
	wndclass.hIcon = LoadIcon(wndclass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndclass.lpszClassName = className;
	RegisterClassA(&wndclass) ;
	m_hWnd = CreateWindowA(className, "MainWindow", WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		nullptr,
		nullptr,
		wndclass.hInstance, nullptr) ;
	if(!m_hWnd)
	{
		throw std::runtime_error{"Error creating window"} ;
	}
}

void Window::Show()
{
	
	ShowWindow(m_hWnd, SW_SHOWDEFAULT) ;
	UpdateWindow(m_hWnd) ;
}


void Application::Run() {
	
	MSG msg {} ;
	while(GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg) ;
		DispatchMessageA(&msg) ;
	}
}