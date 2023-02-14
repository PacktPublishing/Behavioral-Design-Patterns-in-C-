#include <iostream>
#include <thread>
#include <windows.h>
#include "e:\OneDrive - Poash Technologies/Poash/Training Material/C++/Code/ConsoleColors.h"
std::string pDungeon[41] = {
"H   XXXXXXXXX$XXXXXXXXXXXXXXXXXXXXXXXXX",
"XXX XXXXXXXXX      XXXXXXXXX$   XXXXXXX",
"XXX XXXXXXXXXXXXXX XXXXXXXXXXXX XXXXXXX",
"XXX XXXXXXXXXXXXXX XXXXXXXXXXXX XXXXXXX",
"XXX XXXXXX$        XXXXXXXXXXXX XXXXXXX",
"XXX XXXXXXXXXXXXXX XXXXXXXX        XXXX",
"XXX XXXXXXXXXXXXXX XXXXXXXX XXXXXX XXXX",
"XXX    XXXXXXXXXXX          XXXXXX XXXX",
"XXXXXX XXXXXXXXXXXXXXXXXXXX XXXX   XXXX",
"XXXXXX XXXXX @              XXXX XXXXXX",
"XXXXXX XXXXX XXXXXXXXXXXXXX XXXX XXXXXX",
"XXXXXX XXXXX XXXXXXXXXXXXXX XXXX XXXXXX",
"XXXXXX XXXXX XXXXX          XXXX XXXXXX",
"XXXXXX       XXXXX XXXXXXXXXXXXX    $XX",
"XXXXXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXXXX"
};
void DrawDungeon() {
	Console::SetCursorPosition({ 0, 0 });
	Color color = Color::WHITE;
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < pDungeon[i].size(); ++j) {
			if (pDungeon[i][j] == 'H') {
				color = Color::YELLOW;
			}
			else if (pDungeon[i][j] == 'X') {
				color = Color::WHITE;
			}
			else if (pDungeon[i][j] == '$') {
				color = Color::GREEN;
			}
			else if (pDungeon[i][j] == '@') {
				color = Color::MAGENTA;
			}
			Console::WriteChar(pDungeon[i][j], color);
		}
		Console::WriteLine("");
	}
}
struct KeyInfo {
	bool m_Pressed{};
	unsigned short m_Key{};
};
KeyInfo GetKey() {
	char ch{};
	DWORD cNumRead, i;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD irInBuf[128];
	if (!PeekConsoleInputA(hInput, irInBuf, 128, &cNumRead)) {
		std::cout << "Could not read from console\n";
	}
	for (i = 0; i < cNumRead; i++)
	{
		if (irInBuf[i].EventType == KEY_EVENT)
		{
			auto keventrecord = irInBuf[i].Event.KeyEvent;
			FlushConsoleInputBuffer(hInput);
			return { keventrecord.bKeyDown == 0 ? false : true, keventrecord.wVirtualKeyCode };
		}
	}
	return { false, VK_CLEAR };
}
Position position{ 18, 14 };
void DrawPlayer(Position oldPosition, Position newPosition) {
	if (oldPosition != newPosition) {
		Console::WriteAt(" ", oldPosition);
	}
	Console::WriteAt("+", newPosition, Color::DARKYELLOW);

}
bool WithinBounds(Position newPosition) {
	return (newPosition.x >= 0 && newPosition.x <= 42)
		&& (newPosition.y >= 0 && newPosition.y <= 14);
}
bool CheckPlayerPosition(Position newPosition) {
	Console::WriteAt(newPosition, { 0, 22 });
	if (WithinBounds(newPosition)
		&& pDungeon[newPosition.y][newPosition.x] != 'X') {
		return true;
	}
	Beep(1000, 500);
	return false;

}
void Pickup(Position newPosition) {
	position = newPosition;
	if (pDungeon[newPosition.y][newPosition.x] == '$') {
		//Move & pickup $
		pDungeon[newPosition.y][newPosition.x] = ' ';
	}
	else if (pDungeon[newPosition.y][newPosition.x] == '@') {
		//Check if all $ have been collected otherwise kill
	}
	else if (pDungeon[newPosition.y][newPosition.x] == 'H') {
		//Home!
	}
}


int oldmain() {
	bool running = true;
	while (running) {
		DrawDungeon();
		//CheckPlayerPosition(position);
		auto tempPosition = position;
		//system("cls") ;
		Sleep(200);
		if (auto keyinfo = GetKey(); keyinfo.m_Pressed) {
			switch (keyinfo.m_Key) {
			case VK_LEFT:
				--tempPosition.x;
				break;
			case VK_RIGHT:
				++tempPosition.x;
				break;
			case VK_UP:
				--tempPosition.y;
				break;
			case VK_DOWN:
				++tempPosition.y;
				break;
			case VK_ESCAPE:
				running = false;
				break;
			}
		}
		if (CheckPlayerPosition(tempPosition)) {
			Pickup(tempPosition);
		}

	}
	return 0;
}

#include <windows.h>

void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

int main() {
	HANDLE hStdout, hNewScreenBuffer;
	SMALL_RECT srctReadRect{0, 0, 49, 49};
	SMALL_RECT srctWriteRect{0, 0, 49, 49};
	CHAR_INFO chBuffer[2500];
	COORD coordBufSize{50, 50};
	COORD coordBufCoord{};
	BOOL fSuccess;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hNewScreenBuffer = CreateConsoleScreenBuffer(
		GENERIC_READ |           // read/write access 
		GENERIC_WRITE,
		FILE_SHARE_READ |
		FILE_SHARE_WRITE,        // shared 
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 
	if (hStdout == INVALID_HANDLE_VALUE ||
		hNewScreenBuffer == INVALID_HANDLE_VALUE)
	{
		printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}
	DWORD written{};

	const char *pChar = "Hello" ;
	COORD coord{0,0} ;
	while (true) {
		coord.X++ ;
		SetConsoleCursorPosition(hNewScreenBuffer, coord) ;
		WriteConsoleA(hNewScreenBuffer, pChar, strlen(pChar), &written, nullptr);
		fSuccess = ReadConsoleOutput(
			hNewScreenBuffer,        // screen buffer to read from 
			chBuffer,      // buffer to copy into 
			coordBufSize,   // col-row size of chiBuffer  
			coordBufCoord,  // top left dest. cell in chiBuffer 
			&srctReadRect); // screen buffer source rectangle 
		if (!fSuccess)
		{
			printf("ReadConsoleOutput failed - (%d)\n", GetLastError());
			return 1;
		}
		fSuccess = WriteConsoleOutput(
			hStdout, // screen buffer to write to 
			chBuffer,        // buffer to copy from 
			coordBufSize,     // col-row size of chiBuffer 
			coordBufCoord,    // top left src cell in chiBuffer 
			&srctWriteRect);  // dest. screen buffer rectangle 
		if (!fSuccess)
		{
			printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
			return 1;
		}
		Sleep(100) ;
		cls(hNewScreenBuffer) ;
		
	}
}