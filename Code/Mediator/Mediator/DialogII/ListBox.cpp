#include "ListBox.h"

#include <iostream>

int ListBox::GetSelectedItemIndex() const {
	return m_SelectedItem ;
}

void ListBox::AddItem(std::string item) {
	m_Items.push_back(std::move(item)) ;
	SendMessage("ListBox::AddItem") ;
}

void ListBox::SelectItem(int index) {
	m_SelectedItem = index ;
	SendMessage("ListBox::SelectItem") ;
}

const std::string& ListBox::GetSelectedItem() const {
	return m_Items[m_SelectedItem] ;
}

void ListBox::Display() const {
	for(size_t i = 0 ; i < m_Items.size() ; ++i) {
		std::cout << '\t' << m_Items[i] ;
		if(i == m_SelectedItem) {
			std::cout << '*' ;
		}
		std::cout << '\n' ;
	}
	std::cout << '\n' ;
}
