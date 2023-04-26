#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "coordinates.h"
#include "controls.h"

using namespace std;

class Mouse : public Coordinates, public MyControls
{
public:
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole;
	HANDLE hout;
	HANDLE hin;
	INPUT_RECORD InputRecord;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	int buttonX, buttonY;

public:
	Mouse();
	~Mouse();
	void mouse_input();
	void button_clicks(int x, int y, int bg);
	void draw_function();

};