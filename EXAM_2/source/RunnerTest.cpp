// I affirm that all code given below was written solely by me, Tommy Clauson, and that any help I received adhered to the rules stated for this exam.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Runner.h"
using namespace std;

int main()
{
    // opening the file filled with registered runners
    fstream input;
    string fileName = "registrants.txt";
    input.open(fileName.c_str(), ios::in);
    // checking if files exists
    if (input.fail()) 
    {
        cout << "Sorry that file doesnt exist.";
        return -1;
    }
    // declaring vars
    // Runners names
    string firstName, lastName;
    // declaring the pace, index and number of runners to be int
    int pace, index, numberOfRunners = 0;
    // declaring vector
    vector<Runner> registrants;

    // check if end of input file is reached
    while (!input.eof()) 
    {
        index = 0;
        input >> firstName >> lastName >> pace;
        for (int i = 0; i < registrants.size(); i++) 
        {
            if (pace > registrants[i].Get_Pace()) 
            {
                index = i + 1;
            }
        }
        registrants.insert(registrants.begin() + index, Runner(firstName, lastName, pace));
        numberOfRunners++;
    }
    // closing the input file
    input.close();
    // check header file for explination
    string groupNames[8] = { "White", "Yellow", "Green", "Orange", "Blue", "lilac", "red", "N/a" };
    fstream inputs[8];
    for (int i = 0; i < 8; i++) 
    {
        inputs[i].open((groupNames[i] + ".txt").c_str(), ios::out);
        if (inputs[i].fail()) 
        {
            cout << "Could not open file: " << groupNames[i] << endl;
            return -1;
        }
    }

    int numberOfRunnersPerColor[8];
    int fileIndex;
    for (int i = 0; i < registrants.size(); i++) 
    {
        pace = registrants[i].Get_Pace();
        if (pace <= 360) 
        {
            fileIndex = 0;
        }
        else if (pace >= 721)
        {
            fileIndex = 6;
        }
        else 
        {
            switch ((pace - 301) / 60) 
            {
                case 1:fileIndex = 1; break;
                case 2:fileIndex = 2; break;
                case 3:fileIndex = 3; break;
                case 4:fileIndex = 4; break;
                case 5:fileIndex = 5; break;
                case 6:fileIndex = 5; break;
                    default: fileIndex = 7;
            }
        }
    }

        input[fileIndex] << registrants[i].Get_FirstName() << " " << registrants[i].Get_Lastname() << " " << registrants[i].Get_Pace() << endl;
        numberOfRunnersPerColor[fileIndex]++;
    }

    for (int i = 0; i < 8; i++) 
    {
        inputs[i].close();
    }

    string sumFile = "summary.txt";
    input.open(sumFile.c_str(), ios::out);
    
    if (input.fail()) 
    {
        cout << "Could not open file.";
        return -1;
    }

    int startTimes[7];
    startTimes[0] = 32400;
    
    for (int i = 1; i < 7; i++) 
    {
        startTimes[i] = startTimes[i - 1] + numberOfRunnersPerColor[i - 1] + 60;
    }

    input << "The total number of runners is " << numberOfRunners << endl;
    
    for (int i = 0; i < 8; i++) 
    {
        input << "The total number of runners in " << groupNames[i] << " is " << numberOfRunnersPerColor[i] << ". ";
        if (i < 7) {
            input << "They should start the race at " << SecondsToHours(startTimes[i]) << ":";
            input << SecondsToMinutes(startTimes[i]) << ":" << SecondsToSeconds(startTimes[i]) << "." << endl;
        }
    }
}
