class TriangleCoordinates
{
public:
	TriangleCoordinates();						// Set height = 60, width = 60.
	TriangleCoordinates(int h, int w);	// constructor with parameters

	void Print() const;		// Display a fraction on screen
	int GetHeight() const;  //accessor
	int GetWidth() const;	//accessor

	bool SetValue(int n, int d); //set values after construction

private:
	int height;		// height of the rectangle
	int width;		// width of the rectangle
	char symbol;    // text of the rectangle
};