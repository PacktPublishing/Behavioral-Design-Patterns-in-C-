#include "FindDialog.h"
#include "MainWindow.h"

int main() {
	MainWindow win{} ;
	FindDialog dlg{&win} ;
	dlg.SetSearchText("H") ;
	dlg.Find() ;
}
