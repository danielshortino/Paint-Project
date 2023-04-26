#include <iostream>
#include "save-and-load-shapes.h"
#include "program-interface.h"
#include "circle.h"
#include "diamond.h"
#include "rectangle.h"
#include <fstream>

using namespace std;



SaveFile::SaveFile()
{

}

SaveFile::SaveFile(int xx1, int yy1, int xx2, int yy2, int color, bool c_flag, bool d_flag, bool r_flag, bool f_flag)
{
	if (c_flag == true)
	{
		shape = 'C';
	}

	else if (d_flag == true)
	{
		shape = 'D';
	}

	else if (r_flag == true)
	{
		shape = 'R';
	}

	save_fill_flag = f_flag;


	save_x1 = xx1;
	save_y1 = yy1;
	save_x2 = xx2;
	save_y2 = yy2;

	save_color = color;



}


void SaveFile::save_file()
{
	ofstream output_shape("output/shapes.txt", ios::app);


	output_shape << shape << " " << save_x1 << " " << save_y1 << " " << save_x2 << " " << save_y2 << " " << save_color << " " << save_fill_flag << endl;

	output_shape.close();

}

void SaveFile::input_file(int bg_color)
{
	char shape_letter;
	int xx1, yy1, xx2, yy2, color;
	bool filler;

	Interface s;

	s.draw_workspace(bg_color);

	ifstream input_shape("output/shapes.txt");

	while (!input_shape.eof())
	{
		input_shape >> shape_letter >> xx1 >> yy1 >> xx2 >> yy2 >> color >> filler;


		if (shape_letter == 'R')
		{
			MyRectangle R(xx1, yy1, xx2 - xx1, yy2 - yy1, 219, !filler, color, color, "", 0);
			R.Draw();

		}

		else if (shape_letter == 'C')
		{
			MyCircle C(xx1, yy1, ((xx2 - xx1) / 2), color, bg_color, filler);
			C.DrawCircle();
		}

		else if (shape_letter == 'D')
		{
			Diamond D(xx1, yy1, xx2, yy2, xx2 - xx1, color, bg_color, filler);
			D.draw_diamond();
		}
	}

	input_shape.close();
}