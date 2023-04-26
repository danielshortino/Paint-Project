#include "controls.h"


void MyControls::set_x1_y1(int x, int y)
{
	x1 = x;
	y1 = y;
}

void MyControls::set_x2_y2(int xx2, int yy2)
{
	x2 = xx2;
	y2 = yy2;
}

void MyControls::set_brush_color(int c)
{
	brush_color = c;
}

int MyControls::get_x1()
{
	return x1;
}

int MyControls::get_y1()
{
	return y1;
}

int MyControls::get_x2()
{
	return x2;
}

int MyControls::get_y2()
{
	return y2;
}

int MyControls::get_brush_color()
{
	return brush_color;
}

int MyControls::get_background_color()
{
	return background_color;
}

bool MyControls::get_filler()
{
	return fill_flag;
}

bool MyControls::get_rectangle_flag()
{
	return rectangle_flag;
}

bool MyControls::get_diamond_flag()
{
	return diamond_flag;
}

bool MyControls::get_circle_flag()
{
	return circle_flag;
}

bool MyControls::get_save_flag()
{
	return save_flag;
}

bool MyControls::get_load_flag()
{
	return load_flag;
}

