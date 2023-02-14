#pragma once
#include "Iterator.h"
template<typename T>
class ArrayIterator :
    public Iterator<T>
{
	T *m_pBuffer{} ;
	size_t m_TotalElements{} ;
	size_t m_Position{} ;
public:
	ArrayIterator()=default ;
	ArrayIterator(T *ptr, size_t size):m_pBuffer{ptr}, m_TotalElements{size}{
	}
	const T& CurrentItem() override {
		return m_pBuffer[m_Position] ;
	}

	bool HasNext() override {
		return m_Position != m_TotalElements ;
	}

	void Next() override {
		++m_Position ;
	}
} ;


