#include <fstream>
#include <iostream>


#include "TextDocument.h"
#include "Numbers.h"

void Text() {
	TextDocument text{} ;
	text.SetText("Hello there") ;
	text.Save() ;
	text.Load() ;
	//text.Save() ;
	/*text.SetText("Hello world") ;
	text.Save() ;*/
	//text.Close() ;
	text.Print() ;
}
int main() {
	//Text() ;
	Numbers num{} ;
	//num.SetNumber(10) ;
	//num.Save() ;
	num.Load() ;
	num.Print() ;
	
	
}
