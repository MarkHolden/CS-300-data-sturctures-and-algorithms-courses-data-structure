#include "Course.h"

using namespace std;

int Course::GetHashCode(string const& courseId) {

    int hashCode = 0;
    string departmentCode = courseId.substr(0, 4);
    if (departmentCode == "MATH") {
        hashCode += 16; // fifth bit is a 1.
    }
    // departmentCode "CSCI" the fifth bit is a 0.

    string courseNumberString = courseId.substr(4, 3);
    int courseNumber = stoi(courseNumberString);
    
    if ((courseNumber - courseNumber % 100) == 400) {
        hashCode += 12; // bits 3 & 4 are 11.
    }
    else if ((courseNumber - courseNumber % 100) == 300) {
        hashCode += 8; // bits 3 & 4 are 10.
    }
    else if ((courseNumber - courseNumber % 100) == 200) {
        hashCode += 4; // bits 3 & 4 are 01.
    }
    // 100 level courses bits 3 & 4 are 00.

    if ((courseNumber % 100 - courseNumber % 10) == 50) {
        hashCode += 2; // bit 2 is 1.
    }
    // non-X5X courses bit 2 is 0.

    if ((courseNumber % 10) == 1) {
        hashCode += 1; // bit 1 is 1.
    }
    // non-XX1 courses bit 1 is 0.

    return hashCode;
}

int Course::GetHashCode() const {
    return GetHashCode(CourseId);
}


