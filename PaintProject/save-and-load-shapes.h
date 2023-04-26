#pragma once



class SaveFile
{
private:

	char shape;
	int save_x1, save_y1, save_x2, save_y2;
	int save_color;
	bool save_fill_flag;


public:
	SaveFile();
	SaveFile(int xx1, int yy1, int xx2, int yy2, int color, bool c_flag, bool d_flag, bool r_flag, bool f_flag);

	void input_file(int bg_color);
	void save_file();
};