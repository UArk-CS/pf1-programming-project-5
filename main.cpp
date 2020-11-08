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

    while (row1 != row2+1) {

        int randomNumber = (rand() % value2) + value1;
        store(data, row1, col1, randomNumber);
        row1++;

    }

}

void minValue(float data[ROWS][COLS], int row, int col, int row2, int col2, int row3, int col3) {

    float minValue = data[row][col];
    int numberOfRows = row2 - row + 1;

    for (int i = 0; i < numberOfRows; i++) {

        float valueToCompare = data[row + i][col];

        minValue = min(minValue, valueToCompare);

    }

    store(data, row3, col3, minValue);

}

void maxValue(float data[ROWS][COLS], int row, int col, int row2, int col2, int row3, int col3) {

    float maxValue = data[row][col];
    int numberOfRows = row2 - row + 1;

    for (int i = 0; i < numberOfRows; i++) {

        float valueToCompare = data[row + i][col];

        maxValue = max(maxValue, valueToCompare);

    }

    store(data, row3, col3, maxValue);

}

void sum(float data[ROWS][COLS], int row, int col, int row2, int col2, int row3, int col3) {

    int numberOfRows = row2 - row + 1;
    float sum;

    for (int i = 0; i < numberOfRows; i++) {

        sum += data[row + i][col];

    }

    store(data, row3, col3, sum);

}

float average(float data[ROWS][COLS], int row, int col, int row2, int col2) {

    float numberOfRows = row2 - row + 1;
    float sum;

    for (int i = 0; i < numberOfRows; i++) {

        sum += data[row + i][col];

    }

    return sum/numberOfRows;

}

float variance(float data[ROWS][COLS], int row, int col, int row2, int col2) {

    float numberOfRows = row2 - row + 1;
    float var = 0.0;
    float avg = 0.0;

    avg = average(data, row, col, row2, col2);

    for (int i = 0; i < numberOfRows; i++) {

        var += pow(data[row + i][col] - avg, 2);

    }


    return var / numberOfRows;

}

float standardDeviation(float data[ROWS][COLS], int row, int col, int row2, int col2) {

    float std = 0.0;
    float avg = 0.0;

    std = sqrt(variance(data, row, col, row2, col2));



    return std;

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
    int row=0, col=0, row2=0, col2 = 0, row3 = 0, col3 = 0;
    float valueFL=0;
    int valueInt1=0, valueInt2=0;

    for (int i = 0; i < 11; i++) {

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
                    valueInt1 = 0;
                    valueInt2 = 0;
                    cin >> valueInt1 >> valueInt2;
                    read_index(row, col);
                    read_index(row2, col2);
                    randomize(data, row, col, row2, col2, valueInt1, valueInt2);

                    break;
                case 2:
                    //MIN command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);
                    minValue(data, row, col, row2, col2, row3, col3);

                    break;
                case 3:
                    //MAX command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);
                    maxValue(data, row, col, row2, col2, row3, col3);

                    break;
                case 4:
                    //SUM command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);
                    sum(data, row, col, row2, col2, row3, col3);

                    break;
                case 5:
                    //AVE command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);
                    store(data, row3, col3, average(data, row, col, row2, col2));

                    break;
                case 6:
                    //VAR command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);

                    store(data, row3, col3, variance(data, row, col, row2, col2));

                    break;
                case 7:
                    //STD command
                    read_index(row, col);
                    read_index(row2, col2);
                    read_index(row3, col3);
                    store(data, row3, col3, standardDeviation(data, row, col, row2, col2));


                    break;
                case 8:
                    //PRINT command
                    read_index(row, col);
                    read_index(row2, col2);
                    print(data, row, col, row2, col2);

                    break;
                case 9:
                    //QUIT command
                    keepGoing = false;

                    break;
                case 10:
                    //PRINTALL command
                    print(data, 0, 0, 5, 5);

                    break;
                default:
                    break;

            }

        }

    }

}

int main() {

    bool keepGoing = true;
    string validCommands[11] = {"STORE", "RANDOM", "MIN", "MAX", "SUM", "AVE", "VAR", "STD", "PRINT", "QUIT", "PRINTALL"};

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

