#include "Rect.h"

Rect::Rect(const Point& topLeft, const Point& bottomRight): m_TopLeft{topLeft},
                                                            m_BottomRight{bottomRight} {
}

const Point& Rect::GetTopLeft() const {
	return m_TopLeft ;
}

const Point& Rect::GetBottomRight() const {
	return m_BottomRight ;
}

void Rect::SetTopLeft(const Point& topLeft) {
	m_TopLeft = topLeft ;
}

void Rect::SetBottomRight(const Point& bottomRight) {
	m_BottomRight = bottomRight ;
}
