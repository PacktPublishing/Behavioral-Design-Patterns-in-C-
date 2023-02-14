#include "Rect.h"

#include <iostream>
#include "Operation.h"
#include "RectangleVisitor.h"
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

void Rect::Accept(Operation* pOperation) {
	if(auto rect = dynamic_cast<RectangleVisitor*>(pOperation)) {
		rect->VisitRectangle(this) ;
	}else {
		std::cout << "Cannot visit the rectangle\n" ;
	}
}
