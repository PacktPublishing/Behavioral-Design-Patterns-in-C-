#include <thread>

#include "Deck.h"
#include "EditorView.h"
#include "Slide.h"
#include "SlideShowView.h"

void CheckChanges(EditorView &ev) {
	using namespace std ;
	while(true) {
		std::this_thread::sleep_for(500ms) ;
		system("cls") ;
		ev.Display() ;
	}
}
int main() {
	Deck deck {} ;
	EditorView ev{&deck} ;
	std::thread pollingThread{CheckChanges, std::ref(ev)} ;
	pollingThread.detach() ;
	deck.AddSlide(std::make_shared<Slide>("Training", "C++ for beginners")) ;
	deck.AddSlide(std::make_shared<Slide>("Objective", "Learn the basics of C++ language")) ;
	deck.AddSlide(std::make_shared<Slide>("What is C++", "C++ is a general purpose programming language")) ;

	//ev.Display() ;

	//SlideShowView sv{&deck} ;
	//sv.Display() ;
	system("pause") ;
	
}
