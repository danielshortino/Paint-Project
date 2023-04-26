#pragma once
#include "coordinates.h"

class MyCircle : public Coordinates
{
public:
	int m_x, m_y, m_radius, m_brush_color, m_background_color;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	MyCircle(int x, int y, int r, int color, int bg_color, bool filler);
	void DrawCircle();
	bool m_fill;
};

