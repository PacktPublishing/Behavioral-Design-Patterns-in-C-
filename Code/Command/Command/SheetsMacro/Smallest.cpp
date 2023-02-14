#include "Smallest.h"

#include <algorithm>
#include <iostream>

#include "DataList.h"

void Smallest::Execute() {
	auto min = std::min_element(begin(m_pData->GetData()), end(m_pData->GetData())) ;
	if(min != end(m_pData->GetData()))
		std::cout << "Smallest:" << *min << '\n' ;
	else
		std::cout << "Not found\n" ;
}
