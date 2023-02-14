#pragma once
#include <windows.h>

#include "Operation.h"
class Shape;

class Renderer : public Operation
{
	HWND m_hWnd{} ;

public:
	explicit Renderer(HWND hWnd);
	void VisitCircle(Circle* pCircle) override;
	void VisitLine(Line* pLine) override;
};

