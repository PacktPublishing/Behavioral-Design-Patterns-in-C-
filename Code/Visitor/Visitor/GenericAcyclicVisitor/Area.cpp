#include "Area.h"

#include <iostream>
#include <numbers>

#include "Circle.h"

void Area::Visit(Circle* pCircle) {
	m_CircleArea = 2 * std::numbers::pi * pCircle->GetRadius() * pCircle->GetRadius() ;
}


float Area::GetCircleArea() const {
	return m_CircleArea ;
}
