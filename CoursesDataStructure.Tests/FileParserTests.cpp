#pragma once

#include <algorithm>
#include "pch.h"
#include "CppUnitTest.h"
#include "../CoursesDataStructure/FileParser.cpp"
#include "../CoursesDataStructure/HashTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileParserTests
{
    TEST_CLASS(ParseCourse)
    {
    public:

        TEST_METHOD(ParseCourse_ShouldCourse_WhenLineIsValid)
        {
            std::string courseId = "CSCI300";
            std::string name = "Introduction to Algorithms";
            std::string prereq1 = "CSCI200";
            std::string prereq2 = "MATH201";
            Course course = FileParser::ParseCourse(courseId + "," + name + "," + prereq1 + "," + prereq2);
            Assert::AreEqual(courseId, course.CourseId);
            Assert::AreEqual(name, course.Name);
            Assert::IsTrue(std::any_of(course.Prerequisites.begin(), course.Prerequisites.end(), [&prereq1](std::string const& p) { return p == prereq1; }));
            Assert::IsTrue(std::any_of(course.Prerequisites.begin(), course.Prerequisites.end(), [&prereq2](std::string const& p) { return p == prereq2; }));
            Assert::AreEqual(2, (int)course.Prerequisites.size());
        }

        TEST_METHOD(ParseCourse_ShouldThrow_WhenLineHasZeroArguments)
        {
            Assert::ExpectException<std::invalid_argument>([] { FileParser::ParseCourse(""); });
        }

        TEST_METHOD(ParseCourse_ShouldThrow_WhenLineHasOneArgument)
        {
            Assert::ExpectException<std::invalid_argument>([] { FileParser::ParseCourse("CSCI300,"); });
        }
    };
}
