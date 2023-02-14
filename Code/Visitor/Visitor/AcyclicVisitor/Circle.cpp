#include "Circle.h"

#include <iostream>


#include "CircleVisitor.h"
#include "Operation.h"

void Circle::Accept(Operation* pOperation) {
	if(auto circle = dynamic_cast<CircleVisitor*>(pOperation)) {
		circle->VisitCircle(this) ;
	}else {
		std::cout << "Cannot visit the circle\n" ;
	}
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
