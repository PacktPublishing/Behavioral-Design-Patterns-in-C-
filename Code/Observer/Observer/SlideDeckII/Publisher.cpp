#include "Publisher.h"
#include "View.h"
void Publisher::RegisterView(View* pView) {
	m_Views.push_back(pView) ;
}

void Publisher::DeregisterView(View* pView) {
	m_Views.remove(pView) ;
}

void Publisher::Notify(int index) {
	for(auto view : m_Views) {
		view->Display(index) ;
	}
}
