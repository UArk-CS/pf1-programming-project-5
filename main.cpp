//---------------------------------------------------
// Purpose: Implement simple spreadsheet program.
// Author:  John Gauch and TBA
//---------------------------------------------------

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 26;
const int COLS = 26;

//---------------------------------------------------
// Read read index of the form A4 and calculate
// the corresponding row=3 col=0 values.
//---------------------------------------------------
void read_index(int &row, int &col)
{
    char letter = ' ';
    int number = 0;
    cin >> letter >> number;

    if (letter >= 'A' && letter <= 'Z')
        col = letter - 'A';
    else
        cout << "Error: invalid column\n";

    if (number >= 1 && number <= 26)
        row = number - 1;
    else
        cout << "Error: invalid row\n";
}

//---------------------------------------------------
// Print range of values in spreadsheet array
//---------------------------------------------------
void print(float data[ROWS][COLS], int r1, int c1, int r2, int c2)
{
    for (int row = r1; row <= r2; row++)
    {
        for (int col = c1; col <= c2; col++)
            cout << data[row][col] << "\t";
        cout << endl;
    }
}
//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
    // Initialize spreadsheet
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;

    // Test print function
    data[1][3] = 42;
    print(data, 0, 0, 5, 5);

    // ADD CODE TO HANDLE COMMANDS HERE

    return 0;
}

