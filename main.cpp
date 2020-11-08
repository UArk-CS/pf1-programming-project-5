#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 26;
const int COLS = 26;

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

void store(float data[ROWS][COLS], int row, int col, float value) {

    data[row][col] = value;

}

void print(float data[ROWS][COLS], int r1, int c1, int r2, int c2)
{
    for (int row = r1; row <= r2; row++)
    {
        for (int col = c1; col <= c2; col++)
            cout << data[row][col] << "\t";
        cout << endl;
    }
}

void getUserInput(string &userCommandInput) {

    cout << "Enter command >> ";
    cin >> userCommandInput;

    transform(userCommandInput.begin(), userCommandInput.end(), userCommandInput.begin(), ::toupper);

}

void validateUserCommand(string &userCommandInput, string validCommands[], float data[ROWS][COLS], bool &keepGoing) {

    bool isValidCommand = false;
    int commandIndex = 0;
    int row, col = 0;
    float value = 0;

    for (int i = 0; i < 10; i++) {

        if (userCommandInput == validCommands[i]) {

            commandIndex = i;

            switch (commandIndex) {

                case 0:
                    cin >> value;
                    read_index(row, col);
                    store(data, row, col, value);

                    break;
                case 1:
                    //RANDOMIZE command
                    //randomize();

                    break;
                case 2:
                    //MIN command
                    //min();

                    break;
                case 3:
                    //MAX command
                    //max();

                    break;
                case 4:
                    //SUM command
                    //sum();

                    break;
                case 5:
                    //AVE command
                    //average();

                    break;
                case 6:
                    //VAR command
                    //variance();

                    break;
                case 7:
                    //STD command
                    //standardDeviation();

                    break;
                case 8:
                    //PRINT command
                    //print();

                    break;
                case 9:
                    //QUIT command
                    keepGoing = false;

                    break;
                default:
                    break;

            }

        }

    }

}

int main() {

    bool keepGoing = true;
    string validCommands[10] = {"STORE", "RANDOMIZE", "MIN", "MAX", "SUM", "AVE", "VAR", "STD", "PRINT", "QUIT"};
    string usersCommandInput;

    // Initialize spreadsheet
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;

    // Test print function
    data[1][3] = 42;
    print(data, 0, 0, 5, 5);

    while (keepGoing) {

        getUserInput(usersCommandInput);
        validateUserCommand(usersCommandInput, validCommands, data, keepGoing);

    }

    print(data, 0, 0, 5, 5);

    return 0;
}

