#pragma once
#include <unordered_map>

#include "FileLogger.h"
#include "DbLogger.h"

class Application
{
	FileLogger m_Logger { "applog.txt"} ;
	DbLogger m_DbLogger{nullptr} ;
	std::vector<Logger*> m_LoggerVector{} ;
	std::unordered_map<std::string, Logger*> m_Loggers{} ;
public:
	void RegisterLogger(std::string key, Logger *) ;
	void OnStart() ;
	void ExportFile() ;
	void OnUserLogged() ;
	void OnDataRequested() ;
	void OnExit() ;
};

void Print(int& ptr) ;