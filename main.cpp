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

void randomize(float data[ROWS][COLS], int row1, int col1, int row2, int col2, int value1, int value2) {

    while (row1 != row2) {

        int randomNumber = (rand() % value2) + value1;
        store(data, row1, col1, randomNumber);
        row1++;

    }

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
    int row=0, col=0, row2=0, col2 = 0;
    float valueFL=0;
    int valueInt1=0, valueInt2=0;

    for (int i = 0; i < 10; i++) {

        if (userCommandInput == validCommands[i]) {

            commandIndex = i;

            switch (commandIndex) {

                case 0:
                    valueFL = 0.0;
                    cin >> valueFL;
                    read_index(row, col);
                    store(data, row, col, valueFL);

                    break;
                case 1:
                    //RANDOMIZE command
                    //randomize();
                    valueInt1 = 0;
                    valueInt2 = 0;
                    cin >> valueInt1 >> valueInt2;
                    read_index(row, col);
                    read_index(row2, col2);
                    randomize(data, row, col, row2, col2, valueInt1, valueInt2);

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
    string validCommands[10] = {"STORE", "RANDOM", "MIN", "MAX", "SUM", "AVE", "VAR", "STD", "PRINT", "QUIT"};
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

