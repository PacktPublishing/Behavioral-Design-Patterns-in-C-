#pragma once
#include <windows.h>


#include "CircleVisitor.h"
#include "LineVisitor.h"
#include "Operation.h"
#include "RectangleVisitor.h"
class Shape;

class Renderer : public Operation, public CircleVisitor, public LineVisitor,
public RectangleVisitor
{
	HWND m_hWnd{} ;

public:
	explicit Renderer(HWND hWnd);
	void VisitCircle(Circle* pCircle) override;
	void VisitLine(Line* pLine) override;
	void VisitRectangle(Rect* pRect) override;
};

