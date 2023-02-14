#include "Sort.h"

#include <algorithm>
#include <iostream>

#include "DataList.h"
void Sort::Execute() {
	auto sorted = m_pData->GetData() ;
	std::sort(begin(sorted),end(sorted) ) ;
	std::cout <<"Sorted : " ;
	for(auto value : sorted) {
		std::cout << value << ' ' ;
	}
	std::cout << '\n' ;
}
