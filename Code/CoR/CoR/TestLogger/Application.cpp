#include "Application.h"

#include <iostream>


void Application::RegisterLogger(std::string key, Logger* pLogger) {
	m_Loggers[std::move(key)] = pLogger ;
	m_LoggerVector.push_back(pLogger) ;
}

void Application::OnStart() {
	for(auto l : m_LoggerVector) {
		l->Log("dfsdfsf") ;
	}
	m_Loggers["FILE"]->Log("Application started") ;
}

void Application::ExportFile() {
	m_Loggers["FILE"]->Log("File exported") ;
}

void Application::OnUserLogged() {
	m_Loggers["DB"]->Log("User logged in") ;
}

void Application::OnDataRequested() {
	m_Loggers["DB"]->Log("User requested data") ;
}

void Application::OnExit() {
	m_Loggers["FILE"]->Log("Application terminated") ;
}
