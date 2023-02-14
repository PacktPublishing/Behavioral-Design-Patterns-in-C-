#include <fstream>
#include <iostream>


#include "Numbers.h"
#include "TextDocument.h"
void Text() {
	TextDocument text{} ;
	text.SetText("Hello there") ;
	text.Save() ;
	text.SetText("Hello world") ;
	text.Save() ;
	text.Print() ;
}
int main() {
	Numbers num{} ;
	//num.SetNumber(10) ;
	//num.Save() ;
	num.Load() ;
	num.Print() ;
	
	
}
