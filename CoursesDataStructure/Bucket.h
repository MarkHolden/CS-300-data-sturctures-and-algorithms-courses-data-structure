//============================================================================
// Name        : Bucket.h
// Author      : Mark Holden
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Header file defining the Bucket struct.
//============================================================================

#include "Course.h"

struct Bucket {
    /// <summary>
    /// Pointer to the Course object.
    /// </summary>
    Course * Course = nullptr;

    /// <summary>
    /// Whether the Bucket is empty or not.
    /// </summary>
    /// <returns>Boolean value representing whether the Bucket is empty or not.</returns>
    bool IsEmpty() const { return Course == nullptr; };
};