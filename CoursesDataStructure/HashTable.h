#pragma once

#include <string>
#include "Bucket.h"

class HashTable {
public:
	/// <summary>
	/// Array of Buckets with a size sufficient to hold all courses without collision(see GetHashCode()).
	/// </summary>
	Bucket Buckets[32];

	/// <summary>
	/// Determine if a CourseId already exists in the hash table.
	/// </summary>
	/// <param name="courseId">Id of the course for which to search.</param>
	/// <returns></returns>
	bool Exists(std::string const& courseId) const;
	
	/// Insert a course into the hash table.
	/// </summary>
	/// <param name="course">A pointer to the course to insert.</param>
	void Insert(Course * const& course);

	/// <summary>
	/// Get a course by courseId.
	/// </summary>
	/// <param name="courseId">Id of the course to get.</param>
	/// <returns>A pointer to the course if it exists or nullptr.</returns>
	Course * Get(std::string const& courseId) const;

	/// <summary>
	/// Iterates over all courses and prints course details and prerequisites.
	/// </summary>
	void PrintCourses() const;

private:
	void PrintCourseInfo(std::string const& courseId, std::string const& indent = "") const;
};