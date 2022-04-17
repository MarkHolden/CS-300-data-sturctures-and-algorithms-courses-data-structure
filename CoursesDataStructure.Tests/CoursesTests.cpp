#pragma once

#include "pch.h"
#include "CppUnitTest.h"
#include "../CoursesDataStructure/Course.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoursesTests
{
	TEST_CLASS(GetHashCode)
	{
	public:

		TEST_METHOD(GetHashCode_ShouldReturn31_WhenCourseIdIsMATH451)
		{
			Course course;
			course.CourseId = "MATH451";
			int code = course.GetHashCode();
			Assert::AreEqual(31, code);
		}

		TEST_METHOD(GetHashCode_ShouldReturn0_WhenCourseIdIsCSCI100)
		{
			Course course;
			course.CourseId = "CSCI100";
			int code = course.GetHashCode();
			Assert::AreEqual(0, code);
		}
	};
}
