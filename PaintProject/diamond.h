#pragma once


class Diamond
{
private:

	int space, row_num, d_color, d_bg_color, d_x, d_y, d_x2, d_y2;
	bool d_filler;

public:
	Diamond(int x, int y, int x2, int y2, int row, int color, int bg_color, bool filler);

	void draw_diamond();
	void gotoxy(int x, int y);

};
