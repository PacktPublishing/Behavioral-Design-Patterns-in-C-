#pragma once
#include "Iterator.h"
//No rule of 5 implemented
template<typename T>
class Collection
{
public:
	virtual void Add(const T &element) = 0 ;
	virtual size_t Size()const= 0;
	virtual ~Collection()=default ;
	virtual Iterator<T> * CreateIterator()const = 0;
};
