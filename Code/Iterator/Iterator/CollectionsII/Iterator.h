#pragma once
template<class Item>
class Iterator
{
public:
	virtual bool HasNext() = 0 ;
	virtual void Next() = 0;
	virtual const Item & CurrentItem() = 0 ;
	virtual ~Iterator()=default ;
};

