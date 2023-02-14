#include "Renderer.h"

#include <iostream>


#include "Circle.h"
#include "Line.h"

Renderer::Renderer(HWND hWnd) : m_hWnd{ hWnd } {
}

void Renderer::operator()(const Circle& circle) const {
	HDC hdc = GetDC(m_hWnd) ;
	Ellipse(hdc,
			circle.GetPosition().x - circle.GetRadius(),
			circle.GetPosition().y - circle.GetRadius(),
			circle.GetPosition().x + circle.GetRadius(),
			circle.GetPosition().y + circle.GetRadius()
			);
	ReleaseDC(m_hWnd, hdc) ;
	
}
void Renderer::operator()(const Line& line) const {
	HDC hdc = GetDC(m_hWnd) ;
	MoveToEx(hdc, line.GetStart().x, line.GetStart().y, nullptr ) ;
	LineTo(hdc, line.GetEnd().x, line.GetEnd().y) ;
	ReleaseDC(m_hWnd, hdc) ;
	
}
void Renderer::operator()(const Rect& rect) const {
	HDC hdc = GetDC(m_hWnd) ;
	Rectangle(hdc, 
		rect.GetTopLeft().x,
		rect.GetTopLeft().y,
		rect.GetBottomRight().x,
		rect.GetBottomRight().y
		) ;
	ReleaseDC(m_hWnd, hdc) ;
	
}


