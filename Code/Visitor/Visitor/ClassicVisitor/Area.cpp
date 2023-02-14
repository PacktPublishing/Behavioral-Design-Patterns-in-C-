#include "Area.h"

#include <iostream>
#include <numbers>

#include "Circle.h"

void Area::VisitCircle(Circle* pCircle) {
	m_CircleArea = 2 * std::numbers::pi * pCircle->GetRadius() * pCircle->GetRadius() ;
}

void Area::VisitLine(Line* pLine) {
	std::cout << "[Area] Cannot compute area of a line\n" ;
}

float Area::GetCircleArea() const {
	return m_CircleArea ;
}
