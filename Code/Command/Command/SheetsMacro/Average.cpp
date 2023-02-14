#include "Average.h"


#include <iostream>
#include <numeric>

#include "DataList.h"
void Average::Execute() {
	if(m_pData->GetData().empty()) {
		return ;
	}
	auto sum = std::accumulate(begin(m_pData->GetData()), end(m_pData->GetData()), 0) ;
	std::cout << "Average:" << sum/m_pData->GetData().size() << '\n' ;
	
}
