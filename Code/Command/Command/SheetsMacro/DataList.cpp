#include "DataList.h"

void DataList::Add(int data) {
	m_Data.push_back(data) ;
}

void DataList::Remove(size_t index) {
	m_Data.erase(begin(m_Data) + index) ;
}

const std::vector<int>& DataList::GetData() const {
	return m_Data ;
}
