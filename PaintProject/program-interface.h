#pragma once
#include "coordinates.h"
#include <map>
#include <vector>
#include "controls.h"

class Interface :public Coordinates, public MyControls
{
private:
	HANDLE  hConsole;
	map<int, int> colors;
public:
	Interface();
	void PrintSymbol(int val);
	void MapValueToColor(int v, int clr);
	void Displayshape(vector <int> vec, int columns, int x, int y);
	void display_interface();
	void draw_workspace(int);
	void draw_interface_background();
	void draw_color_palette();
	void draw_button_boxes();

	void reset_save_load_buttons();
	void save_button(int c);

	void background_button(int);
	void fill_button(int);
	void color_button(int);
	void rectangle_button(int);
	void draw_button(int);
	void erase_button(int);
	void diamond_button(int);
	void circle_button(int);

	int choose_color(int x, int y, int bc);
};
