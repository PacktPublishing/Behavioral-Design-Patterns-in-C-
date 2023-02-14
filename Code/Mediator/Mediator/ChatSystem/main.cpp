#include <iostream>

#include "ChatServer.h"
#include "Person.h"

int main() {
	ChatServer server{} ;

	Person p1 ;
	p1.SetName("Umar") ;

	Person p2 ;
	p2.SetName("Ayaan") ;

	Person p3 ;
	p3.SetName("Raihaan") ;


	p1.RegisterServer(&server) ;
	p2.RegisterServer(&server) ;
	p3.RegisterServer(&server) ;

	std::cout << "Umar is logging in...\n" ;
	server.Register(p1.GetName(), &p1) ;

	std::cout << "\n\nAyaan is logging in...\n" ;
	server.Register(p2.GetName(), &p2) ;

	std::cout << "\n\nRaihaan is logging in...\n" ;
	server.Register(p3.GetName(), &p3) ;

	std::cout << "\n\nCommunication between participants\n" ;
	p1.Send(p2.GetName(), "Hi there") ;
	p2.Send(p1.GetName(), "Hello") ;
	p3.Send("", "Hi everyone") ;

	server.Deregister(p1.GetName()) ;
}
