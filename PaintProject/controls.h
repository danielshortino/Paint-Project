#pragma once


class MyControls
{
protected:

	int x1, y1, x2, y2;

	bool save_flag = false;
	bool load_flag = false;

	int brush_color = 15;
	int background_color = 15;

	bool draw_flag = false;
	bool erase_flag = false;

	bool fill_flag = false;

	bool rectangle_flag = false;
	bool diamond_flag = false;
	bool circle_flag = false;


public:

	void set_x1_y1(int x, int y);
	void set_x2_y2(int x2, int y2);

	void set_brush_color(int c);

	int get_x1();
	int get_y1();
	int get_x2();
	int get_y2();

	int get_brush_color();
	int get_background_color();

	bool get_filler();

	bool get_rectangle_flag();
	bool get_diamond_flag();
	bool get_circle_flag();

	bool get_save_flag();
	bool get_load_flag();


};
