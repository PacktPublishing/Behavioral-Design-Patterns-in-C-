#include "Circle.h"
#include "Operation.h"

void Circle::Accept(Operation* pOperation) {
	pOperation->VisitCircle(this) ;
}

void Circle::SetPosition(const Point& position) {
	m_Position = position ;
}

void Circle::SetRadius(int radius) {
	m_Radius = radius ;
}

const Point& Circle::GetPosition() const {
	return m_Position ;
}

int Circle::GetRadius() const {
	return m_Radius ;
}

Circle::Circle(const Point& position, int radius): m_Position{position},
                                                   m_Radius{radius} {
}
