#include <ctime>
#include <memory>

#include "Add.h"
#include "Average.h"
#include "Composite.h"
#include "DataList.h"
#include "Display.h"
#include "Largest.h"
#include "Smallest.h"
#include "Menu.h"
#include "Remove.h"
#include "Sort.h"
#include "Sum.h"

int main() {
	srand(time(nullptr)) ;
	DataList data{} ;
	Menu menu ;
	auto display  = std::make_shared<Display>(&data) ;
	auto add      = std::make_shared<Add>(&data);
	auto remove   = std::make_shared<Remove>(&data);
	auto smallest = std::make_shared<Smallest>(&data);
	auto largest  = std::make_shared<Largest>(&data);
	auto avg      = std::make_shared<Average>(&data);
	auto sort     = std::make_shared<Sort>(&data);
	auto sum      = std::make_shared<Sum>(&data);
	auto macro    = std::make_shared<Composite>();

	macro->Add(avg) ;
	macro->Add(sum) ;
	macro->Add(smallest) ;
	macro->Add(largest) ;
	
	menu.Init(0, "",			display		) ;
	menu.Init(1, "Add",			add) ;
	menu.Init(2, "Remove",		remove) ;
	menu.Init(3, "Smallest",	smallest) ;
	menu.Init(4, "Largest",		largest) ;
	menu.Init(5, "Average",		avg) ;
	menu.Init(6, "Sort",		sort) ;
	menu.Init(7, "Sum",			sum) ;
	menu.Init(8, "Exec Macro",	macro) ;
	menu.Run() ;
	//
	//Add add{&data} ;
	//for(int i = 0 ; i < 8 ; ++i) {
	//	add.Execute() ;
	//}
	////disp.Execute() ;
	//Average avg{&data} ;
	////avg.Execute() ;

	//Largest lg{&data} ;
	//lg.Execute() ;
	////disp.Execute() ;


	//Composite macro{} ;
	//macro.Add(&disp) ;
	//macro.Add(&lg) ;
	//macro.Add(new Smallest{&data}) ;
	//macro.Add(&avg) ;

	//macro.Execute() ;
	
}
