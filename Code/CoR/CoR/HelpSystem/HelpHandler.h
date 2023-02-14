#pragma once
#include <iostream>
#include <string>

class HelpHandler{
public:
	virtual void ShowHelp(const std::string&topic) {
		if(m_pNext) {
			std::cout << "Not available. Moving to next...\n" ;
			m_pNext->ShowHelp(topic) ;
		}else {
			std::cout <<"No help available\n" ;
		}
	}
	void SetSuccessor(HelpHandler *next) {
		m_pNext = next ;
	}

private:
	HelpHandler *m_pNext{} ;
	std::string m_Topic{} ;
};

template<typename T>
void Foo(T a) {
	
}
template void Foo(int) ;