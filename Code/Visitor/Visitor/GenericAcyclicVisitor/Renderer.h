#pragma once
#include <windows.h>

#include "Operation.h"
#include "OperationVisitor.h"
#include "RectangleVisitor.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
class Shape;

class Renderer : public Operation, public OperationVisitor<Circle>,
public OperationVisitor<Line>,
public OperationVisitor<Rect>
{
	HWND m_hWnd{} ;

public:
	explicit Renderer(HWND hWnd);
	void Visit(Circle* pCircle) override;
	void Visit(Line* pLine) override;
	void Visit(Rect* pRect) override;
};

