#include <forward_list>
#include <iostream>

#include "Array.h"
#include "List.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	List<int> numbers {1,2,3,4} ;
	numbers.Add(5) ;
	numbers.Add(6) ;

	auto node = numbers.GetHead() ;
	node->m_pNext = node->m_pNext->m_pNext ;
	auto head = numbers.GetHead() ;
	while(head != nullptr) {
		std::cout << head->m_Data << ' ' ;
		head = head->m_pNext ;
	}
	std::cout << "\nSize:" << numbers.Size() ;
	/*for(size_t i = 0 ; i < numbers.Size() ; ++i) {
		std::cout << numbers[i] << ' ' ;
	}*/
}
