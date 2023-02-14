#include "Sum.h"
#include <iostream>
#include <numeric>
#include "DataList.h"
void Sum::Execute() {
	auto sum = std::accumulate(begin(m_pData->GetData()), end(m_pData->GetData()), 0) ;
	std::cout << "Sum:" << sum << '\n' ;
}
