//============================================================================
// Name        : Course.h
// Author      : Mark Holden
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Header file defining the Course class 
//============================================================================

#pragma once

#include <vector>
#include <string>

class Course {
public:
    /// <summary>
    /// Gets the HashCode for this Course.
    /// </summary>
    /// <returns>The hashcode.</returns>
    int GetHashCode() const;

    /// <summary>
    /// Get a HashCode by courseId.
    /// </summary>
    /// <param name="courseId">CourseId to hash.</param>
    /// <returns>The hashcode.</returns>
    static int GetHashCode(std::string const& courseId);

    /// <summary>
    /// The name of the Course.
    /// </summary>
    std::string Name;

    /// <summary>
    /// A list of Prerequisites for this Course.
    /// </summary>
    std::vector<std::string> Prerequisites;

    /// <summary>
    /// Id of the course.
    /// </summary>
    std::string CourseId;
};