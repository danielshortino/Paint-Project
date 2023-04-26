#include "rectangle.h"
#include "my-sound.h"

MyRectangle::MyRectangle()
{
	m_x = m_y = m_w = m_h = 0;
	m_symbol = ' ';
	m_hollow = false;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_textColor = m_recColor = 15;
	m_sleepTime = 250;
}

MyRectangle::MyRectangle(int xx, int yy, int ww, int hh, char symbol, bool hollow, int recCol, int txtCol, string txt, int sleepTime) :MyRectangle()
{
	m_x = xx; m_y = yy; m_w = ww; m_h = hh; m_symbol = symbol; m_hollow = hollow; m_recColor = recCol; m_text = txt, m_textColor = txtCol; m_sleepTime = sleepTime;
}

void MyRectangle::Draw()
{
	MySound MS;
	MS.Play(L"sounds/scribble.wav", NULL, SND_ASYNC);


	SetConsoleTextAttribute(hConsole, m_recColor);
	for (int i = 0; i < m_h; i++)
	{
		for (int j = 0; j < m_w; j++)
		{

			gotoxy(m_x + j, m_y + i);

			if (((m_x + j) >= 2) && ((m_x + j) <= 72) && ((m_y + i) >= 2) && ((m_y + i) <= 24))
			{
				if (m_hollow)
				{
					if (i == 0 || i == m_h - 1 || j == 0 || j == m_w - 1)
						cout << m_symbol;
				}
				else
					cout << m_symbol;
			}
		}
	}
	// draw the text if there is one, in the center
	if (m_text != "")
	{
		SetConsoleTextAttribute(hConsole, m_textColor);
		int textLen = m_text.length();
		int midHeight = m_h / 2;
		int midWidth = m_w / 2;
		midWidth = midWidth - (textLen / 2);
		gotoxy(m_x + midWidth, m_y + midHeight);
		cout << m_text;
	}
}

