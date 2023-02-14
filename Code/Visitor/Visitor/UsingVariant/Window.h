#pragma once
#include <vector>
#include <windows.h>
#include "Point.h"
struct Drawable {
	virtual void Draw(HDC hdc) = 0;
	virtual ~Drawable() = default;
};
struct LMBUpHandler {
	virtual void OnLMBUp(HWND hWnd, Point pt) = 0 ;
};
using WindowProcedure = LRESULT  (CALLBACK*)(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
class Window
{
	HWND m_hWnd{};
public:
	HWND GetWindowHandle() ;
	void SetWindowProcedure(WindowProcedure wndProc) ;
	Window();
	void Show();
	static LRESULT CALLBACK CallBackHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

class Application {
	Application()=default ;
public:
	static void Run();
};