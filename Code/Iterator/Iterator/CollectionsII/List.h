#pragma once
#include <initializer_list>

#include "Collection.h"
#include "ListIterator.h"

template<typename T>
class List :
    public Collection <T>
{
	
	size_t m_Size{} ;
public:
	struct Node {
		T m_Data{} ;
		Node *m_pNext{} ;
		Node(const T& mData, Node* mPNext = nullptr)
			: m_Data{mData},
			  m_pNext{mPNext} {
		}
	}*m_pHead;
	List()=default ;
	List(const std::initializer_list<T> elements) {
		auto itr = elements.begin() ;
		Add(*itr++) ;
		auto temp = m_pHead ;
		while(itr != elements.end()) {
			temp->m_pNext = new Node{*itr++} ;
			temp = temp->m_pNext ;
		}
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

	Iterator<T>* CreateIterator() const override;
};

template<typename T>
class ListIterator :
    public Iterator<T>
{
	typename List<T>::Node *m_pHead{} ;
public:
	ListIterator() = default ;
	ListIterator(typename List<T>::Node* mPHead)
		: m_pHead{mPHead} {
	}

	const T& CurrentItem() override {
		return m_pHead->m_Data ;
	}

	bool HasNext() override {
		return m_pHead != nullptr ;
	}

	void Next() override {
		m_pHead = m_pHead->m_pNext ;
	}
};
template<typename T>
Iterator<T>* List<T>::CreateIterator() const {
	return new ListIterator<T>{ m_pHead };
}