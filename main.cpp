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

void getUserInput(string &userInput) {

    cout << "Enter command" << endl;
    cout << ">> ";
    getline(cin, userInput);

    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

}

void parseUserInput(string &userInput, string commandParameters[]) {

    char* charArray;
    charArray = &userInput[0];

    char* parameters = strtok(charArray, " ");

    int i = 0;
    while (parameters != NULL) {

        commandParameters[i] = parameters;

        parameters = strtok(NULL, " ");

        i++;

    }

}

void validateUserCommand(string commandParameters[], string validCommands[], string &userInput) {

    bool isValidCommand = false;
    int commandIndex = 0;

    for (int i = 0; i < 10; i++) {

        //Debugging purposes
        cout << i << ": " << validCommands[i] << endl;

        if (commandParameters[0] == validCommands[i]) {

            commandIndex = i;

            //Debugging purposes
            cout << "Valid Command " << commandIndex << endl;

            switch (commandIndex) {

                case 0:
                    //STORE command
                    //store();

                    isValidCommand = true;

                    break;
                case 1:
                    //RANDOMIZE command
                    //randomize();

                    isValidCommand = true;

                    break;
                case 2:
                    //MIN command
                    //min();

                    isValidCommand = true;

                    break;
                case 3:
                    //MAX command
                    //max();

                    isValidCommand = true;

                    break;
                case 4:
                    //SUM command
                    //sum();

                    isValidCommand = true;

                    break;
                case 5:
                    //AVE command
                    //average();

                    isValidCommand = true;

                    break;
                case 6:
                    //VAR command
                    //variance();

                    isValidCommand = true;

                    break;
                case 7:
                    //STD command
                    //standardDeviation();

                    isValidCommand = true;

                    break;
                case 8:
                    //PRINT command
                    //print();

                    isValidCommand = true;

                    break;
                case 9:
                    //QUIT command
                    //quit();

                    isValidCommand = true;

                    break;
                default:
                    break;

            }

        }

        if (!isValidCommand) {

            getUserInput(userInput);
            i = 0;

        }

    }

}

int main() {
    string validCommands[10] = {"STORE", "RANDOMIZE", "MIN", "MAX", "SUM", "AVE", "VAR", "STD", "PRINT", "QUIT"};
    string userInput;
    string commandParameters[] = {};

    // Initialize spreadsheet
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;

    // Test print function
    data[1][3] = 42;
    print(data, 0, 0, 5, 5);

    // ADD CODE TO HANDLE COMMANDS HERE
    getUserInput(userInput);
    parseUserInput(userInput, commandParameters);

    for (int i = 0; i < commandParameters->size() - 1; i++) {
        cout << commandParameters[i] << endl;
    }

    validateUserCommand(commandParameters, validCommands, userInput);

    return 0;
}

