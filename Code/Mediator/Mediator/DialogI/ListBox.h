#pragma once
#include <vector>



#include "Widget.h"

class EditBox ;
class RadioGroup ;
class ListBox :
    public Widget, public Command
{
	std::vector<std::string> m_Items{} ;
	int m_SelectedItem{-1} ;
	EditBox *m_pEditBox{} ;
	RadioGroup *m_pRadioGroup{} ;
public:
	void SetEditBox(EditBox *pEditBox) ;
	void SetRadioGroup(RadioGroup *pRadioGroup) ;
	void AddItem(std::string item) ;
	void SelectItem(int index) ;
	const std::string & GetSelectedItem()const ;
	void Display()const ;

	void OnClick(Widget* pWidget, const std::string& message) override;
};

