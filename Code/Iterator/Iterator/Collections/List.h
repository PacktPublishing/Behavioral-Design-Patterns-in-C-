#pragma once
#include <initializer_list>

#include "Collection.h"
template<typename T>
class List :
    public Collection <T>
{
	struct Node {
		T m_Data{} ;
		Node *m_pNext{} ;
		Node(const T& mData, Node* mPNext = nullptr)
			: m_Data{mData},
			  m_pNext{mPNext} {
		}
	}*m_pHead;
	size_t m_Size{} ;
public:
	List()=default ;
	List(const std::initializer_list<T> elements) {
		auto itr = elements.begin() ;
		Add(*itr++) ;
		auto temp = m_pHead ;
		while(itr != elements.end()) {
			temp->m_pNext = new Node{*itr++} ;
			temp = temp->m_pNext ;
		}
		m_Size = elements.size() ;
	}

	~List() override {
		auto temp= m_pHead ;
		do {
			m_pHead = m_pHead->m_pNext ;
			delete temp ;
			temp = m_pHead ;
		}while(temp != nullptr );
	}

	void Add(const T& element) override {
		if(m_Size == 0) {
			m_pHead = new Node{element} ;
		}else {
			auto temp = new Node{element, m_pHead} ;
			m_pHead = temp ;
		}
		++m_Size ;
	}

	size_t Size() const override {
		return m_Size ;
	}
	Node * GetHead() {
		return m_pHead ;
	}
};

/*
 * 1. Inconsistent API
 * 2. Client has to know the implementation details to access teh elements
 * 3. Internal implementation is exposed to clients
 * 4. They can modify the state of the object without its knowledge. It will make the object invalid
 * 
 */
