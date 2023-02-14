#include "Add.h"

#include <iostream>
#include "DataList.h"
#include "Menu.h"

void Add::Execute() {
	//int data{} ;
	//std::cout << "Data?" ;
	//std::cin >> data ;
	m_pData->Add(rand() % 100)	 ;
}
