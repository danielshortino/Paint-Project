#include "circle.h"
#include <vector>
#include "my-sound.h"

MyCircle::MyCircle(int x, int y, int r, int color, int bg_color, bool filler)
{
    m_x = x;
    m_y = y;
    m_radius = r;
    m_brush_color = color;
    m_background_color = bg_color;
    m_fill = filler;

}


void MyCircle::DrawCircle()
{
    int c = 0;
    int val;
    int counter = 0;

    const int width = m_radius;
    const int length = m_radius; // times 1.5

    int xLimit = 0;
    int yLimit = 0;

    MySound MS;
    MS.Play(L"sounds/scribble.wav", NULL, SND_ASYNC);

    if (m_fill == false)
    {
        for (int yy = width; yy >= -width; yy -= 2)
        {

            gotoxy(m_x, m_y - (length / 2) + counter++);

            xLimit = m_x + (m_radius * 2);
            yLimit = (m_y - (length / 2) + counter);

            if ((xLimit >= 2) && (xLimit <= 72) && (yLimit >= 3) && (yLimit <= 25))
            {

                for (int xx = -length; xx <= length; xx++)
                {
                    val = (int)sqrt(pow(xx, 2) + pow(yy, 2));


                    if (val == m_radius)
                    {

                        SetConsoleTextAttribute(hConsole, m_brush_color);
                        std::cout << char(219);


                    }
                    else
                    {


                        SetConsoleTextAttribute(hConsole, m_background_color);
                        std::cout << char(219);

                    }
                }

            }
        }

    }

    else if (m_fill == true)
    {
        for (int yy = width; yy >= -width; yy -= 2)
        {



            gotoxy(m_x, m_y - (length / 2) + counter++);

            xLimit = m_x + (m_radius * 2);
            yLimit = (m_y - (length / 2) + counter);

            if ((xLimit >= 2) && (xLimit <= 72) && (yLimit >= 3) && (yLimit <= 25))
            {
                for (int xx = -length; xx <= length; xx++)
                {
                    val = (int)sqrt(pow(xx, 2) + pow(yy, 2));


                    if (val == m_radius)
                    {
                        SetConsoleTextAttribute(hConsole, m_brush_color);
                        std::cout << char(219);
                    }
                    else if (val > m_radius)
                    {
                        SetConsoleTextAttribute(hConsole, m_background_color);
                        std::cout << char(219);
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, m_brush_color);
                        std::cout << char(219);
                    }



                }
            }
        }

    }

}
