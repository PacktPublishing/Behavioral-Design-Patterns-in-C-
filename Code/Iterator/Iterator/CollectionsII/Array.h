#pragma once
#include <initializer_list>
#include "Collection.h"
#include "ArrayIterator.h"
template<typename T>
class Array :
    public Collection<T>
{
	T *m_pBuffer{} ;
	size_t m_Size{} ;
public:
	Array()=default ;
	Array(const std::initializer_list<T> &elements) {
		m_pBuffer = new T[elements.size()] ;
		//Use operator new & placement new instead
		for(auto e : elements) {
			m_pBuffer[m_Size++] = e ;
		}
	}
	~Array() override {
		delete []m_pBuffer ;
	}
	void Add(const T& element) override {
		if(m_Size == 0) {
			m_pBuffer = new T[1]{element} ;
		}else {
			auto temp = new T[m_Size +1 ];
			std::copy(m_pBuffer, &m_pBuffer[m_Size], temp) ;
			temp[m_Size] = element ;
			delete []m_pBuffer ;
			m_pBuffer = temp ;
		}
		++m_Size ;
	}
	const T & operator[](int index)const  {
		return m_pBuffer[index] ;
	}
	T & operator[](int index){
		return m_pBuffer[index] ;
	}
	size_t Size() const override {
		return m_Size ;
	}
	ArrayIterator<T> * CreateIterator()const {
		return new ArrayIterator<T>{m_pBuffer, m_Size} ;
	}
};

