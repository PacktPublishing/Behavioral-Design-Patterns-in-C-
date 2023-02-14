#include <iostream>
#include <thread>

#include "Deck.h"
#include "EditorView.h"
#include "Slide.h"
#include "SlideShowView.h"


int main() {
	Deck deck {} ;
	EditorView ev{&deck} ;
	deck.Attach(&ev) ;
	deck.AddSlide(std::make_shared<Slide>("Training", "C++ for beginners")) ;
	deck.AddSlide(std::make_shared<Slide>("Objective", "Learn the basics of C++ language")) ;
	deck.AddSlide(std::make_shared<Slide>("What is C++", "C++ is a general purpose programming language")) ;

	//ev.Display() ;

	SlideShowView sv{&deck} ;
	deck.Attach(&sv) ;
	std::cout << "\nModifying slide # 3\n" ;
	deck.ModifyTitle(2, "Overview") ;
	//sv.Display() ;
	std::cout << "Loading file...\n" ;
	deck.Load() ;
	
}
