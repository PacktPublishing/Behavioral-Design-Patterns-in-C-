#include <iostream>

#include "Button.h"
#include "ListBox.h"
#include "EditBox.h"
#include "RadioGroup.h"
void Display(const ListBox &listBox, const EditBox  &editBox, 
	const RadioGroup & radioGroup) {
	std::cout << "[EditBox] -> " << editBox.GetText() << '\n' ;
	std::cout << "[RadioGroup] -> " << radioGroup.GetSelection() << '\n' ;
	std::cout << "[ListBox] -> \n" ;
	listBox.Display() ;
}
int main() {
	ListBox listBox{} ;
	EditBox editBox{} ;
	RadioGroup radioGroup{} ;
	Button button{} ;

	button.SetCommand(&listBox) ;

	listBox.SetEditBox(&editBox) ;
	listBox.SetRadioGroup(&radioGroup) ;

	editBox.SetListBox(&listBox) ;

	editBox.SetText("Umar") ;
	radioGroup.SetSelection(0) ;
	button.Click() ;
	Display(listBox, editBox, radioGroup) ;

	editBox.SetText("Ayaan") ;
	radioGroup.SetSelection(0) ;
	button.Click() ;
	Display(listBox, editBox, radioGroup) ;
	
	editBox.SetText("Seerat") ;
	radioGroup.SetSelection(2) ;
	button.Click() ;
	Display(listBox, editBox, radioGroup) ;

	listBox.SelectItem(2) ;
	Display(listBox, editBox, radioGroup) ;

	
	listBox.SelectItem(0) ;
	Display(listBox, editBox, radioGroup) ;
}
