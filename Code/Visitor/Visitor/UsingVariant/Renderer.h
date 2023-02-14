#pragma once
#include <windows.h>
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
class Renderer
{
	HWND m_hWnd{} ;

public:
	explicit Renderer(HWND hWnd);
	void operator()(const Circle &circle)const ;
	void operator()(const Rect &rect)const ;
	void operator()(const Line &line)const ;
};

