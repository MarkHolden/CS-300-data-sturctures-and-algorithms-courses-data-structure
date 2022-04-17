//============================================================================
// Name        : CoursesDataStructure.cpp
// Author      : Mark Holden
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Project Two 
//============================================================================

#include "HashTable.h"
#include "FileParser.h"
#include <iostream>
#include "Input.h"

using namespace std;

/// <summary>
/// Display the main menu.
/// </summary>
/// <param name="isFinalRound"></param>
void DisplayMenu() {
    cout << "Game Menu:" << endl;
    cout << "  1. Load Data Structure" << endl;
    cout << "  2. Print Course List" << endl;
    cout << "  3. Print Course" << endl;
    cout << "  0. Exit" << endl;
}

void PrintCourseInfo(HashTable* const hashTable) {
    string courseId = Input::ReadString("For which courseId would you like to display info? ");
    hashTable->PrintCourseInfo(courseId);
}

/// <summary>
/// Main entry point for the application.
/// </summary>
/// <returns>Exit code.</returns>
int main() {
    auto hashTable = new HashTable;
    int choice = -1;
    while (choice != 0) {
        DisplayMenu();
        choice = Input::ReadInt("Enter Choice: ", 0, 3);

        switch (choice) {
        case 1:
            FileParser::ReadFile(hashTable);
            break;

        case 2:
            hashTable->PrintCourses();
            break;

        case 3:
            PrintCourseInfo(hashTable);
            break;

        default:
            break;
        }
    }

    return 0;
}

