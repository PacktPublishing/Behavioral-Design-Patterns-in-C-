#include <forward_list>
#include <iostream>

#include "Array.h"
#include "List.h"

void Print(Iterator<int> *itr) {
	while(itr->HasNext()) {
		std::cout << itr->CurrentItem() << ' ';
		itr->Next() ;
	}
	std::cout << '\n' ;
	delete itr ;
}
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	Array<int> numbers1 {1,2,3,4} ;
	numbers1.Add(5) ;
	numbers1.Add(6) ;

	//List<int>::Node *p ;
	//auto head = numbers.GetHead() ;
	/*while(head != nullptr) {
		std::cout << head->m_Data << ' ' ;
		head = head->m_pNext ;
	}*/
	Print(numbers1.CreateIterator()) ;

	List<int> numbers {1,2,3,4} ;
	numbers.Add(5) ;
	numbers.Add(6) ;
	Print(numbers.CreateIterator()) ;
}
