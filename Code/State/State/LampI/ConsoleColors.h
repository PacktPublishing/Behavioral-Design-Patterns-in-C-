/*
 * Requires Win32 & C++17
 * Umar Lone
 * Copyright Poash Techhnologies
 */



#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <windows.h>
enum class Color :unsigned short {
    BLACK             = 0,
    DARKBLUE          = FOREGROUND_BLUE,
    DARKGREEN         = FOREGROUND_GREEN,
    DARKCYAN          = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED           = FOREGROUND_RED,
    DARKMAGENTA       = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW        = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY          = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY              = FOREGROUND_INTENSITY,
    BLUE              = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN             = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN              = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED               = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA           = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW            = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE             = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};
struct Position {
	short x ;
	short y ;
	friend std::ostream & operator<<(std::ostream &out, Position pt) {
		return std::cout << "{" << pt.x << ',' << pt.y <<"}" ;
	}
	operator std::string () {
		std::ostringstream out ;
		out << "{" << x << ',' << y <<"}" ;
		return out.str() ;
	}
	friend bool operator == (Position left, Position right) {
		return left.x == right.x && left.y == right.y ;
	}
	friend bool operator != (Position left, Position right) {
		return !(left == right) ;
	}
};
class Console
{
	inline static HANDLE m_Std;
	static Console m_Instance;
	static WORD GetColor(Color color) {
		return static_cast<unsigned short>(color) ;
	}

	Console() {
		m_Std = GetStdHandle(STD_OUTPUT_HANDLE);
	}
public:
	static void SetCursorPosition(Position position) {
		SetConsoleCursorPosition(m_Std, {position.x, position.y}) ;
	}
	static void WriteChar(char ch, Color color = Color::WHITE, bool bold = false) {
		Write({ch}, color, bold) ;
	}
	static void WriteAt(const std::string &text, Position position, Color color = Color::WHITE, bool bold=false) {
		SetCursorPosition(position) ;
		Write(text, color, bold) ;
	}
	static void Write(const std::string& text, Color color= Color::WHITE, bool bold=false) {
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

	static void WriteLine(const std::string& text, Color color= Color::WHITE, bool bold=false) {
		Write(text + '\n', color, bold);
	}


};

inline Console Console::m_Instance;

