#pragma once
#include "Iterator.h"

template<typename Item>
class Aggregate
{
public:
	virtual Iterator<Item> * CreateIterator()const = 0 ;
	virtual ~Aggregate()=default ;
};

