#include "Remove.h"

#include <iostream>
#include "DataList.h"
void Remove::Execute() {
	int index{} ;
	std::cout << "Remove at index?" ;
	std::cin >> index ;
	m_pData->Remove(index)	 ;
}
