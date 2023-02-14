#pragma once
#include <string>
#include <stdexcept>
#include <windows.h>
enum class Color { RED, GREEN, BLUE, WHITE };
class Console
{
	inline static HANDLE m_Std;
	static Console m_Instance;
	static WORD GetColor(Color color) {
		switch (color) {
		case Color::RED: return FOREGROUND_RED;
		case Color::GREEN: return FOREGROUND_GREEN;
		case Color::BLUE: return FOREGROUND_BLUE;
		}
		return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	}

	Console() {
		m_Std = GetStdHandle(STD_OUTPUT_HANDLE);
	}
public:
	static void Write(const std::string& text, Color color, bool bold) {
		CONSOLE_SCREEN_BUFFER_INFO csbi{};
		if (!GetConsoleScreenBufferInfo(m_Std, &csbi)) {
			throw std::runtime_error{ "Error while retrieving console information" };
		}
		WORD fgColor = GetColor(color);
		if (bold) {
			fgColor |= FOREGROUND_INTENSITY;
		}
		SetConsoleTextAttribute(m_Std, fgColor);
		DWORD written{};
		WriteConsoleA(m_Std, text.c_str(), text.length(), &written, nullptr);
		SetConsoleTextAttribute(m_Std, csbi.wAttributes);

	}

	static void WriteLine(const std::string& text, Color color, bool bold) {
		Write(text + '\n', color, bold);
	}


};

inline Console Console::m_Instance;

