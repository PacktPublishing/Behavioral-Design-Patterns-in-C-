#include <iostream>

#include "Button.h"
#include "Dialog.h"
#include "ListBox.h"
#include "EditBox.h"
#include "RadioGroup.h"

int main() {
	Dialog dlg{} ;
	Button *pButton = dlg.GetButton() ;
	ListBox *pListBox = dlg.GetListBox() ;
	dlg.SetData("Umar", 0) ;
	pButton->Click() ;
	dlg.Display() ;

	dlg.SetData("Ayaan", 0) ;
	pButton->Click() ;
	dlg.Display() ;
	
	dlg.SetData("Seerat", 2) ;
	pButton->Click() ;
	dlg.Display() ;

	pListBox->SelectItem(0) ;
	dlg.Display() ;

	pListBox->SelectItem(2) ;
	dlg.Display() ;
	
}
