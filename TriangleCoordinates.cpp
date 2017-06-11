#include <iostream>
#include "trianglecoordinates.h"

using namespace std;

TriangleCoordinates::TriangleCoordinates()
{
	height = 60;
	width = 60;
	symbol = '#';
}

TriangleCoordinates::TriangleCoordinates(int h, int w)
{
	height = h;
	width = w;
	symbol = '#';
}

void TriangleCoordinates::Print() const
{
	int diag = 1;
	char row = 'A';
	int topColumn = 2;
	int bottomColumn = 1;

	for (int h = 1; h <= height; h++)
	{
		if (diag > 10)
			diag = 1;

		for (int w = 1; w <= width; w++)
		{
			if (h % 10 == 0 && w == width)
			{
				cout << symbol;
				row++;
			}
			//draw horozontal border
			else if (h % 10 == 1 || h % 10 == 0)
				cout << symbol;
			//draw vertical border
			else if (w % 10 == 1 || w % 10 == 0)
				cout << symbol;
			//draw triangle hypotinuses
			else if (w % 10 == diag)
				cout << symbol;
			//draw a "top" triangle, eg. A2, C6
			else if (h % 10 == 3 && w % 10 == 6)
			{
				cout << row;
				cout << topColumn;
				if (topColumn < 10)
					w++;
				else
					w += 2;
				topColumn += 2;
			}
			//draw a "bottom" triangle, eg. B2, B6
			else if (h % 10 == 8 && w % 10 == 4)
			{
				cout << row;
				cout << bottomColumn;
				if (bottomColumn < 10)
					w++;
				else
					w += 2;
				bottomColumn += 2;
			}
			else
				cout << ' ';
		}
		cout << '\n';
		diag++;
		topColumn = 2;
		bottomColumn = 1;
	}
}
int TriangleCoordinates::GetHeight() const
{
	return height;
}
int TriangleCoordinates::GetWidth() const
{
	return width;
}

bool TriangleCoordinates::SetValue(int h, int w)
{
	height = h;
	width = w;

	return true;
}