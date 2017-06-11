#include <iostream>
#include "trianglecoordinates.h"

using namespace std;

void PrintOptions();
void GetSelection();

TriangleCoordinates CreateNewMap();			//create a new map!
void UpdateMap(TriangleCoordinates &tc);	//update the width and height of the map
void FindTriangleFromCoordinates(TriangleCoordinates tc);			//find which triangle a set of coordinates lie in
void PrintMap(TriangleCoordinates tc);		//print the map with current width/height
bool triangleExists = false;				//global variable to ensure no more than 1 map is created
TriangleCoordinates triangleCoordinates;	//global map to use for the life of the program
bool loop = true;							//while loop control global

//main
void main()
{
	cout << "Hello! Lets calculate some triangle coordinates! For best use please maximise your console screen so it is possible to see all the text" << endl;
	while (loop)
	{
		PrintOptions();
		GetSelection();
	}
	return;
}

//prints list of selectable options
void PrintOptions()
{
	cout << "Please choose from the following options by entering 1-5:" << endl;
	cout << "1.) Create a new TriangleCoordinates Map." << endl;
	cout << "2.) Update your current TriangleCoordinates map values." << endl;
	cout << "3.) Print the map!" << endl;
	cout << "4.) Insert some vertex coordinates and find which triangle it is in the map." << endl;
	cout << "5.) Exit the program." << endl;
}

//grabs user selection and allocated what to do with the selection
void GetSelection()
{
	int selection = 0;

	cin >> selection;
	//49 and 57 are decimal for '1' and '9'
	if (selection >= 1 && selection <= 9)
	{
		switch (selection)
		{
		case (1): 
			if (triangleExists)
			{
				cout << "You've already created a triangle coordinates map, now use it!" << endl;
				break;
			}
			else
				triangleCoordinates = CreateNewMap();
				break;
			break;
		case (2): UpdateMap(triangleCoordinates);
			break;
		case (3): PrintMap(triangleCoordinates);
			break;
		case (4): FindTriangleFromCoordinates(triangleCoordinates);
			break;
		case (5): loop = false;
		}
	}
	else
	{
		cout << "You have selected an incorrect number!";
	}
}

//creates a new map, it is assumed that one hasn't been created already
TriangleCoordinates CreateNewMap()
{
	int selection = 0;
	int height = 0;
	int width = 0;
	char symbol = '$';

	while (selection != 1 && selection != 2)
	{
		cout << "Press 1 to automatically create a 60x60 map, or 2 to input your own sizes." << endl;
		cin >> selection;
	}

	if (selection == 1)
	{
		height = 60;
		width = 60;
	}
	else if (selection == 2)
	{
		while (height == 0 || height % 10 != 0 || height < 10 || height > 100)
		{
			cout << "Please enter the height. It is limited to increments of 10, between 10-100:" << endl;
			cin >> height;
		}
		while (width == 0 || width % 10 != 0 || width < 10 || width > 100)
		{
			cout << "Please enter the width. It is limited to increments of 10, between 10-100:" << endl;
			cin >> width;
		}
	}
	TriangleCoordinates tc(height, width);
	triangleExists = true;
	return tc;
}

//update width and height of the map
void UpdateMap(TriangleCoordinates &tc)
{
	int selection = 0;
	int height = 0;
	int width = 0;
	char symbol = '$';

	if (!triangleExists)
	{
		cout << "You must create a triangle coordinates map first!" << endl;
		return;
	}

	while (height == 0 || height % 10 != 0 || height < 10 || height > 100)
	{
		cout << "Please enter the height. It is limited to increments of 10, between 10-100:" << endl;
		cin >> height;
	}
	while (width == 0 || width % 10 != 0 || width < 10 || width > 100)
	{
		cout << "Please enter the width. It is limited to increments of 10, between 10-100:" << endl;
		cin >> width;
	}

	tc.SetValue(height, width);
}

//finds which triangle is in a list of coordinates
void FindTriangleFromCoordinates(TriangleCoordinates tc)
{
	int type = 0;
	int v1x = -1;
	int v1y = -1;
	int v2x = -1;
	int v2y = -1;
	int v3x = -1;
	int v3y = -1;
	char row = 'A';
	int topColumn = 2;
	int bottomColumn = 1;

	if (!triangleExists)
	{
		cout << "You must create a triangle coordinates map first!" << endl;
		return;
	}

	cout << "Please enter vertex coordinates assuming the top leftmost pixel is (0,0) and increases to the right and downwards" << endl;
	cout << "All numbers should be in increments of 10, and end with either a 1 or 0." << endl;
	cout << "For example, the vertex coordinates are correct: (0, 10) (10, 0), (10,10)" << endl;

	while (v1x < 0 || v1x > 100)
	{
		cout << "Please enter a valid v1x." << endl;
		cin >> v1x;
	}

	while (v1y < 0 || v1y > 100)
	{
		cout << "Please enter a valid v1y." << endl;
		cin >> v1y;
	}

	while (v2x < 0 || v2x > 100)
	{
		cout << "Please enter a valid v2x." << endl;
		cin >> v2x;
	}

	while (v2y < 0 || v2y > 100)
	{
		cout << "Please enter a valid v2y." << endl;
		cin >> v2y;
	}

	while (v3x < 0 || v3x > 100)
	{
		cout << "Please enter a valid v3x." << endl;
		cin >> v3x;
	}

	while (v3y < 0 || v3y > 100)
	{
		cout << "Please enter a valid v3y." << endl;
		cin >> v3y;
	}

	if (v1x == v2x && v1y == v3y)
		type = 1;
	else if (v1y == v2y && v1x == v3x)
		type = 2;

	if (type == 1)
	{
		if ((v3x <= tc.GetWidth() && v3y <= tc.GetHeight()) && ((v2y == (v1y-10) && (v3x == v2x+10))))
		{
			v3x /= 10;
			v3y /= 10;

			row += (v3y - 1);
			bottomColumn += ((v3x - 1) * 2);

			cout << "You have entered triangle " << row << bottomColumn << '.' << endl;
		}
		else
			cout << "You entered coordinates that do not exist." << endl;
	}

	else if (type == 2)
	{
		if ((v3x <= tc.GetWidth() && v3y <= tc.GetHeight()) && (v2x < v1x && v3y > v2y))
		{
			v3x /= 10;
			v3y /= 10;

			row += (v3y - 1);
			topColumn += ((v3x - 1) * 2);

			cout << "You have entered triangle " << row << topColumn << '.' << endl;
		}
	else
		cout << "You entered coordinates that do not exist." << endl;
	}

	else
		cout << "You entered coordinates that do not exist." << endl;

}

//prints the map!
void PrintMap(TriangleCoordinates tc)
{
	if (!triangleExists)
	{
		cout << "You must create a triangle coordinates map first!" << endl;
		return;
	}

	tc.Print();
}