#include "Display.h"

#include <iostream>
#include "DataList.h"

void Display::Execute() {
	std::cout <<"\nData : " ;
	for(auto value : m_pData->GetData()) {
		std::cout << value << ' ' ;
	}
	std::cout << '\n' ;
}
