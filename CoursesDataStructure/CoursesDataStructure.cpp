//============================================================================
// Name        : CoursesDataStructure.cpp
// Author      : Mark Holden
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Project Two 
//============================================================================

#include "HashTable.h"
#include "FileParser.h"

using namespace std;



/// <summary>
/// Main entry point for the application.
/// </summary>
/// <returns>Exit code.</returns>
int main() {
    auto hashTable = new HashTable;
    FileParser::ReadFile(hashTable);
    hashTable->PrintCourses();

	return 0;
}

