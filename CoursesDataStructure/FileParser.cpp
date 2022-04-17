#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"
#include "FileParser.h"

using namespace std;

void FileParser::ReadFile(HashTable* courses) {
	string line;
	ifstream coursesFile;
	vector<string> prereqsToValidate;
	coursesFile.open("..\\courses.txt");
	if (coursesFile.is_open()) {
		while (getline(coursesFile, line)) {
			try {
				Course* course = FileParser::ParseCourse(line);
				courses->Insert(course);
				for (string prereq : course->Prerequisites) {
					if (!courses->Exists(prereq) && find(prereqsToValidate.begin(), prereqsToValidate.end(), prereq) != prereqsToValidate.end()) {
						prereqsToValidate.push_back(prereq);
					}
				}
			}
			catch (const exception& ex) {
				cout << "An error occurred while parsing the file:\n" << ex.what() << endl;
			}
		}
		coursesFile.close();
	}

	for (string prereq : prereqsToValidate) {
		if (!courses->Exists(prereq)) {
			cout << "The prerequisite course " << prereq << " is missing from the course list.\n";
		}
	}
}

Course* FileParser::ParseCourse(string line) {
	auto course = new Course;
	char delimiter(',');
	course->CourseId = line.substr(0, line.find(delimiter));
	if (course->CourseId == "") {
		throw invalid_argument("Less than two parameters were recieved.");
	}
	line.erase(0, course->CourseId.length() + 1);

	course->Name = line.substr(0, line.find(delimiter));
	if (course->Name == "") {
		throw invalid_argument("Less than two parameters were recieved.");
	}
	line.erase(0, course->Name.length() + 1);

	while (line.length() > 0) {
		string prereq = line.substr(0, line.find(delimiter));
		if (prereq.length() > 0) {
			course->Prerequisites.push_back(prereq);
		}
		line.erase(0, prereq.length() + 1);
	}

	return course;
}
