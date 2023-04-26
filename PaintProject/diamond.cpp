#include <iostream>
#include "diamond.h"
#include "Windows.h"
#include "program-interface.h"
#include "my-sound.h"

using namespace std;

Diamond::Diamond(int x1, int y1, int x2, int y2, int row, int color, int bg_color, bool filler)
{
    d_x = x1;
    d_y = y2;
    d_x2 = x2;
    d_y2 = y2;
    row_num = row;
    space = row_num - 1;
    d_color = color;
    d_bg_color = bg_color;
    d_filler = filler;
}

void Diamond::draw_diamond()
{
    MySound MS;
    MS.Play(L"sounds/scribble.wav", NULL, SND_ASYNC);


    Interface s;

    int x = d_x;
    int y = d_y;
    int r = row_num;

    if (d_filler == false)
    {

        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if ((x >= 2) && (x <= 72) && (y >= 2) && (y <= 24))
                {
                    gotoxy(x++, y);
                    if ((j == r - 1) || (j == 0))
                        cout << char(219);
                    else
                    {
                        s.setcolor(d_bg_color);
                        cout << char(219);
                    }

                    s.setcolor(d_color);
                }
            }

            r -= 2;
            y++;
            x = d_x + i + 1;
        }

        r = row_num;
        y = d_y;
        x = d_x;

        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if ((x >= 2) && (x <= 72) && (y >= 2) && (y <= 24))
                {
                    gotoxy(x++, y);

                    if ((j == r - 1) || (j == 0))
                        cout << char(219);
                    else
                    {
                        s.setcolor(d_bg_color);
                        cout << char(219);
                    }
                    s.setcolor(d_color);

                }
            }
            r -= 2;
            y--;
            x = d_x + i + 1;
        }


    }


    if (d_filler == true)
    {

        s.setcolor(d_color);

        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if ((x >= 2) && (x <= 72) && (y >= 2) && (y <= 24))
                {
                    gotoxy(x++, y);
                    cout << char(219);
                }
            }

            r -= 2;
            y++;
            x = d_x + i + 1;
        }

        r = row_num;
        y = d_y;
        x = d_x;

        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if ((x >= 2) && (x <= 72) && (y >= 2) && (y <= 24))
                {
                    gotoxy(x++, y);
                    cout << char(219);
                }
            }

            r -= 2;
            y--;
            x = d_x + i + 1;
        }
    }


}

void Diamond::gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}