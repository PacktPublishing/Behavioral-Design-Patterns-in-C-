#include "Renderer.h"



#include "Circle.h"
#include "Line.h"
#include "Rect.h"

Renderer::Renderer(HWND hWnd) : m_hWnd{ hWnd } {
}

void Renderer::Visit(Circle* circle) {
	HDC hdc = GetDC(m_hWnd);
	Ellipse(hdc,
		circle->GetPosition().x - circle->GetRadius(),
		circle->GetPosition().y - circle->GetRadius(),
		circle->GetPosition().x + circle->GetRadius(),
		circle->GetPosition().y + circle->GetRadius()
	);
	ReleaseDC(m_hWnd, hdc);

}
void Renderer::Visit(Line* line) {
	HDC hdc = GetDC(m_hWnd);
	MoveToEx(hdc, line->GetStart().x, line->GetStart().y, nullptr);
	LineTo(hdc, line->GetEnd().x, line->GetEnd().y);
	ReleaseDC(m_hWnd, hdc);
}

void Renderer::Visit(Rect* pRect) {
	HDC hdc = GetDC(m_hWnd);
	Rectangle(hdc, 
		pRect->GetTopLeft().x,
		pRect->GetTopLeft().y,
		pRect->GetBottomRight().x,
		pRect->GetBottomRight().y
		) ;
	ReleaseDC(m_hWnd, hdc);
	
}
