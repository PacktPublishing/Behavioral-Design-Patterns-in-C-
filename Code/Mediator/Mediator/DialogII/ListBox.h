#pragma once
#include <vector>



#include "Widget.h"

class ListBox :
    public Widget
{
	using Widget::Widget ;
	std::vector<std::string> m_Items{} ;
	int m_SelectedItem{-1} ;
public:
	void AddItem(std::string item) ;
	void SelectItem(int index) ;
	const std::string & GetSelectedItem()const ;
	void Display()const ;
	int GetSelectedItemIndex()const ;

};

