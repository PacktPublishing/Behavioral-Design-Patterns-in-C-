#include "Largest.h"


#include <algorithm>
#include <iostream>
#include "DataList.h"
void Largest::Execute() {
	auto min = std::max_element(begin(m_pData->GetData()), end(m_pData->GetData())) ;
	if(min != end(m_pData->GetData()))
		std::cout << "Largest:" << *min << '\n' ;
	else
		std::cout << "Not found\n" ;
	
}
