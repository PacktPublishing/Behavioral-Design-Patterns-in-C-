#pragma once
#include <vector>

class DataList
{
	std::vector<int> m_Data{} ;
public:
	void Add(int data) ;
	void Remove(size_t index) ;
	const std::vector<int> & GetData()const ;
};

