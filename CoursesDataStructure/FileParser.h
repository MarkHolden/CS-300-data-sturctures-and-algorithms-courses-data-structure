#pragma once

#include <string>

class FileParser {
public:
    /// <summary>
    /// Reads the file into a HashTable.
    /// </summary>
    /// <param name="courses">HashTable into which to read the file.</param>
    /// <returns>The HashTable representing the data in the file.</returns>
    static void ReadFile(HashTable* courses);

    /// <summary>
    /// Parses a Course from a line in a courses file.
    /// </summary>
    /// <param name="line">Line to parse.</param>
    /// <returns>Parsed course.</returns>
    static Course* ParseCourse(std::string line);
};