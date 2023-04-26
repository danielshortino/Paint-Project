/*
	Daniel Shortino
	CS M125 72508
	27 NOV 2022

*/

#include <iostream>
#include "controls.h"
#include "program-interface.h"
#include "mouse-functions.h"
#include "rectangle.h"
#include "diamond.h"
#include "circle.h"
#include "save-and-load-shapes.h"
#include "my-sound.h"

using namespace std;

int loops = 0;

int main()
{
	Mouse M;


	Interface elements;
	elements.display_interface();



	while (1)
	{

		M.mouse_input();


		switch (M.InputRecord.EventType)
		{

		case MOUSE_EVENT:

			if (M.InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // LEFT CLICKS
			{
				M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
				M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;

				M.set_x1_y1(M.coord.X, M.coord.Y);

				M.button_clicks(M.coord.X, M.coord.Y, M.get_background_color());

				M.draw_function();

			}

			else if (M.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // RIGHT CLICKS
			{
				M.coord.X = M.InputRecord.Event.MouseEvent.dwMousePosition.X;
				M.coord.Y = M.InputRecord.Event.MouseEvent.dwMousePosition.Y;

				M.set_x2_y2(M.coord.X, M.coord.Y);

				if (M.get_rectangle_flag() == true)
				{
					MyRectangle R(M.get_x1(), M.get_y1(), M.get_x2() - M.get_x1(), M.get_y2() - M.get_y1(), 219, !M.get_filler(), M.get_brush_color(), 0, "", 0);
					R.Draw();
				}
				else if (M.get_diamond_flag() == true)
				{
					Diamond D(M.get_x1(), M.get_y1(), M.get_x2(), M.get_y2(), M.get_x2() - M.get_x1(), M.get_brush_color(), M.get_background_color(), M.get_filler());
					D.draw_diamond();
				}
				else if (M.get_circle_flag() == true)
				{
					MyCircle C(M.get_x1(), M.get_y1(), ((M.get_x2() - M.get_x1()) / 2), M.get_brush_color(), M.get_background_color(), M.get_filler());
					C.DrawCircle();
				}

				if (M.get_save_flag() == true)
				{
					SaveFile SF(M.get_x1(), M.get_y1(), M.get_x2(), M.get_y2(), M.get_brush_color(), M.get_circle_flag(), M.get_diamond_flag(), M.get_rectangle_flag(), M.get_filler());
					SF.save_file();
				}

			}
			break;
		default:
			break;
		}
	
	}

}

