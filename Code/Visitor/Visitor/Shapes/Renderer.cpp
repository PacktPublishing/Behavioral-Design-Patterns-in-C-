#include "Renderer.h"

#include <iostream>


#include "Circle.h"
#include "Line.h"

Renderer::Renderer(HWND hWnd) : m_hWnd{ hWnd } {
}

void Renderer::Draw(Shape* shape) {
	HDC hdc = GetDC(m_hWnd) ;
	if (auto line = dynamic_cast<Line*>(shape)) {
		MoveToEx(hdc, line->GetStart().x, line->GetStart().y, nullptr ) ;
		LineTo(hdc, line->GetEnd().x, line->GetEnd().y) ;
	}
	else if (auto circle = dynamic_cast<Circle*>(shape)) {
		Ellipse(hdc,
			circle->GetPosition().x - circle->GetRadius(),
			circle->GetPosition().y - circle->GetRadius(),
			circle->GetPosition().x + circle->GetRadius(),
			circle->GetPosition().y + circle->GetRadius()
			);
	}
	ReleaseDC(m_hWnd, hdc) ;
}
