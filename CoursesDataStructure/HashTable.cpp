//============================================================================
// Name        : HashTable.cpp
// Author      : Mark Holden
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : HashTable class for storing Courses
//============================================================================

#pragma once

#include "HashTable.h"
#include <string>
#include <iostream>

using namespace std;

bool HashTable::Exists(string const& courseId) const {
    int hashCode = Course::GetHashCode(courseId);
    return !Buckets[hashCode].IsEmpty();
}

void HashTable::Insert(Course * const& course) {
    int hashCode = course->GetHashCode();
    Buckets[hashCode].Course = course;
}

Course* HashTable::Get(string const& courseId) const {
    int hashCode = Course::GetHashCode(courseId);
    return Buckets[hashCode].Course;
}

void HashTable::PrintCourses() const {
    for (int i = 0; i < 32; ++i) {
        if (!Buckets[i].IsEmpty()) {
            PrintCourseInfo(Buckets[i].Course->CourseId);
        }
    }
}

void HashTable::PrintCourseInfo(string const& courseId, string const& indent) const {
    const Course* course = Get(courseId);
    if (course == nullptr) {
        cout << "Course with Id: " << courseId << " not found.\n";
        return;
    }

    cout << indent << "CourseId: " << courseId << " | " << "Course Name: " << course->Name << endl;
    if (!course->Prerequisites.empty()) {
        cout << indent << "Course Prerequisites:\n";
        for (string prereq : course->Prerequisites) {
            PrintCourseInfo(prereq, indent + "\t");
        }
    }
}
