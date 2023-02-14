#pragma once
#include <windows.h>
class Shape;

class Renderer
{
	HWND m_hWnd{} ;

public:
	explicit Renderer(HWND hWnd);
	void Draw(Shape *pShape) ;
};

