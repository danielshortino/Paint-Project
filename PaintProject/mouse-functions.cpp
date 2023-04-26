#include "mouse-functions.h"
#include "controls.h"
#include "program-interface.h"
#include "save-and-load-shapes.h"
#include "my-sound.h"

Mouse::Mouse()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);

    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    hin = GetStdHandle(STD_INPUT_HANDLE);
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);
    SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    buttonX = 1;
    buttonY = 1;
    ReadConsoleInput(hin, &InputRecord, 1, &Events);
}

void Mouse::mouse_input()
{
    ReadConsoleInput(hin, &InputRecord, 1, &Events);
}


void Mouse::button_clicks(int x, int y, int bg)
{
    Interface s;



    if ((x >= 76) && (x <= 98) && (y >= 3) && (y <= 5)) // color palette
    {
        MySound MS;
        MS.Play(L"sounds/flick.wav", NULL, SND_ASYNC);

        brush_color = s.choose_color(x, y, brush_color);

        s.color_button(brush_color);


        if (draw_flag == true)
        {
            s.draw_button(brush_color);
        }

        else if (rectangle_flag == true)
            s.rectangle_button(brush_color);

        else if (diamond_flag == true)
        {
            s.diamond_button(brush_color);
        }

        else if (circle_flag == true)
            s.circle_button(brush_color);

        if (fill_flag == true)
        {
            s.fill_button(brush_color);
        }




    }

    if ((x >= 83) && (x <= 92) && (y == 8)) // BACKGROUND BUTTON
    {
        MySound MS;
        MS.Play(L"sounds/whoosh.wav", NULL, SND_ASYNC);
        background_color = brush_color;
        s.background_button(brush_color);
        s.draw_workspace(brush_color);
    }

    if ((x >= 95) && (x <= 98) && (y == 8)) // FILL BUTTON
    {
        MySound MS;
        MS.Play(L"sounds/flick.wav", NULL, SND_ASYNC);

        switch (fill_flag)
        {
        case true: fill_flag = false;
            s.fill_button(15);
            break;
        default: fill_flag = true;
            erase_flag = false;
            s.erase_button(15);
            s.fill_button(brush_color);
            break;
        }

    }

    if ((x >= 80) && (x <= 84) && (y == 10)) // RESET BUTTON
    {
        MySound MS;
        MS.Play(L"sounds/whoosh.wav", NULL, SND_ASYNC);

        brush_color = 15;
        background_color = 15;
        draw_flag = false;
        fill_flag = false;
        erase_flag = false;
        rectangle_flag = false;
        circle_flag = false;
        diamond_flag = false;
        save_flag = false;
        load_flag = false;
        s.display_interface();
    }


    if ((x >= 86) && (x <= 90) && (y == 10)) // SAVE BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);

        switch (save_flag)
        {
        case true: save_flag = false;
            s.save_button(15);
            break;
        default: save_flag = true;
            s.save_button(brush_color);
            break;
        }
    }

    if ((x >= 91) && (x <= 94) && (y == 10)) // LOAD BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/fairy-dust.wav", NULL, SND_ASYNC);

        brush_color = 15;
        background_color = 15;
        draw_flag = false;
        fill_flag = false;
        erase_flag = false;
        rectangle_flag = false;
        circle_flag = false;
        diamond_flag = false;
        save_flag = false;
        s.display_interface();

        s.draw_workspace(bg);

        SaveFile input_shapes;

        input_shapes.input_file(bg);


    }

    if ((x >= 77) && (x <= 86) && (y == 13)) // DRAW BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);


        switch (draw_flag)
        {
        case true: draw_flag = false;
            s.draw_button(15);
            break;
        default: draw_flag = true;
            erase_flag = false;
            s.draw_button(brush_color);
            s.erase_button(15);
            s.rectangle_button(15);
            circle_flag = false;
            s.circle_button(15);
            s.diamond_button(15);
            break;
        }

    }

    if ((x >= 90) && (x <= 99) && (y == 13)) // ERASE BUTTON
    {


        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);

        switch (erase_flag)
        {
        case true: erase_flag = false;
            s.erase_button(15);
            break;
        default: erase_flag = true;
            draw_flag = false;
            rectangle_flag = false;
            fill_flag = false;
            circle_flag = false;
            diamond_flag = false;
            s.diamond_button(15);
            s.circle_button(15);
            s.erase_button(brush_color);
            s.draw_button(15);
            s.rectangle_button(15);
            s.fill_button(15);
            s.diamond_button(15);
            break;
        }
    }

    if ((x >= 77) && (x <= 97) && (y == 16)) // RECTANGLE BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);


        switch (rectangle_flag)
        {
        case true: rectangle_flag = false;
            s.rectangle_button(15);
            break;
        default: rectangle_flag = true;
            erase_flag = false;
            draw_flag = false;
            circle_flag = false;
            diamond_flag = false;
            s.circle_button(15);
            s.draw_button(15);
            s.erase_button(15);
            s.diamond_button(15);
            s.rectangle_button(brush_color);
            break;
        }
    }

    if ((x >= 77) && (x <= 97) && (y == 19)) // DIAMOND BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);


        switch (diamond_flag)
        {
        case true: diamond_flag = false;
            s.diamond_button(15);
            break;
        default: diamond_flag = true;
            erase_flag = false;
            draw_flag = false;
            circle_flag = false;
            rectangle_flag = false;
            s.circle_button(15);
            s.draw_button(15);
            s.erase_button(15);
            s.rectangle_button(15);
            s.diamond_button(brush_color);
            break;
        }
    }

    if ((x >= 77) && (x <= 97) && (y == 22)) // CIRCLE BUTTON
    {

        MySound MS;
        MS.Play(L"sounds/click.wav", NULL, SND_ASYNC);


        switch (circle_flag)
        {
        case true: circle_flag = false;
            s.circle_button(15);
            break;
        default: circle_flag = true;
            erase_flag = false;
            draw_flag = false;
            rectangle_flag = false;
            diamond_flag = false;
            s.draw_button(15);
            s.erase_button(15);
            s.rectangle_button(15);
            s.diamond_button(15);
            s.circle_button(brush_color);
            break;
        }

    }






}


void Mouse::draw_function()
{
    if ((coord.X >= 2) && (coord.X <= 72) && (coord.Y >= 2) && (coord.Y <= 24)) // DRAWING AREA
    {

        if (draw_flag == true)
        {
            SetConsoleTextAttribute(hConsole, brush_color);
            SetConsoleCursorPosition(hout, coord);
            cout << char(219);
        }

        if (erase_flag == true)
        {
            SetConsoleTextAttribute(hConsole, background_color);
            SetConsoleCursorPosition(hout, coord);
            cout << char(219);
        }

    }
}


Mouse::~Mouse()
{
    FlushConsoleInputBuffer(hin);
}