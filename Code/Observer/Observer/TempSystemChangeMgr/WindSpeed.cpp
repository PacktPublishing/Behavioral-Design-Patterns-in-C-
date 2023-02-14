#include "WindSpeed.h"

void WindSpeed::SetSpeed(float speed) {
	m_Speed = speed ;
	Notify() ;
}

std::string WindSpeed::GetType() const {
	return "windspeed" ;
}

std::any WindSpeed::GetValue() {
	return std::make_any<float>(m_Speed) ;
}
