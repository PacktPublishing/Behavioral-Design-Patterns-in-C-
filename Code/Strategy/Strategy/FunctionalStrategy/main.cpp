#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>

#include <string_view>
#include "SafeVector.h"
void WinPrinter(const std::vector<int>& data) {
	std::ostringstream out{};
	for (const auto& element : data) {
		out << element << ' ';
	}
	MessageBoxA(nullptr, out.str().c_str(), "Data", MB_OK);
}

class Logger {
	std::ofstream m_Output{"elements.txt"};
public:
	void Log(const std::vector<int>& data) {
		std::ostringstream out{};
		for (const auto& element : data) {
			m_Output << element << ' ';
		}
	}
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int) {
	using namespace std::placeholders;
	using namespace std;
	Logger logger;
	SafeVector<int> coll;
	for (int i = 0; i < 100; ++i) {
		coll.Add(i);
	}
	//coll.SetPrinter(WinPrinter) ;
	auto fn = std::bind(&Logger::Log, &logger, _1);

	//fn("Hello") ;
	coll.SetPrinter(fn);
	coll.Print();
}